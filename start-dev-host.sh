#!/bin/sh

if [ -e build ];
then
  echo "build already exists"
  exit 1
fi

if [ ! -e CMakeLists.txt ];
then
  echo "No CMakeLists.txt"
  exit 1
fi

mkdir build
cd build
cmake VERBOSE=1 -DBUILD_SHARED_LIBS=y -DCMAKE_INSTALL_PREFIX=/usr/local ..
