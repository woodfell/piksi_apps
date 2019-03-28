project (sbp_settings_daemon)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SRCS
    internal/setting.h
    main.c
    setting.c
    settings_sbp_cb.c
	)

add_executable(
		sbp_settings_daemon
		${SRCS}
		)

target_link_libraries(
		sbp_settings_daemon
    sbp
    piksi
    settings
    ${LIBUV}
		)

install(
    TARGETS sbp_settings_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )

if (BUILD_UNIT_TESTS)
  message(STATUS "Adding sbp_settings_daemon unit tests")
  add_executable(
      sbp_settings_daemon_tests
      setting.c
      test/run_sbp_settings_daemon_test.cc
      )

  target_include_directories(
      sbp_settings_daemon_tests
      PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
      )

  target_link_libraries(
      sbp_settings_daemon_tests
      piksi
      gtest
      )

  add_test(
      NAME sbp_settings_daemon_tests
      COMMAND sbp_settings_daemon_tests
      WORKING_DIRECTORY test
      )
endif()
