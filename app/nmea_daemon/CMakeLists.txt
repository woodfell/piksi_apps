project (nmea_daemon)

set(SRCS
   nmea_daemon.c
	)

add_executable(
		nmea_daemon
		${SRCS}
		)

target_link_libraries(
		nmea_daemon
    piksi
    settings
		sbp
    gnss_converters
    ${LIBUV}
		)

install(
    TARGETS nmea_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )
