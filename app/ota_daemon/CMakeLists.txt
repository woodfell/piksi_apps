project (ota_daemon)

set(SRCS
   ota_settings.h
   ota_daemon.c
   ota_settings.c
	)

add_executable(
		ota_daemon
		${SRCS}
		)

target_link_libraries(
		ota_daemon
    curl
    sbp
    piksi
    network
    m
    json-c
    settings
    ${LIBUV}
		)

install(
    TARGETS ota_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )

install(
    PROGRAMS overlay/etc/init.d/S85ota_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/init.d
    )
