project (sbp_rtcm3_bridge)

set(SRCS
    sbp.h
    sbp_rtcm3_bridge.c
    sbp.c
	)

add_executable(
		sbp_rtcm3_bridge
		${SRCS}
		)

target_link_libraries(
    sbp_rtcm3_bridge
    sbp
    piksi
    settings
    gnss_converters
    ${LIBUV}
    )

install(
    TARGETS sbp_rtcm3_bridge
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )
