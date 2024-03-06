# cmake_minimum_required()
cmake_minimum_required(VERSION 3.0)

project(OOP LANGUAGES CXX)
# set(CMAKE_CURRENT_SOURCE_DIR src)
# set(CMAKE_CURRENT_BINARY_DIR build)
MESSAGE ("Source path: ${PROJECT_SOURCE_DIR}\nCmake current source: ${CMAKE_CURRENT_SOURCE_DIR}")
MESSAGE ("Binary path: ${PROJECT_BINARY_DIR}\nCmake current build: ${CMAKE_CURRENT_BINARY_DIR}")

# Set source files directory
set(INCLUDE_DIR src/Interfaces)
set(SOURCES
    ../src/ElectricCar/ElectricCar.cpp
    ../src/Car/Car.cpp
    ../src/HybridCar/HybridCar.cpp
    ../src/PetrolCar/PetrolCar.cpp
    ../src/main.cpp)

# include_directories("/src/Interfaces/Interfaces.h")
# Add executable
add_executable(main
    ${SOURCES})
# target_include_directories(main
#     PRIVATE
#     ../src/Interfaces)