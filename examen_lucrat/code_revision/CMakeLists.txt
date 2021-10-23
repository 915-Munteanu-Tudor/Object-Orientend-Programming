cmake_minimum_required(VERSION 3.19)
project(code_revision)

set(CMAKE_CXX_STANDARD 14)

add_executable(code_revision main.cpp Programmer.cpp Programmer.h SourceFile.cpp SourceFile.h RepoProgrammer.cpp RepoProgrammer.h exceptions.cpp exceptions.h RepoSourceFile.cpp RepoSourceFile.h Service.cpp Service.h GUIObserver.cpp GUIObserver.h)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
target_link_libraries(code_revision Qt5::Widgets Qt5::Sql)