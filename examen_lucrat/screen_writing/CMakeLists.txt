cmake_minimum_required(VERSION 3.19)
project(screen_writing)

set(CMAKE_CXX_STANDARD 14)

add_executable(screen_writing main.cpp Writer.cpp Writer.h Idea.cpp Idea.h RepoWriter.cpp RepoWriter.h Exceptions.cpp Exceptions.h RepoIdea.cpp RepoIdea.h Service.cpp Service.h GUIObserver.cpp GUIObserver.h MyTableView.h)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
target_link_libraries(screen_writing Qt5::Widgets Qt5::Sql)