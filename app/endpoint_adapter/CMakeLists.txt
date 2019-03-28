project (endpoint_adapter)

set(SRCS
	endpoint_adapter.c
	endpoint_adapter_stdio.c
	endpoint_adapter_file.c
	endpoint_adapter_tcp_listen.c
	endpoint_adapter_tcp_connect.c
	endpoint_adapter_udp_listen.c
	endpoint_adapter_udp_connect.c
	endpoint_adapter_can.c
	)

add_executable(
		endpoint_adapter
		${SRCS}
		)

target_link_libraries(
		endpoint_adapter
    piksi
    settings
		sbp
    ${LIBUV}
    ${CMAKE_THREAD_LIBS_INIT}
		)

install(
    TARGETS endpoint_adapter
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )
