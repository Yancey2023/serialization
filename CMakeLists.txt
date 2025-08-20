cmake_minimum_required(VERSION 3.21)
project(serialization
        VERSION 1.0
        DESCRIPTION "serialization library for C++"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-unused-parameter")
elseif (MSVC)
    add_compile_options("/W4")
    add_compile_options("/wd4100")
    add_compile_options("/utf-8")
    add_compile_options("/Zc:__cplusplus")
    add_compile_options("/permissive-")
endif ()

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
