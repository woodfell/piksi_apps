project (sample_daemon)

set(SRCS
  sbp.h
  udp_socket.h
  sample_daemon.c
  sbp.c
  udp_socket.c
	)

add_executable(
		sample_daemon
		${SRCS}
		)

target_link_libraries(
		sample_daemon
    sbp
    piksi
    settings
    ${CMAKE_THREAD_LIBS_INIT}
    ${LIBUV}
		)

install(
    TARGETS sample_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )

install(
    PROGRAMS overlay/etc/init.d/S83sample_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/init.d
    )
