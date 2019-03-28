project (endpoint_router)

set(SRCS
  endpoint_router.h
  endpoint_router_load.h
  endpoint_router_print.h
  endpoint_router.c
  endpoint_router_load.c
  endpoint_router_print.c
	)

add_executable(
		endpoint_router
		${SRCS}
		)

target_link_libraries(
		endpoint_router
    piksi
    settings
		sbp
    cmph
    yaml
    ${LIBUV}
		)

install(
    TARGETS endpoint_router
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )

if (BUILD_UNIT_TESTS)
  message(STATUS "Adding endpoint_router unit tests")
  add_executable(
      endpoint_router_tests
      test/endpoint_router_test.cc
      ${SRCS}
      )
  
  target_include_directories(
      endpoint_router_tests
      PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
      )

  target_link_libraries(
      endpoint_router_tests
      PUBLIC
      sbp
      piksi
      dl
      yaml
      ${CMAKE_THREAD_LIBS_INIT}
      settings
      cmph
      ${LIBUV}
      gtest
      )
  target_link_libraries(endpoint_router_tests PRIVATE "-z muldefs")

  add_test(
      NAME endpoint_router_tests
      COMMAND endpoint_router_tests
      WORKING_DIRECTORY test
      )
endif()

