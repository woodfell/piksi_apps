project (piksi_leds)

set(SRCS
  firmware_state.h
  led_adp8866.h
  led_adp8866_regs.h
  manage_led.h
  firmware_state.c
  led_adp8866.c
  main.c
  manage_led.c
	)

add_executable(
		piksi_leds
		${SRCS}
		)

target_link_libraries(
		piksi_leds
    sbp
    piksi
    settings
    ${CMAKE_THREAD_LIBS_INIT}
    ${LIBUV}
		)

install(
    TARGETS piksi_leds
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )
