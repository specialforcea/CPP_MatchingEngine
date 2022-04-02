cmake_minimum_required(VERSION 3.23.0)

project(ob)

add_executable(${PROJECT_NAME} main.cpp)

include_directories(../src)
link_directories(../src)

add_library(orderbook SHARED
    ../src/orderbook.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC ../src)

target_link_directories(${PROJECT_NAME} PUBLIC ../src)

target_link_libraries(${PROJECT_NAME} orderbook)
