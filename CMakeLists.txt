cmake_minimum_required(VERSION 3.16)

project(ee205_lab_08d_animal_farm_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(ee205_lab_08d_animal_farm_2 main.cpp config.hpp cats.cpp cats.hpp catDatabase.cpp catDatabase.hpp weight.cpp weight.hpp)
