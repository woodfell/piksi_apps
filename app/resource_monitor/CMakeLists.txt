project (resource_monitor)

set(SRCS
  query_sys_state.h
  resmon_common.h
  resource_monitor.h
  resource_query.h
  sbp.h
  query_cpu_usage.c
  query_mem_usage.c
  query_sockets.c
  query_sys_state.c
  resmon_common.c
  resource_monitor.c
  resource_query.c
  sbp.c
	)

add_executable(
		resource_monitor
		${SRCS}
		)

target_link_libraries(
		resource_monitor
    piksi
    settings
		sbp
    m
    ${LIBUV}
    ${CMAKE_THREAD_LIBS_INIT}
		)

install(
    TARGETS resource_monitor
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )

install(
    PROGRAMS overlay/etc/init.d/S99resource_monitor
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/init.d
    )

install(
    FILES overlay/etc/sudoers.d/resource_monitor
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/sudoers.d
    )

install(
  PROGRAMS overlay/etc/sv/resource_monitor_runsvdir/run
  DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/sv/resource_monitor_runsvdir
  )

if (BUILD_UNIT_TESTS)
  message(STATUS "Adding resource_monitor unit tests")
  add_executable(
      resource_monitor_tests
      test/run_resource_monitor_test.cc
      ${SRCS}
      )
  
  target_include_directories(
      resource_monitor_tests
      PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
      )

  target_link_libraries(
      resource_monitor_tests
      PUBLIC
      ${JSONC}
      sbp
      piksi
      dl
      ${CMAKE_THREAD_LIBS_INIT}
      ${LIBUV}
      gtest
      )
  target_link_libraries(resource_monitor_tests PRIVATE "-z muldefs")

  add_test(
      NAME resource_monitor_tests
      COMMAND resource_monitor_tests
      WORKING_DIRECTORY test
      )
endif()

