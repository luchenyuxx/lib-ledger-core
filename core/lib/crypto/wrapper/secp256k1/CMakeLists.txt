project(secp256k1_wrapper)

#Create a wrapper library
add_library(secp256k1_wrapper STATIC secp256k1_wrapper.h secp256k1_wrapper.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_dependencies(secp256k1_wrapper secp256k1)

#Link to Rust library
target_link_libraries(secp256k1_wrapper "${CMAKE_CURRENT_SOURCE_DIR}/../../src/rust-secp256k1/target/debug/libsecp256k1.a")
target_include_directories(secp256k1_wrapper PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../../src/rust-secp256k1/depend/secp256k1")

#Executable test
add_executable(Example secp256k1_rust_test.cpp)
add_dependencies(Example secp256k1_wrapper)
target_link_libraries(Example secp256k1_wrapper)