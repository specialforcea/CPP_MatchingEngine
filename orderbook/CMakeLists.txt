cmake_minimum_required(VERSION 3.23.0)

project(ob)

# add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME} ./test/time_execution.cpp)

include_directories(./src)
link_directories(./src)

add_subdirectory(./src)

target_include_directories(${PROJECT_NAME} PUBLIC ./src)

target_link_directories(${PROJECT_NAME} PUBLIC ./src)

target_link_libraries(${PROJECT_NAME} orderbook)

target_link_libraries(${PROJECT_NAME} orderentry)

target_link_libraries(${PROJECT_NAME} ordermap)

target_link_libraries(${PROJECT_NAME} limitprice)