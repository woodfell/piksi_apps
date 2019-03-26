project (sbp_nmea_bridge)

set(SRCS
    sbp.h
    sbp.c
    sbp_nmea_bridge.c
	)

add_executable(
		sbp_nmea_bridge
		${SRCS}
		)

target_link_libraries(
    sbp_nmea_bridge
    sbp
    piksi
    gnss_converters
    settings
    m
    ${LIBUV}
    )

install(
    TARGETS sbp_nmea_bridge
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )
