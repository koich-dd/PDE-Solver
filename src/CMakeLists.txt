cmake_minimum_required(VERSION 3.6)
project(PDE-Solver)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
include_directories("../eigen-3.3.9")
add_executable(main main.cpp Coordinate.cpp Solver.cpp Jacobi.cpp GaussSeidel.cpp)
