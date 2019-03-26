project (piksi_system_daemon)

set(SRCS
   main.c
	)

add_executable(
		piksi_system_daemon
		${SRCS}
		)

target_link_libraries(
		piksi_system_daemon
    sbp
    piksi
    dl
    settings
    ${LIBUV}
		)

install(
    TARGETS piksi_system_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )

install(
    PROGRAMS 
      overlay/etc/init.d/S82piksi_system_daemon
      overlay/etc/init.d/do_sbp_msg_reset
      overlay/etc/init.d/update_eth0_config
      overlay/etc/init.d/update_ntp_config
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/init.d
    )

install(
    FILES overlay/etc/sudoers.d/piksi_system_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/sudoers.d
    )

install(
    PROGRAMS overlay/etc/sv/piksi_system_daemon_runsvdir/run
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/sv/piksi_system_daemon_runsvdir
    )

