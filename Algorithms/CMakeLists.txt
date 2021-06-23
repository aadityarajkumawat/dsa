cmake_minimum_required(VERSION 3.19)
project(Algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(Algorithms main.cpp two_number_sum/two_number_sum.cpp two_number_sum/two_number_sum.h validate-sequence/ValidateSequenceProblem.cpp validate-sequence/ValidateSequenceProblem.h)