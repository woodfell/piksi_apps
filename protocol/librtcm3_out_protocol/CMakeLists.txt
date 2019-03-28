project (librtcm3_out_protocol)

set (SRCS
    info_rtcm3_out.c
  )

add_library(
    rtcm3_out_protocol SHARED
    ${SRCS}
    )

install(
    TARGETS rtcm3_out_protocol
    DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}/endpoint_protocols
    )
