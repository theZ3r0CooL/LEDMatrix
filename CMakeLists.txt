cmake_minimum_required(VERSION 3.5)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME LEDMatrix)
project(${PROJECT_NAME})

set(${CMAKE_PROJECT_NAME}_SKETCH LEDMatrix.ino)
set(${CMAKE_PROJECT_NAME}_BOARD esp32)
set(${CMAKE_PROJECT_NAME}_PORT /dev/ttyUSB0)

set(${CMAKE_PROJECT_NAME}_LIBRARY LEDMatrix)
set(${CMAKE_PROJECT_NAME}_LIBRARY_SRC LEDMatrix.cpp)
set(${CMAKE_PROJECT_NAME}_LIBRARIES Adafruit_NeoPixel)

set(ARDUINO_CORE_PATH /home/user/.arduino15/packages/esp32/hardware/esp32/1.0.6)

set(${CMAKE_PROJECT_NAME}_AFLAGS -Os -Wall -Wextra -Wno-expansion-to-defined -Wno-unused-parameter -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti)

generate_arduino_library(${CMAKE_PROJECT_NAME} ${${CMAKE_PROJECT_NAME}_LIBRARY_SRC})

find_arduino_library(neoPixel Adafruit_NeoPixel ${board_id} 3RD_PARTY)
link_arduino_library(${CMAKE_PROJECT_NAME} neoPixel ${board_id})