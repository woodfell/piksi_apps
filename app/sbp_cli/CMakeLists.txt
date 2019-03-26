project (sbp_cli)

set(LOG_SRCS
   sbp_log.c
	)

add_executable(
		sbp_log
		${LOG_SRCS}
		)

target_link_libraries(
		sbp_log
    sbp
    piksi
    settings
    ${LIBUV}
		)

set(CMD_RESP_SRCS
   sbp_cmd_resp.c
	)

add_executable(
		sbp_cmd_resp
		${CMD_RESP_SRCS}
		)

target_link_libraries(
		sbp_cmd_resp
    sbp
    piksi
    settings
    ${LIBUV}
		)

install(
    TARGETS sbp_log sbp_cmd_resp
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )
