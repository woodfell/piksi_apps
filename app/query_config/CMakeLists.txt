project (query_config)

set(SRCS
   query_config.c
	)

add_executable(
		query_config
		${SRCS}
		)

target_link_libraries(
		query_config
    sbp
    piksi
    settings
    ${LIBUV}
		)

install(
    TARGETS query_config
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )
