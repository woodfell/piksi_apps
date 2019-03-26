project (orion_daemon CXX)

option(BUILD_ORION_DAEMON "Compile the orion daemon process" OFF)

if ( NOT BUILD_ORION_DAEMON )
  return()
endif()

find_program(
  GRPC_CPP_PLUGIN
  NAMES grpc_cpp_plugin
  )

if ( NOT GRPC_CPP_PLUGIN )
  message(WARNING "Can't find grpc protoc plugin, orion_daemon will be skipped")
  return()
endif ( NOT GRPC_CPP_PLUGIN )

set(SRCS
  orion.pb.cc
  orion.grpc.pb.cc
  orion_daemon.cc
	)

add_executable(
		orion_daemon
		${SRCS}
		)

target_include_directories(
    orion_daemon
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
    )

target_link_libraries(
		orion_daemon
    sbp
    stdc++
    protobuf
    grpc++_unsecure
    ${CMAKE_THREAD_LIBS_INIT}
    piksi
    settings
    ${LIBUV}
		)

install(
    TARGETS orion_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
    )

install(
    PROGRAMS overlay/etc/init.d/S82orion_daemon
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/init.d
    )

add_custom_command(
    OUTPUT orion.grpc.pb.cc
    COMMAND protoc --grpc_out=${CMAKE_CURRENT_BINARY_DIR} --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN} --proto_path=${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/orion.proto
    DEPENDS orion.proto
    COMMENT "Generating orion.grpc.pb.cc"
    )

add_custom_command(
    OUTPUT orion.pb.cc
    COMMAND protoc --cpp_out=${CMAKE_CURRENT_BINARY_DIR} --proto_path=${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/orion.proto
    DEPENDS orion.proto
    COMMENT "Generating orion.pb.cc"
    )

add_custom_target(
    RunGenerator 
    DEPENDS orion.grpc.pb.cc orion.pb.cc
    COMMENT "Checking if re-generation is required"
    )

add_dependencies(
    orion_daemon
    RunGenerator
    )
