cmake_minimum_required(VERSION 2.8.12)

project(googletest-download NONE)

include(ExternalProject)
ExternalProject_Add(googletest
        GIT_REPOSITORY    https://github.com/google/googletest.git
        GIT_TAG           master
        SOURCE_DIR        "T:/materiale/an1/sem2/oop/Object-Orientend-Programming git/cpy lb4/cmake-build-debug-coverage/googletest-src"
        BINARY_DIR        "T:/materiale/an1/sem2/oop/Object-Orientend-Programming git/cpy lb4/cmake-build-debug-coverage/googletest-build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND     ""
        INSTALL_COMMAND   ""
        TEST_COMMAND      ""
        )
