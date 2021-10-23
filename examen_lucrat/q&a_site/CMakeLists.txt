cmake_minimum_required(VERSION 3.19)
project(q_a_site)

set(CMAKE_CXX_STANDARD 14)

add_executable(q_a_site main.cpp User.cpp User.h Answer.cpp Answer.h Question.cpp Question.h GUIObserver.cpp GUIObserver.h Service.cpp Service.h RepoUsers.cpp RepoUsers.h RepoQuestions.cpp RepoQuestions.h RepoAnswers.cpp RepoAnswers.h exceptions.cpp exceptions.h)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
target_link_libraries(q_a_site Qt5::Widgets Qt5::Sql)