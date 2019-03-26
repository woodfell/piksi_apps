project (cell_modem_daemon)

set(SRCS
  at_command_utils.h
  cell_modem_inotify.h
  cell_modem_probe.h
  cell_modem_settings.h
  at_command_utils.c
  cell_modem_daemon.c
  cell_modem_inotify.c
  cell_modem_probe.c
  cell_modem_settings.c
	)

add_executable(
		cell_modem_daemon
		${SRCS}
		)

target_link_libraries(
		cell_modem_daemon
    piksi
    settings
		sbp
    ${LIBUV}
		)

install(
    TARGETS cell_modem_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )

install(
    PROGRAMS
      overlay/etc/init.d/S86cell_modem_daemon
      overlay/etc/init.d/kill_pppd_service
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/init.d
    )

install(
    FILES overlay/etc/sudoers.d/cell_modem_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/sudoers.d
    )

install(
    PROGRAMS overlay/etc/sv/cell_modem_daemon_runsvdir/run
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/sv/cell_modem_daemon_runsvdir
    )
