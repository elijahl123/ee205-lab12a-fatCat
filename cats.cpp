//
// Created by Elijah Lopez on 3/29/22.
//

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cassert>
#include "cats.hpp"
#include "config.hpp"

using namespace std;

Cat::Cat() {
    name = new char[MAX_CAT_NAME_LEN];
    gender = UNKNOWN_GENDER;
    breed = UNKNOWN_BREED;
    isCatFixed = false;
    weight = UNKNOWN_WEIGHT;
}

Cat::Cat(char *newName, enum gender newGender, enum breed newBreed, Weight newWeight) {
    Cat::setName(newName);
    Cat::setWeight(newWeight);
    Cat::setGender(newGender);
    Cat::setBreed(newBreed);
    isCatFixed = false;
    next = nullptr;
}

const char *Cat::getName() const {
    return name;
}

gender Cat::getGender() const {
    return gender;
}

breed Cat::getBreed() const {
    return breed;
}

bool Cat::getIsCatFixed() const {
    return isCatFixed;
}

Weight Cat::getWeight() const {
    return weight;
}

bool Cat::setName(char *newName) {
    if (newName == nullptr) {
        cout << PROGRAM_NAME << ": newName cannot be nullptr" << endl;
        return false;
    } else if (strcmp(newName, "") == 0) {
        cout << PROGRAM_NAME << ": newName cannot be empty" << endl;
        return false;
    } else if (strlen(newName) > MAX_CAT_NAME_LEN) {
        cout << PROGRAM_NAME << ": newName cannot be longer than " << MAX_CAT_NAME_LEN << " characters" << endl;
        return false;
    }
    name = newName;
    return true;
}

bool Cat::setGender(enum gender newGender) {
    Cat::gender = newGender;
    return true;
}

bool Cat::setBreed(enum breed newBreed) {
    Cat::breed = newBreed;
    return true;
}

bool Cat::fixCat() {
    Cat::isCatFixed = true;
    return true;
}

bool Cat::setWeight(Weight newWeight) {
    if (newWeight <= 0) {
        cout << PROGRAM_NAME << ": newWeight must be greater than 0" << endl;
        Cat::weight = UNKNOWN_WEIGHT;
        return false;
    }
    Cat::weight = newWeight;
    return true;
}

Cat::~Cat() {
    delete[] name;
    Cat::setGender(UNKNOWN_GENDER);
    Cat::setBreed(UNKNOWN_BREED);
    Cat::isCatFixed = false;
    Cat::weight = 0;
}

bool Cat::print() const noexcept {
    assert(validate());
    cout << setw(80) << setfill('=') << "" << endl;
    cout << setfill(' ');
    cout << left;
    cout << boolalpha;
    FORMAT_LINE("Cat", "name") << Cat::getName() << endl;
    FORMAT_LINE("Cat", "gender") << Cat::getGender() << endl;
    FORMAT_LINE("Cat", "breed") << Cat::getBreed() << endl;
    FORMAT_LINE("Cat", "isFixed") << Cat::getIsCatFixed() << endl;
    FORMAT_LINE("Cat", "weight") << Cat::getWeight() << endl;
    return true;
}

bool Cat::validate() const noexcept {
    if (Cat::getName() == nullptr) {
        cout << PROGRAM_NAME << ": Cat name cannot be nullptr" << endl;
        return false;
    } else if (strcmp(Cat::getName(), "") == 0) {
        cout << PROGRAM_NAME << ": Cat name cannot be empty" << endl;
        return false;
    } else if (strlen(Cat::getName()) > MAX_CAT_NAME_LEN) {
        cout << PROGRAM_NAME << ": Cat name cannot be longer than " << MAX_CAT_NAME_LEN << " characters" << endl;
        return false;
    } else if (Cat::getGender() == UNKNOWN_GENDER) {
        cout << PROGRAM_NAME << ": Cat gender must be known" << endl;
        return false;
    } else if (Cat::getBreed() == UNKNOWN_BREED) {
        cout << PROGRAM_NAME << ": Cat breed must be known" << endl;
        return false;
    } else if (Cat::getWeight() <= 0) {
        cout << PROGRAM_NAME << ": newWeight must be greater than 0" << endl;
        return false;
    }
    return true;
}






