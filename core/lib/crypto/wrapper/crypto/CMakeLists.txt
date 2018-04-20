project(crypto_wrapper)

#Create a wrapper library
add_library(crypto_wrapper STATIC crypto_wrapper.h crypto_wrapper.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_dependencies(crypto_wrapper crypto)

#Link to Rust library
target_link_libraries(crypto_wrapper "${CMAKE_CURRENT_SOURCE_DIR}/../../src/rust-crypto/target/debug/libcrypto.a")
target_include_directories(crypto_wrapper PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../../src/rust-crypto/depend/crypto")

#Executable test
add_executable(crypto_example crypto_rust_test.cpp)
add_dependencies(crypto_example crypto_wrapper)
target_link_libraries(crypto_example crypto_wrapper)