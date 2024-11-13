cmake_minimum_required(VERSION 3.21)
project(serialization
        VERSION 1.0
        DESCRIPTION "serialization library for C++"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_library(serialization INTERFACE include/serialization/Serialization.h)
target_include_directories(serialization INTERFACE rapidjson/include include)

if (PROJECT_IS_TOP_LEVEL)
    add_executable(serialization_example example/example.cpp)
    target_link_libraries(serialization_example PUBLIC serialization)
endif ()
