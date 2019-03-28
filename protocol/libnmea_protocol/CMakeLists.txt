project (libnmea_protocol)

set (SRCS
    info_nmea.c
  )

add_library(
    nmea_protocol SHARED
    ${SRCS}
    )

target_link_libraries(
    nmea_protocol
    piksi
    )

install(
    TARGETS nmea_protocol
    DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}/endpoint_protocols
    )

install(
    FILES nmea_router.yml
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/endpoint_router
    )
