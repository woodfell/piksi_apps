project (health_daemon)

set(SRCS
  base_num_sats_monitor.h
  baseline_monitor.h
  glo_bias_monitor.h
  glo_health_context.h
  glo_obs_monitor.h
  gnss_time_monitor.h
  health_context.h
  health_monitor.h
  ntrip_obs_monitor.h
  skylark_monitor.h
  base_num_sats_monitor.c
  baseline_monitor.c
  glo_bias_monitor.c
  glo_health_context.c
  glo_obs_monitor.c
  gnss_time_monitor.c
  health_daemon.c
  health_monitor.c
  ntrip_obs_monitor.c
  skylark_monitor.c
	)

add_executable(
		health_daemon
		${SRCS}
		)

target_link_libraries(
		health_daemon
    sbp
    piksi
    m
    network
    curl
    swiftnav
    settings
    ${LIBUV}
		)

install(
    TARGETS health_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )
