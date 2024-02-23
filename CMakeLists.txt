cmake_minimum_required(VERSION 3.10)
project(kubify VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories("${PROJECT_SOURCE_DIR}/src")

# Add main application
add_executable(kubify src/main.cpp src/KubifyApp.cpp)

# Google Test for unit tests
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Test executable
add_executable(test_kubify tests/TestKubifyApp.cpp src/KubifyApp.cpp)
target_link_libraries(test_kubify ${GTEST_LIBRARIES} pthread)

# Add test
add_test(NAME kubify_test COMMAND test_kubify)
