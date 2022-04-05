///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file catDatabase.hpp
/// @version 1.0
///
/// @author Elijah Lopez <elijahl7@hawaii.edu>
/// @date   05_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef EE205_LAB_08D_ANIMAL_FARM_2_CATDATABASE_HPP
#define EE205_LAB_08D_ANIMAL_FARM_2_CATDATABASE_HPP


#include <iostream>
#include "cats.hpp"

class CatDatabase {
public:
    Cat* catDatabaseHeadPointer;
    CatDatabase();
    ~CatDatabase();

    bool validateDatabase() const;
    void addCat(Cat* newCat);
    bool deleteCat(Cat* catToDelete);
    void deleteAllCats();
    int findCatByName(const char* catName);
    void printAllCats();
};

extern CatDatabase catDatabase;

#endif //EE205_LAB_08D_ANIMAL_FARM_2_CATDATABASE_HPP
