cmake_minimum_required(VERSION 3.0)

project(cmake_modules)

include(GNUInstallDirs)

add_subdirectory(ProtectTarget)

install(FILES
    SetupDependency.cmake
    DESTINATION lib/cmake/SetupDependency
    )

install(FILES
    FindSetupDependency.cmake
    DESTINATION lib/cmake/SetupDependency
    RENAME SetupDependencyConfig.cmake
    )

install(FILES
    ProtectTarget.cmake
    DESTINATION lib/cmake/ProtectTarget.cmake
    )

install(FILES
    FindProtectTarget.cmake
    DESTINATION lib/cmake/ProtectTarget
    RENAME ProtectTargetConfig.cmake
    )

install(FILES 
    FindCheck.cmake
    ClangToolsLibsettings.cmake
    ClangTools.cmake
    Toolchain-gcc-arm-embedded.cmake

    DESTINATION lib/cmake/
    )
