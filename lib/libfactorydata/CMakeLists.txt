project (libfactorydata)

set (HDRS
    factory_data.h
    image_table.h
    )

set (SRCS
    common.h
    compiler.h
    factory_data.c
    image_table.c
    )

add_library(
    factorydata SHARED
    ${SRCS}
    ${HDRS}
    )

target_include_directories(
    factorydata
    PUBLIC ${PROJECT_SOURCE_DIR}
    )

target_link_libraries(
    factorydata
    z
    )

install(
    TARGETS factorydata
    DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    )

install(
    FILES ${HDRS}
    DESTINATION include
    )
