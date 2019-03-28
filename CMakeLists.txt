cmake_minimum_required(VERSION 3.10)

project (piksi_apps C CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(GNUInstallDirs)
include(SetupDependency)

if(CMAKE_CROSSCOMPILING)
  message(STATUS "Skipping unit tests because we are cross compiling")
else()
  message(STATUS "Enabling unit tests")
  SetupDependency(TARGET gtest SUBDIR third_party/googletest/googletest CHECK_TARGET REQUIRED PACKAGE GTest)
  enable_testing()
  set(BUILD_UNIT_TESTS TRUE)
endif()

SetupDependency(TARGET rtcm SUBDIR third_party/librtcm/c CHECK_TARGET REQUIRED LIBS librtcm.so)
SetupDependency(TARGET swiftnav CHECK_TARGET REQUIRED LIBS libswiftnav.so)
SetupDependency(TARGET sbp SUBDIR third_party/libsbp/c CHECK_TARGET REQUIRED LIBS libsbp.so)
SetupDependency(TARGET settings CHECK_TARGET REQUIRED LIBS libsettings.so)
SetupDependency(TARGET gnss_converters SUBDIR third_party/gnss-converters/c CHECK_TARGET REQUIRED LIBS libgnss_converters.so)

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

