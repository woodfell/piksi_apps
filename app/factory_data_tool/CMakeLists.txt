project (factory_data_tool)

set(SRCS
  factory_data_tool.c
	)

add_executable(
		factory_data_tool
		${SRCS}
		)

target_link_libraries(
		factory_data_tool
    factorydata
		)

install(
    TARGETS factory_data_tool
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )
