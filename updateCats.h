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
#include "catDatabase.h"

extern bool fixCat(NumCats);

extern bool updateCatName(NumCats, char *);

extern bool updateCatWeight(NumCats, Weight);

extern bool updateCatCollar1(NumCats, enum color);

extern bool updateCatCollar2(NumCats, enum color);

extern bool updateLicense(NumCats, unsigned long long);