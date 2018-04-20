

set(command "/usr/local/Cellar/cmake/3.10.1/bin/cmake;-Dmake=${make};-Dconfig=${config};-P;/Users/elkhalilbellakrid/Desktop/Playground_07/lib-ledger-core/core/lib/crypto/src/rust-crypto/src/crypto-stamp/crypto-build--impl.cmake")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/Users/elkhalilbellakrid/Desktop/Playground_07/lib-ledger-core/core/lib/crypto/src/rust-crypto/src/crypto-stamp/crypto-build-out.log"
  ERROR_FILE "/Users/elkhalilbellakrid/Desktop/Playground_07/lib-ledger-core/core/lib/crypto/src/rust-crypto/src/crypto-stamp/crypto-build-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /Users/elkhalilbellakrid/Desktop/Playground_07/lib-ledger-core/core/lib/crypto/src/rust-crypto/src/crypto-stamp/crypto-build-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "crypto build command succeeded.  See also /Users/elkhalilbellakrid/Desktop/Playground_07/lib-ledger-core/core/lib/crypto/src/rust-crypto/src/crypto-stamp/crypto-build-*.log")
  message(STATUS "${msg}")
endif()
