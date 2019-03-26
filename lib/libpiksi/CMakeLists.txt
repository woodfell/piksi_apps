project (libpiksi C CXX)

set (HDRS
  include/libpiksi/cast_check.h
  include/libpiksi/common.h
  include/libpiksi/endpoint.h
  include/libpiksi/filter.h
  include/libpiksi/framer.h
  include/libpiksi/interface.h
  include/libpiksi/logging.h
  include/libpiksi/loop.h
  include/libpiksi/metrics.h
  include/libpiksi/metrics_foreach.h
  include/libpiksi/metrics_table.h
  include/libpiksi/min_ini.h
  include/libpiksi/min_ini_glue.h
  include/libpiksi/networking.h
  include/libpiksi/protocols.h
  include/libpiksi/runit.h
  include/libpiksi/sbp_pubsub.h
  include/libpiksi/sbp_rx.h
  include/libpiksi/sbp_tx.h
  include/libpiksi/serial_utils.h
  include/libpiksi/settings_client.h
  include/libpiksi/sha256.h
  include/libpiksi/table.h
  include/libpiksi/util.h
  include/libpiksi/version.h
  )

set (SRCS
  src/filter_none.h
  src/framer_none.h
  src/endpoint.c
  src/filter.c
  src/filter_none.c
  src/framer.c
  src/framer_none.c
  src/interface.c
  src/logging.c
  src/loop.c
  src/metrics.c
  src/min_ini.c
  src/networking.c
  src/protocols.c
  src/runit.c
  src/sbp_pubsub.c
  src/sbp_rx.c
  src/sbp_tx.c
  src/serial_utils.c
  src/settings_client.c
  src/sha256.c
  src/table.c
  src/util.c
  src/version.c
  )

add_library(
    piksi SHARED
    ${SRCS}
    ${HDRS}
    )

target_include_directories(
    piksi
    PUBLIC ${PROJECT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
    )

target_link_libraries(
    piksi
    sbp
    settings
    ${LIBUV}
    )

install(
    TARGETS piksi
    DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    )

install(
    FILES ${HDRS}
    DESTINATION include/libpiksi
    )

if (BUILD_UNIT_TESTS)
  message(STATUS "Adding libpiksi unit tests")
  add_subdirectory(test)
endif()

