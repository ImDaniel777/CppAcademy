cmake_minimum_required(VERSION 3.16)
project(Min_max)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib )

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_library(nr_lib SHARED Cpp_Component.hpp Cpp_Component.cpp)

# add_executable(main
# ../main.cpp)

add_executable(Cpp_Component_Test
Cpp_Component_Test.cpp)


find_package(Boost CONFIG COMPONENTS system filesystem unit_test_framework REQUIRED)

target_link_libraries(Cpp_Component_Test 
  nr_lib
  Boost::unit_test_framework
  )

if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif() #CMAKE_BUILD_TYPE STREQUAL "Coverage"
