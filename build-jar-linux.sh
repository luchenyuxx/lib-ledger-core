#!/bin/bash
set -eo pipefail

export JAVA_OPTS="-Dfile.encoding=UTF-8"

apt update
apt install -y openjdk-8-jdk

cd $LINUX_BUILD_DIR
cmake -DTARGET_JNI=ON $LINUX_SRC_DIR
make -j 8
