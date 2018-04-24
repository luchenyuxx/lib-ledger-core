# Enable ExternalProject CMake module
include(ExternalProject)

# Set default ExternalProject root directory
set(prefix "${CMAKE_CURRENT_SOURCE_DIR}")

# Add rust_example as a CMake target
ExternalProject_Add(
        secp256k1
        PREFIX "${prefix}"
        DOWNLOAD_COMMAND ""
        CONFIGURE_COMMAND ""
        BUILD_COMMAND cargo build COMMAND cargo build --release
        BINARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}"
        INSTALL_COMMAND ""
        LOG_BUILD ON
        LOG_CONFIG ON
        LOG_INSTALL ON)

