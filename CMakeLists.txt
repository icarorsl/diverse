cmake_minimum_required(VERSION 3.0)
project(hello-vsc)

include_directories(src/core)

set(SOURCE src/main.cpp src/core/DSObject.h src/core/DSObject.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})