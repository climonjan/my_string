cmake_minimum_required(VERSION 3.16.3)

project(BKPD_BREAKS_SLEEVE)

set(CMAKE_CXX_STANDARD 17)
set(SOURCES *.cpp)
set(TARGET main)
set(LIB zmq)

add_executable(${TARGET} ${SOURCES})

target_include_directories(${TARGET} PRIVATE ".")

target_link_libraries(${TARGET} ${LIB})