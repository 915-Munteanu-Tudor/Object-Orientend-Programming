cmake_minimum_required(VERSION 3.17)
project(LAB_4_OOP)

set(CMAKE_CXX_STANDARD 14)

include_directories("LAB 4 OOP/ComplexTests")
include_directories("LAB 4 OOP/LAB 4 OOP")

add_executable(LAB_4_OOP

        "LAB 4 OOP/LAB 4 OOP/app.cpp"
        "LAB 4 OOP/LAB 4 OOP/Dog.cpp"
        "LAB 4 OOP/LAB 4 OOP/Dog.h"
#        "LAB 4 OOP/LAB 4 OOP/DynamicArrayItterator.cpp"
#        "LAB 4 OOP/LAB 4 OOP/DynamicArrayItterator.h"
#        "LAB 4 OOP/LAB 4 OOP/DynamicArray.h"
         "LAB 4 OOP/LAB 4 OOP/app.h" "LAB 4 OOP/LAB 4 OOP/main.cpp" "LAB 4 OOP/LAB 4 OOP/repoDog.cpp" "LAB 4 OOP/LAB 4 OOP/repoDog.h" "LAB 4 OOP/LAB 4 OOP/exceptions.cpp" "LAB 4 OOP/LAB 4 OOP/exceptions.h" "LAB 4 OOP/LAB 4 OOP/validators.cpp" "LAB 4 OOP/LAB 4 OOP/validators.h" "LAB 4 OOP/LAB 4 OOP/adoption.cpp" "LAB 4 OOP/LAB 4 OOP/adoption.h"
        "LAB 4 OOP/LAB 4 OOP/Qt/QtApp.cpp" "LAB 4 OOP/LAB 4 OOP/Qt/QtApp.h" "LAB 4 OOP/LAB 4 OOP/Qt/Menu.cpp" "LAB 4 OOP/LAB 4 OOP/Qt/Menu.h" "LAB 4 OOP/LAB 4 OOP/Qt/User.cpp" "LAB 4 OOP/LAB 4 OOP/Qt/User.h" "LAB 4 OOP/LAB 4 OOP/Qt/Admin.cpp" "LAB 4 OOP/LAB 4 OOP/Qt/Admin.h" "LAB 4 OOP/LAB 4 OOP/UndoRedo.cpp" "LAB 4 OOP/LAB 4 OOP/UndoRedo.h" "LAB 4 OOP/LAB 4 OOP/Service.cpp" "LAB 4 OOP/LAB 4 OOP/Service.h")
#        "LAB 4 OOP/LAB 4 OOP/DynamicArrayItterator.cpp" "LAB 4 OOP/LAB 4 OOP/DynamicArrayItterator.h")
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(tests         "LAB 4 OOP/LAB 4 OOP/app.cpp"
        "LAB 4 OOP/LAB 4 OOP/Dog.cpp"
        "LAB 4 OOP/LAB 4 OOP/Dog.h"
        "LAB 4 OOP/LAB 4 OOP/DynamicArrayItterator.cpp"
        "LAB 4 OOP/LAB 4 OOP/DynamicArrayItterator.h"
        "LAB 4 OOP/LAB 4 OOP/DynamicArray.h"
        "LAB 4 OOP/LAB 4 OOP/app.h" "LAB 4 OOP/ComplexTests/ComplexTests.cpp ")
target_link_libraries(tests gtest_main)
#add_test(NAME example_test COMMAND example)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\")

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
target_link_libraries(LAB_4_OOP Qt5::Widgets Qt5::Sql)