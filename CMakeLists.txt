cmake_minimum_required(VERSION 3.10)

project (piksi_apps C CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(GNUInstallDirs)

if(CMAKE_CROSSCOMPILING)
  message(STATUS "Skipping unit tests because we are cross compiling")
else()
  message(STATUS "Enabling unit tests")
  find_package(gtest REQUIRED)
  enable_testing()
  set(BUILD_UNIT_TESTS TRUE)
endif()

find_package(rtcm REQUIRED)
find_package(swiftnav REQUIRED)
find_package(sbp REQUIRED)
find_package(settings REQUIRED)
find_package(gnss_converters REQUIRED)

find_library(LIBUV NAMES libuv.so PATHS /usr/local/lib)
find_library(LIBJSONC NAMES libjson-c.so PATHS /usr/local/lib)
find_package(Threads REQUIRED)

if(CMAKE_CROSSCOMPILING)
  add_custom_target(
      rootfs-overlay
      COMMAND env BUILD_DIR=${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR}/scripts/make-rootfs-overlay.sh
      )
endif()

add_subdirectory(lib)
add_subdirectory(protocol)
add_subdirectory(app)

