#!/bin/sh

if [ -e build.target ];
then
  echo "build.target already exists"
  exit 1
fi

if [ ! -e CMakeLists.txt ];
then
  echo "No CMakeLists.txt"
  exit 1
fi

SDK=/opt/piksi-sdk
if [ "x$1" != "x" ];
then
  SDK=$1
  shift
fi

TOOLCHAIN_FILE="${SDK}/usr/share/buildroot/toolchainfile.cmake"
if [ ! -e "${TOOLCHAIN_FILE}" ];
then
  echo "Could not find toolchain file in ${SDK}"
  exit 1
fi

mkdir build.target
cd build.target
cmake -DBUILD_SHARED_LIBS=y -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_TOOLCHAIN_FILE=${TOOLCHAIN_FILE} ..
