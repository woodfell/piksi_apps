project (ntrip_daemon)

set(SRCS
    ntrip_settings.h
    ntrip_daemon.c
    ntrip_settings.c
	)

add_executable(
		ntrip_daemon
		${SRCS}
		)

target_link_libraries(
		ntrip_daemon
    piksi
    settings
		sbp
    network
    curl
    ${LIBUV}
		)

install(
    TARGETS ntrip_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )

install(
    PROGRAMS overlay/etc/init.d/S82ntrip_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}
    )
