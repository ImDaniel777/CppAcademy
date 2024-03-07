cmake_minimum_required(VERSION 3.0 )

project(STRATEGY_PATTERN LANGUAGES CXX)

set(SOURCES
    src/EEPROM.cpp
    src/FLASH.cpp
    src/MemoryContext.cpp
    src/main.cpp)

add_executable(main ${SOURCES})