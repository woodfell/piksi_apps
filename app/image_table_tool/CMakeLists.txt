project (image_table_tool)

set(SRCS
  image_table_tool.c
	)

add_executable(
		image_table_tool
		${SRCS}
		)

target_link_libraries(
		image_table_tool
    factorydata
		)

install(
    TARGETS image_table_tool
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )
