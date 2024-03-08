cmake_minimum_required(VERSION 3.0)
project(TestProject)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Define your executable
add_executable(TestProject main.cpp)

# Link your executable with OpenCV libraries
target_link_libraries(TestProject ${OpenCV_LIBS})
