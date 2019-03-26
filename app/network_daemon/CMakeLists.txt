project (network_daemon)

set(SRCS
    network_daemon.c
	)

add_executable(
		network_daemon
		${SRCS}
		)

target_link_libraries(
		network_daemon
    sbp
    piksi
    settings
    ${LIBUV}
		)

install(
    TARGETS network_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )

install(
    PROGRAMS overlay/etc/init.d/S86network_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/init.d
    )
