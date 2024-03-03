cmake_minimum_required(VERSION 3.10)
project(kubify VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for your project
include_directories("${PROJECT_SOURCE_DIR}/src")

include_directories(
    "/usr/local/include/kubernetes/include"
    "/usr/local/include/kubernetes/config"
    "/usr/local/include/kubernetes/api"
)


# Set all of the sources
set(SOURCES
    src/KubifyApp.cpp
    src/Graph.cpp
)

find_package(kubepp_lib REQUIRED)


# Add main application
add_executable(kubify src/main.cpp ${SOURCES})

# Enable testing with CTest
enable_testing()

# Find Google Test package (should work if GTest is installed properly)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Find the fmt library
find_package(fmt REQUIRED)
target_link_libraries(kubify fmt::fmt kubepp_lib::kubepp_lib)



# Add test executable
#add_executable(test_kubify tests/TestKubifyApp.cpp ${SOURCES})
#target_link_libraries(test_kubify ${GTEST_LIBRARIES} pthread fmt::fmt)


# Add test to the project to be run with 'make test' or 'ctest'
#add_test(NAME kubify_test COMMAND test_kubify)




# Add test executable
#add_executable(test_mock_reader tests/TestMockReader.cpp ${SOURCES})
#target_link_libraries(test_mock_reader ${GTEST_LIBRARIES} pthread fmt::fmt)

# Add test to the project to be run with 'make test' or 'ctest'
#add_test(NAME mock_reader_test COMMAND test_mock_reader)



install(TARGETS kubify DESTINATION bin)