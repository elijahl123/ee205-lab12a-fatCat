///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file cats.hpp
/// @version 1.0
///
/// @author Elijah Lopez <elijahl7@hawaii.edu>
/// @date   29_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CATS_HPP
#define EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CATS_HPP

#define MAX_CATS 1024
#define MAX_CAT_NAME_LEN 30
#define UNKNOWN_WEIGHT -1

/// Format a line for printing the members of a class
#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)


typedef float Weight;

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

class Cat {
private:
    char* name;
    enum gender gender;
    enum breed breed;
    bool isCatFixed;
    Weight weight;
public:
    Cat *next;
public:
    const char* getName() const;
    enum gender getGender() const;
    enum breed  getBreed() const;
    bool        getIsCatFixed() const;
    Weight      getWeight() const;

    void        setName(char *name);
    void        fixCat();
    void        setWeight(Weight weight);

public:
    Cat();
    Cat(char*, enum gender, enum breed, Weight);

    virtual ~Cat();

protected:
    void setGender(enum gender gender);
    void setBreed(enum breed newBreed);

public:
    bool print() const noexcept;
    bool validate() const noexcept;
};


#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CATS_HPP
