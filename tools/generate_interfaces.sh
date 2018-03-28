#!/usr/bin/env bash
# Generate library API with djinni

echo "Generating core API"
if [[ $# -gt 0 ]] ; then
    trace="true";
else
    trace="false";
fi
echo "Enable debug compilation " $trace
CORE_CPP_API_DIRECTORY=core/src/ledger-core-source-api/api
CORE_CPP_JNI_DIRECTORY=core/src/ledger-core-source-api/jni
rm -rf $CORE_CPP_API_DIRECTORY $CORE_CPP_JNI_DIRECTORY
./djinni/src/run    --idl ./core/core.djinni \
                    --cpp-out $CORE_CPP_API_DIRECTORY \
                    --cpp-namespace ledger::core::api \
                    --cpp-optional-template std::experimental::optional \
                    --cpp-optional-header "\"../../utils/optional.hpp\"" \
                    --jni-include-cpp-prefix "../../../api/" \
                    --jni-out $CORE_CPP_JNI_DIRECTORY/jni \
                    --java-out ledger-core-api/api/core/java \
                    --java-package co.ledger.core \
                    --swift-out ledger-core-api/api/core/swift \
                    --swift-umbrella-header ledger-core.h \
                    --objc-type-prefix LG \
                    --objc-out ledger-core-api/api/core/objc \
                    --objcpp-out ledger-core-api/api/core/objcpp \
                    --node-out ledger-core-api/api/core/nodejs \
					--node-type-prefix NJS \
        			--node-include-cpp ../../../../$CORE_CPP_API_DIRECTORY \
        			--node-package ledgerapp_nodejs \
                    --trace $trace

cp ./djinni/support-lib/jni/* $CORE_CPP_JNI_DIRECTORY/jni
cp ./djinni/support-lib/*.hpp $CORE_CPP_JNI_DIRECTORY

