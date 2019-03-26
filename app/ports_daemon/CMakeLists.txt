project (ports_daemon)

set(SRCS
  can.h
  ports.h
  protocols.h
  serial.h
  whitelists.h
  can.c
  ports.c
  ports_daemon.c
  protocols.c
  serial.c
  whitelists.c
	)

add_executable(
		ports_daemon
		${SRCS}
		)

target_link_libraries(
    ports_daemon
    sbp
    piksi
    dl
    socketcan
    settings
    ${LIBUV}
    )

install(
    TARGETS ports_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )

install(
    PROGRAMS overlay/etc/init.d/S82ports_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/init.d
    )

install(
    FILES overlay/etc/flags/can_ports
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/flags
    )

install(
    FILES overlay/etc/sudoers.d/ports_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/sudoers.d
    )

install(
    PROGRAMS overlay/etc/sv/ports_daemon_runsvdir/run
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/sv/ports_daemon_runsvdir
    )

if (BUILD_UNIT_TESTS)
  message(STATUS "Adding ports_daemon unit tests")
  add_executable(
      ports_daemon_tests
      test/run_ports_daemon_test.cc
      ${SRCS}
      )
  
  target_include_directories(
      ports_daemon_tests
      PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
      )

  target_link_libraries(
      ports_daemon_tests
      PUBLIC
      ${JSONC}
      sbp
      piksi
      dl
      socketcan
      ${CMAKE_THREAD_LIBS_INIT}
      ${LIBUV}
      ${GTEST_BOTH_LIBRARIES}
      )
  target_link_libraries(ports_daemon_tests PRIVATE "-z muldefs")

  add_test(
      NAME ports_daemon_tests
      COMMAND ports_daemon_tests
      WORKING_DIRECTORY test
      )
endif()

