///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Project - EE 205 - Spr 2022
///
/// @file updateCats.h
/// @version 1.0
///
/// @author Elijah Lopez <elijahl7@hawaii.edu>
/// @date   08_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <stdbool.h>

extern bool fixCat(unsigned long);

extern bool updateCatName(unsigned long, char *);

extern bool updateCatWeight(unsigned long, Weight);

extern bool updateCatCollar1(const unsigned long, const enum color);

extern bool updateCatCollar2(const unsigned long, const enum color);

extern bool updateLicense(const unsigned long, const unsigned long long);