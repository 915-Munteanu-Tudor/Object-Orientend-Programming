cmake_minimum_required(VERSION 3.19)
project(examne_practic)

set(CMAKE_CXX_STANDARD 14)

add_executable(examne_practic main.cpp Ethnologist.cpp Ethnologist.h Building.cpp Building.h RepoBuildings.cpp RepoBuildings.h RepoEthnologists.cpp RepoEthnologists.h Service.cpp Service.h GUIObserver.cpp GUIObserver.h)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
target_link_libraries(examne_practic Qt5::Widgets Qt5::Sql)