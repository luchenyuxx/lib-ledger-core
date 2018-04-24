use std::{ slice, mem, str };
use std::ffi::{ CStr };
use std::iter::repeat;

extern crate libc;
use libc::{ size_t, c_char };

extern crate crypto;
use crypto::{ symmetriccipher, buffer, blockmodes, sha1, sha2, aes, pbkdf2, hmac, ripemd160 };
use crypto::buffer::{ ReadBuffer, WriteBuffer, BufferResult };
use crypto::digest::Digest;
use crypto::mac::{Mac, MacResult};


extern crate rand;
use rand::Rng;

#[no_mangle]
pub extern fn make_u8_vec() -> *mut Vec<u8> {
    Box::into_raw(Box::new(Vec::new()))
}


/////////AES////////
#[repr(C)]
pub struct Vector {
    data: *const u8,
    len: usize,
}

impl Vector {

    unsafe fn as_u8_slice(&self) -> &[u8] {
        //assert!(!self.data.is_null());
        slice::from_raw_parts(self.data as *const u8, self.len as usize)
    }

    fn from_vec<T>(mut vec: Vec<T>) -> Vector {
        vec.shrink_to_fit();
        let array = Vector { data: vec.as_ptr() as *const u8, len: vec.len() as size_t };
        mem::forget(vec);
        array
    }
}

#[no_mangle]
pub extern fn encrypt_rust(iv: &Vector, key: &Vector, data: &Vector) -> Vector {
    unsafe {
        match encrypt_rust_impl(iv.as_u8_slice(), key.as_u8_slice(), data.as_u8_slice()) {
                Ok(encrypted_data) => Vector::from_vec(encrypted_data),
                Err(_) => panic!("Error at encryption !")
        }
    }
}

pub fn encrypt_rust_impl(iv: &[u8], key: &[u8], data: &[u8]) -> Result<Vec<u8>, symmetriccipher::SymmetricCipherError> {

    // Create an encryptor instance of the best performing
    // type available for the platform.
    let mut encryptor = aes::cbc_encryptor(
            aes::KeySize::KeySize256,
            key,
            iv,
            blockmodes::PkcsPadding);

    // keep track of how much data has been
    // read from or written to them.
    let mut final_result = Vec::<u8>::new();
    let mut read_buffer = buffer::RefReadBuffer::new(data);
    let mut buffer = [0; 4096];
    let mut write_buffer = buffer::RefWriteBuffer::new(&mut buffer);

    loop {
        let result = try!(encryptor.encrypt(&mut read_buffer, &mut write_buffer, true));
        final_result.extend(write_buffer.take_read_buffer().take_remaining().iter().map(|&i| i));

        match result {
            BufferResult::BufferUnderflow => break,
            BufferResult::BufferOverflow => { }
        }
    }

    Ok(final_result)
}

// Decrypts a buffer with the given key and iv using
// AES-256/CBC/Pkcs encryption.
#[no_mangle]
pub extern fn decrypt_rust(iv: &Vector, key: &Vector, data: &Vector) -> Vector {
    unsafe {
        match decrypt_rust_impl(iv.as_u8_slice(), key.as_u8_slice(), data.as_u8_slice()) {
                Ok(decrypted_data) => Vector::from_vec(decrypted_data),
                Err(_) => panic!("Error at decryption !")
        }
    }
}

pub fn decrypt_rust_impl(iv: &[u8], key: &[u8], encrypted_data: &[u8]) -> Result<Vec<u8>, symmetriccipher::SymmetricCipherError> {

    let mut decryptor = aes::cbc_decryptor(
            aes::KeySize::KeySize256,
            key,
            iv,
            blockmodes::PkcsPadding);

    let mut final_result = Vec::<u8>::new();
    let mut read_buffer = buffer::RefReadBuffer::new(encrypted_data);
    let mut buffer = [0; 4096];
    let mut write_buffer = buffer::RefWriteBuffer::new(&mut buffer);

    loop {
        let result = try!(decryptor.decrypt(&mut read_buffer, &mut write_buffer, true));
        final_result.extend(write_buffer.take_read_buffer().take_remaining().iter().map(|&i| i));
        match result {
            BufferResult::BufferUnderflow => break,
            BufferResult::BufferOverflow => { }
        }
    }

    Ok(final_result)
}

