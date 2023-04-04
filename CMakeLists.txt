cmake_minimum_required(VERSION 3.13)

project(LEDMatrix)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES LEDMatrix.cpp)

set(HEADERS LEDMatrix.h)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} Adafruit_NeoPixel)
