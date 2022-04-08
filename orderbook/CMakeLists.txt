cmake_minimum_required(VERSION 3.23.0)

project(ob)

add_executable(${PROJECT_NAME} main.cpp)

include_directories(./src)
link_directories(./src)

add_library(orderbook SHARED
    ./src/orderbook.cpp
)

add_library(orderentry SHARED
    ./src/OrderEntry.cpp
)

add_library(ordermap SHARED
    ./src/ordermap.cpp
)

add_library(limitprice SHARED
    ./src/LimitPrice.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ./src)

target_link_directories(${PROJECT_NAME} PUBLIC ./src)

target_link_libraries(${PROJECT_NAME} orderbook)

target_link_libraries(${PROJECT_NAME} orderentry)

target_link_libraries(${PROJECT_NAME} ordermap)

target_link_libraries(${PROJECT_NAME} limitprice)