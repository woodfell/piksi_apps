project (pfw_welcome)

set(SRCS
   pfw_welcome.c
	)

add_executable(
		pfw_welcome
		${SRCS}
		)

target_link_libraries(
		pfw_welcome
    piksi
    settings
		sbp
    ${LIBUV}
		)

install(
    TARGETS pfw_welcome
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )
