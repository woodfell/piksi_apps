project (skylark_daemon)

set(SRCS
    skylark_settings.h
    skylark_daemon.c
    skylark_settings.c
	)

add_executable(
		skylark_daemon
		${SRCS}
		)

target_link_libraries(
		skylark_daemon
    curl
    sbp
    piksi
    network
    settings
    ${LIBUV}
		)

install(
    TARGETS skylark_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )

install(
    PROGRAMS overlay/etc/init.d/S82skylark_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/init.d
    )
