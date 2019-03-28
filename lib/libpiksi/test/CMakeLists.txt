project(libpiksitests)

# run_libpiksi_tests
add_executable(
    run_libpiksi_tests
    run_libpiksi_tests.cc
    test_endpoint.cc
    test_misc.cc
    test_pubsub_loop_integration.cc
    test_reqrep_loop_integration.cc
    test_run.cc
    test_sha256.cc
    test_table.cc
    test_version.cc
    )

target_include_directories(
    run_libpiksi_tests
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
    )

target_link_libraries(
    run_libpiksi_tests
    piksi
    sbp
    dl
    settings
    ${CMAKE_THREAD_LIBS_INIT}
    ${LIBUV}
    gtest
    )

add_test(
    NAME run_libpiksi_tests
    COMMAND run_libpiksi_tests
    WORKING_DIRECTORY test
    )

# run_libpiksi_str_tests
add_executable(
    run_libpiksi_str_tests
    test_str.cc
    )

target_include_directories(
    run_libpiksi_str_tests
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
    )

target_link_libraries(
    run_libpiksi_str_tests
    piksi
    sbp
    dl
    settings
    ${CMAKE_THREAD_LIBS_INIT}
    ${LIBUV}
    gtest
    )

add_test(
    NAME run_libpiksi_str_tests
    COMMAND run_libpiksi_str_tests
    WORKING_DIRECTORY test
    )

# pk_test_server
add_executable(
    pk_test_server
    pk_test_server.c
    )

target_include_directories(
    pk_test_server
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
    )

target_link_libraries(
    pk_test_server
    piksi
    sbp
    dl
    settings
    ${CMAKE_THREAD_LIBS_INIT}
    ${LIBUV}
    )

add_test(
    NAME pk_test_server
    COMMAND pk_test_server
    WORKING_DIRECTORY test
    )
