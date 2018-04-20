
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#Remove mongoose, MongooseHttpClient, MongooseSimpleRestServer, AsioHttpClient because we removed openssl dependency
add_library(ledger-test STATIC
            EventLooper.cpp EventLooper.hpp EventThread.cpp EventThread.hpp
            NativeThreadDispatcher.cpp NativeThreadDispatcher.hpp
            NativePathResolver.cpp NativePathResolver.hpp
            CoutLogPrinter.cpp CoutLogPrinter.hpp
            route.cc route.h RustRandomNumberGenerator.cpp RustRandomNumberGenerator.hpp callbacks.cpp callbacks.hpp FakeWebSocketClient.cpp FakeWebSocketClient.h)

include_directories(${CMAKE_BINARY_DIR}/include)

target_link_libraries(ledger-test PUBLIC crypto_wrapper)
target_include_directories(ledger-test PUBLIC ../../../lib/crypto/wrapper/crypto)

include_directories(../boost)
target_include_directories(ledger-test PUBLIC ../../../lib/fmt-3.0.0)
target_include_directories(ledger-test PUBLIC ../../../lib/cereal/)
target_include_directories(ledger-test PUBLIC ../../../../core)
target_include_directories(ledger-test PUBLIC ../../../../core/src)
