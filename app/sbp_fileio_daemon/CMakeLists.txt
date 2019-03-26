project (sbp_fileio_daemon)

set(DAEMON_SRCS
    main.c
    sbp_fileio.c
    path_validator.c
	)

add_executable(
		sbp_fileio_daemon
		${DAEMON_SRCS}
		)

target_link_libraries(
		sbp_fileio_daemon
    piksi
    settings
		sbp
    ${LIBUV}
    ${CMAKE_THREAD_LIBS_INIT}
		)

set(FLUSH_SRCS
    flush_main.c
    sbp_fileio.c
    path_validator.c
   )

add_executable(
    sbp_fileio_flush
    ${FLUSH_SRCS}
    )

target_link_libraries(
    sbp_fileio_flush
    piksi
    settings
    sbp
    ${LIBUV}
    ${CMAKE_THREAD_LIBS_INIT}
    )

install(
    TARGETS sbp_fileio_daemon sbp_fileio_flush
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )

install(
    PROGRAMS overlay/etc/init.d/S81sbp_fileio_daemon_external
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/init.d
    )

if (BUILD_UNIT_TESTS)
  message(STATUS "Adding sbp_fileio_daemon unit tests")
  add_executable(
      sbp_fileio_daemon_tests
      sbp_fileio.c
      path_validator.c
      test/run_sbp_fileio_daemon_tests.cc
      )
  
  target_include_directories(
      sbp_fileio_daemon_tests
      PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
      )

  target_link_libraries(
      sbp_fileio_daemon_tests
      piksi
      ${CMAKE_THREAD_LIBS_INIT}
      ${LIBUV}
      ${GTEST_BOTH_LIBRARIES}
      )

  add_test(
      NAME sbp_fileio_daemon_tests
      COMMAND sbp_fileio_daemon_tests
      WORKING_DIRECTORY test
      )
endif()

