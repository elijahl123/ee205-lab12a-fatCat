///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.h
/// @version 1.0
///
/// @author Elijah Lopez <elijahl7@hawaii.edu>
/// @date   08_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <stdio.h>
#include <stdbool.h>

#define BAD_CAT false
#define GOOD_CAT true

extern bool validateCatColorCombination(const unsigned long, const enum color, const enum color);

extern bool addCat(const char *, const enum gender, const enum breed, const bool, const float, const enum color, const enum color, const unsigned long long);