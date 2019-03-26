project (metrics_daemon)

set(SRCS
   metrics_daemon.c
	)

add_executable(
    metrics_daemon
		metrics_daemon.h
    sbp.h
		metrics_daemon.c
    sbp.c
		${SRCS}
		)

target_link_libraries(
		metrics_daemon
    sbp
    piksi
    settings
    ${LIBJSONC}
    ${LIBUV}
		)

install(
    TARGETS metrics_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )

install(
    PROGRAMS overlay/etc/init.d/S86metrics_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/init.d
    )

install(
    FILES overlay/etc/logrotate.d/metrics_json
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/logrotate.d
    )

if (BUILD_UNIT_TESTS AND UNIT_TESTS_ARE_BROKEN_DO_NOT_COMPILE)
  message(STATUS "Adding metric_daemon unit tests")
  add_executable(
      metrics_daemon_tests
      metrics_daemon.c
      test/run_metrics_daemon_test.cc
      )

  target_include_directories(
      metrics_daemon_tests
      PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
      )

  target_link_libraries(
      metrics_daemon_tests
      PUBLIC
      piksi
      sbp
      settings
      ${LIBJSONC}
      ${GTEST_BOTH_LIBRARIES}
      )
  target_link_libraries(metrics_daemon_tests PRIVATE "-z muldefs")

  add_test(
      NAME metrics_daemon_tests
      COMMAND metrics_daemon_tests
      WORKING_DIRECTORY test
      )
endif()
