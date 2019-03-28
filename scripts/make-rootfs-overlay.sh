#!/bin/bash

if [ -z "${BUILD_DIR}" ];
then
  echo "This script should only be run as part of a build. Specify BUILD_DIR if you really want to run it externally"
  exit 1
fi

if [ ! -d "${BUILD_DIR}" ];
then
  echo "$BUILD_DIR doesn't exist"
  exit 1
fi

cd $BUILD_DIR
make DESTDIR=rootfs-overlay install
cd rootfs-overlay
tar -zcv --owner=root --group=root -f ../rootfs-overlay.tar.gz *
cd $BUILD_DIR
rm -rf rootfs-overlay

echo "Root fs overlay available at $(pwd)/rootfs-overlay.tar.gz"

