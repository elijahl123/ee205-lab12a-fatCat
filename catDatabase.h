///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Elijah Lopez <elijahl7@hawaii.edu>
/// @date   08_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <stdio.h>
#include <stdbool.h>

#define MAX_CATS 20
#define MAX_NAME_LENGTH 30

enum gender {
    UNKNOWN_GENDER,
    MALE,
    FEMALE
};

enum breed {
    UNKNOWN_BREED,
    MAINE_COON,
    MANX,
    SHORTHAIR,
    PERSIAN,
    SPHYNX
};

enum color {
    BLACK,
    WHITE,
    RED,
    BLUE,
    GREEN,
    PINK
};

struct Cat {
    char                name[MAX_NAME_LENGTH]   ;
    enum gender         gender                  ;
    enum breed          breed                   ;
    bool                isFixed                 ;
    float               weight                  ;
    enum color          collarColor1            ;
    enum color          collarColor2            ;
    unsigned long long  license                 ;
};

extern struct Cat cats[MAX_CATS];

extern size_t numCats;

extern size_t initDatabase();
