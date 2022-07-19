cmake_minimum_required (VERSION 2.6)
project (sampleApp)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

include_directories("LL")
include_directories("utils")

add_subdirectory(LL)

add_executable(sampleApp main.c)

TARGET_LINK_LIBRARIES(sampleApp ll)