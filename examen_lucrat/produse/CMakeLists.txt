cmake_minimum_required(VERSION 3.19)
project(produse)

set(CMAKE_CXX_STANDARD 14)

add_executable(produse main.cpp Produse.cpp Produse.h RepoProduse.cpp RepoProduse.h Service.cpp Service.h Exceptions.cpp Exceptions.h GUIObserver.cpp GUIObserver.h MyTableView.cpp MyTableView.h)


find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
target_link_libraries(produse Qt5::Widgets Qt5::Sql)