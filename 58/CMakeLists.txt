cmake_minimum_required(VERSION 3.28)
project(Ceres_test)

set(CMAKE_CXX_STANDARD 17)

find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})

add_library(lib common.cpp)

add_executable(Ceres_test bundle_adjustment_ceres.cpp)
target_link_libraries(Ceres_test lib ${CERES_LIBRARIES})