cmake_minimum_required(VERSION 3.16)
project(EigenPractice VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
include_directories(../../deps/eigen3)

add_executable(EigenPractice zero_cost_data_pass.cpp utils.h)