project (librtcm3_in_protocol)

set (SRCS
    info_rtcm3_in.c
    framer_rtcm3_in.c
  )

add_library(
    rtcm3_in_protocol SHARED
    ${SRCS}
    )

target_link_libraries(
    rtcm3_in_protocol
    piksi
    )

install(
    TARGETS rtcm3_in_protocol
    DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}/endpoint_protocols
    )

install(
    FILES rtcm3_router.yml
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/endpoint_router
    )
