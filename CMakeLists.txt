cmake_minimum_required(VERSION 3.21)
project(serialization
        VERSION 1.0
        DESCRIPTION "serialization library for C++"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_library(serialization INTERFACE include/serialization/serialization.h)
target_include_directories(serialization INTERFACE rapidjson/include include)
add_library(serialization::serialization ALIAS serialization)

add_library(serialization_no_filesystem INTERFACE include/serialization/serialization.h)
target_include_directories(serialization_no_filesystem INTERFACE rapidjson/include include)
target_compile_definitions(serialization_no_filesystem INTERFACE SERIALIZATION_NO_FILESYSTEM)
add_library(serialization::serialization_no_filesystem ALIAS serialization_no_filesystem)

if (PROJECT_IS_TOP_LEVEL)
    add_library(serialization_example example/example.cpp)
    target_link_libraries(serialization_example PUBLIC serialization)
endif ()
