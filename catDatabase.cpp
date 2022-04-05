//
// Created by Elijah Lopez on 4/5/22.
//

#include "catDatabase.hpp"
#include "config.hpp"
#include <iostream>
#include <cstring>

using namespace std;

CatDatabase::CatDatabase() {
    catDatabaseHeadPointer = nullptr;
}

CatDatabase::~CatDatabase() {
    catDatabaseHeadPointer = nullptr;
}

bool CatDatabase::validateDatabase() const {
    bool isValid = true;
    Cat* currentCat = catDatabaseHeadPointer;
    while (currentCat != nullptr) {
        if (!currentCat->validate()) {
            isValid = false;
        }
        currentCat = currentCat->next;
    }
    if (!isValid) {
        cout << PROGRAM_NAME << ": Database is invalid." << endl;
    }
    return isValid;
}

// run validateDatabase() before and after this function
void CatDatabase::addCat(Cat *newCat) {
    if (!validateDatabase()) {
        return;
    }
    if (!newCat->validate()) {
        cout << PROGRAM_NAME << ": Error: Cat is invalid" << endl;
        return;
    }
    if (catDatabaseHeadPointer == nullptr) {
        catDatabaseHeadPointer = newCat;
    } else {
        Cat *currentCat = catDatabaseHeadPointer;
        while (currentCat->next != nullptr) {
            currentCat = currentCat->next;
        }
        currentCat->next = newCat;
    }
    if (!validateDatabase()) {
        return;
    }
}

void CatDatabase::deleteCat(Cat *catToDelete) {
    if (!validateDatabase()) {
        return;
    }
    if (catToDelete == catDatabaseHeadPointer) {
        catDatabaseHeadPointer = catToDelete->next;
    } else {
        Cat *currentCat = catDatabaseHeadPointer;
        while (currentCat->next != catToDelete) {
            currentCat = currentCat->next;
        }
        currentCat->next = catToDelete->next;
    }
    if (!validateDatabase()) {
        return;
    }
}

void CatDatabase::deleteAllCats() {
    if (!validateDatabase()) {
        return;
    }
    Cat *currentCat = catDatabaseHeadPointer;
    while (currentCat != nullptr) {
        Cat *nextCat = currentCat->next;
        deleteCat(currentCat);
        currentCat = nextCat;
    }
    catDatabaseHeadPointer = nullptr;
    if (!validateDatabase()) {
        return;
    }
}

int CatDatabase::findCatByName(const char* catName) {
    if (!validateDatabase()) {
        return -1;
    }
    Cat *currentCat = catDatabaseHeadPointer;
    int catIndex = 0;
    while (currentCat != nullptr) {
        if (strncmp(currentCat->getName(), catName, MAX_CAT_NAME_LEN) == 0) {
            return catIndex;
        }
        currentCat = currentCat->next;
        catIndex++;
    }
    return -1;
}

void CatDatabase::printAllCats() {
    if (!validateDatabase()) {
        return;
    }
    Cat *currentCat = catDatabaseHeadPointer;
    while (currentCat != nullptr) {
        currentCat->print();
        currentCat = currentCat->next;
    }
}

CatDatabase catDatabase = CatDatabase();


