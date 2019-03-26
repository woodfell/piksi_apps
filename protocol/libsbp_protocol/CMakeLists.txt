project (libsbp_protocol)

set (SRCS
    filter_sbp.c
    framer_sbp.c
    info_sbp.c
  )

add_library(
    sbp_protocol SHARED
    ${SRCS}
    )

target_link_libraries(
    sbp_protocol
    piksi
    )

install(
    TARGETS sbp_protocol
    DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    )

install(
    FILES sbp_router_smoothpose.yml sbp_router.yml
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/endpoint_router
    )