/////////SHA256////////
#[no_mangle]
pub extern fn string_to_bytes_hash(input: *const c_char) -> Vector {
    let c_str = unsafe {
        assert!(!input.is_null());
        CStr::from_ptr(input)
    };
    let mut hasher = sha2::Sha256::new();
    hasher.input(c_str.to_bytes());
    let mut hash: Vec<u8> = repeat(0).take(hasher.output_bits()/8).collect();
    hasher.result(& mut hash);
    hasher.reset();
    Vector::from_vec(hash)
}
#[no_mangle]
pub extern fn bytes_to_bytes_hash(input: &Vector) -> Vector {
    let mut hasher = sha2::Sha256::new();
    unsafe {
        hasher.input(input.as_u8_slice());
    }
    let mut hash: Vec<u8> = repeat(0).take(hasher.output_bits()/8).collect();
    hasher.result(& mut hash);
    hasher.reset();
    Vector::from_vec(hash)
}
/*
#[no_mangle]
pub extern fn string_to_hex_hash(input: *const c_char) -> *const c_char {

    let hex = string_to_hex_hash_helper(input);

    //Send result back to C++
    let result = CString::new(hex).unwrap();
    let p_result = result.as_ptr();
    std::mem::forget(result);
    p_result

}
*/
////////RIPEMD160/////////////
#[no_mangle]
pub extern fn ripemd160_hash(input: &Vector) -> Vector {
    let mut hasher = ripemd160::Ripemd160::new();
    unsafe {
        hasher.input(input.as_u8_slice());
    }
    let mut hash: Vec<u8> = repeat(0).take(hasher.output_bits()/8).collect();
    hasher.result(& mut hash);
    hasher.reset();
    Vector::from_vec(hash)
}

//////PBKDF2///////////
#[no_mangle]
pub extern fn pbkdf2_derive(key: &Vector, salt: &Vector, iter: u32, outLength: size_t) -> Vector {
    unsafe {
        let mut mac = hmac::Hmac::new(sha1::Sha1::new(), key.as_u8_slice());
        let mut result: Vec<u8> = repeat(0).take(outLength as usize).collect();
        pbkdf2::pbkdf2(&mut mac, salt.as_u8_slice(), iter, &mut result);
        Vector::from_vec(result)
    }
}

//////HMAC//////
fn hmac_hash<D: Digest>(mut digest: D, key: &Vector, data: &Vector) -> Vector {
    unsafe{
        let mut mac = hmac::Hmac::new(digest, key.as_u8_slice());
        mac.input(data.as_u8_slice());
        let mac_result = mac.result();
        mac.reset();
        Vector::from_vec(mac_result.code().to_vec())
    }
}

#[no_mangle]
pub extern fn hmac_sha256(key: &Vector, data: &Vector) -> Vector {
    hmac_hash(sha2::Sha256::new(), key, data)
}

#[no_mangle]
pub extern fn hmac_sha512(key: &Vector, data: &Vector) -> Vector {
    hmac_hash(sha2::Sha512::new(), key, data)
}

//////RNG//////
fn get_random_data<T : rand::Rand>() -> T {
    let mut rng = rand::thread_rng();
    rng.gen::<T>()
}
#[no_mangle]
pub extern fn get_random_int() -> i32 {
    get_random_data::<i32>()
}
#[no_mangle]
pub extern fn get_random_long() -> i64 {
    get_random_data::<i64>()
}
#[no_mangle]
pub extern fn get_random_byte() -> u8 {
    get_random_data::<u8>()
}
#[no_mangle]
pub extern fn get_random_bytes(size: i32) -> Vector {
    let mut random : Vec<u8> = Vec::new();
    for i in 0 .. size {
        random.push(get_random_byte())
    }
    Vector::from_vec(random)
}