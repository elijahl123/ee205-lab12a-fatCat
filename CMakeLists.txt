cmake_minimum_required(VERSION 3.16)

project(ee205_lab_08d_animal_farm_1_to_clion C)

set(CMAKE_C_STANDARD 99)

add_executable(ee205_lab_08d_animal_farm_1_to_clion main.c config.h catDatabase.c catDatabase.h addCats.c addCats.h deleteCats.c deleteCats.h reportCats.c reportCats.h updateCats.c updateCats.h)
