project (csac_daemon)

set(SRCS
   csac_daemon.c
	)

add_executable(
		csac_daemon
		${SRCS}
		)

target_link_libraries(
		csac_daemon
    piksi
    settings
		sbp
    gnss_converters
    ${LIBUV}
		)

install(
    TARGETS csac_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )

install(
    PROGRAMS overlay/etc/init.d/S86csac_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/init.d
    )
