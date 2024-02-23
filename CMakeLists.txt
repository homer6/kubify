cmake_minimum_required(VERSION 3.10)
project(kubify VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for your project
include_directories("${PROJECT_SOURCE_DIR}/src")

# Set all of the sources
set(SOURCES
    src/KubifyApp.cpp
    src/Graph.cpp
)


# Add main application
add_executable(kubify src/main.cpp ${SOURCES})

# Enable testing with CTest
enable_testing()

# Find Google Test package (should work if GTest is installed properly)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})



# Add test executable
add_executable(test_kubify tests/TestKubifyApp.cpp ${SOURCES})
target_link_libraries(test_kubify ${GTEST_LIBRARIES} pthread)

# Add test to the project to be run with 'make test' or 'ctest'
add_test(NAME kubify_test COMMAND test_kubify)




# Add test executable
add_executable(test_mock_reader tests/TestMockReader.cpp ${SOURCES})
target_link_libraries(test_mock_reader ${GTEST_LIBRARIES} pthread)

# Add test to the project to be run with 'make test' or 'ctest'
add_test(NAME mock_reader_test COMMAND test_mock_reader)