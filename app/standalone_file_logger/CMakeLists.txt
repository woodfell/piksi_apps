project (standalone_file_logger C CXX)

set(SRCS
    rotating_logger.h
    rotating_logger.cc
    standalone_file_logger.cc
	)

add_executable(
		standalone_file_logger
		${SRCS}
		)

target_link_libraries(
		standalone_file_logger
    sbp
    piksi
    settings
    ${CMAKE_THREAD_LIBS_INIT}
    ${LIBUV}
		)

install(
    TARGETS standalone_file_logger
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )

install(
    FILES overlay/etc/sudoers.d/standalone_file_logger
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/sudoers.d
    )

if (BUILD_UNIT_TESTS)
  message(STATUS "Adding standalone_file_logger unit tests")
  add_executable(
      standalone_file_logger_tests
      rotating_logger.cc
      standalone_file_logger.cc
      test/run_rotating_logger_test.cc
      )
  
  target_include_directories(
      standalone_file_logger_tests
      PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
      )

  target_link_libraries(
      standalone_file_logger_tests
      PUBLIC
      piksi
      ${CMAKE_THREAD_LIBS_INIT}
      ${LIBUV}
      gtest
      )
  target_link_libraries(standalone_file_logger_tests PRIVATE "-z muldefs")

  add_test(
      NAME standalone_file_logger_tests
      COMMAND standalone_file_logger_tests
      WORKING_DIRECTORY test
      )
endif()

