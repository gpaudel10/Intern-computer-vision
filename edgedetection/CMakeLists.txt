cmake_minimum_required(VERSION 3.20)

project(edgedetection)
set(CMAKE_CXX_STANDARD 17)
add_executable(output edge.cpp)

find_package(OpenCV CONFIG REQUIRED)

target_include_directories(output PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(output PRIVATE ${OpenCV_LIBS})