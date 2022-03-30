#include "catDatabase.h"
#include "addCats.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "config.h"

bool validateCatColorCombination(const unsigned long index, const enum color collarColor1, const enum color collarColor2) {
    if (cats[index].collarColor1 == collarColor1 && cats[index].collarColor2 == collarColor2) {
        return true;
    }
    return false;
}

bool addCat(const char *name, const enum gender gender, const enum breed breed, bool isFixed, const Weight weight, const enum color collarColor1, const enum color collarColor2, const unsigned long long license) {
    // returns index of the cat in the database
    if (numCats >= MAX_CATS) {
        fprintf(stderr, "%s: You have reached the maximum amount of cats!\n", PROGRAM_NAME);
        return BAD_CAT;
    }

    if (strlen(name) > MAX_NAME_LENGTH || strlen(name) == 0) {
        fprintf(stderr, "%s: The name of a cat must between 1 and 30 characters.\n", PROGRAM_NAME);
        return BAD_CAT;
    }

    for (size_t i = 0; i < numCats; ++i) {
        if (strncmp(cats[i].name, name, MAX_NAME_LENGTH) == 0) {
            fprintf(stderr, "%s: A cat with this name already exists.\n", PROGRAM_NAME);
            return BAD_CAT;
        }
        if (cats[i].license == license) {
            fprintf(stderr, "%s: A cat with this license already exists.\n", PROGRAM_NAME);
            return BAD_CAT;
        }
        if (validateCatColorCombination(i, collarColor1, collarColor2)) {
            fprintf(stderr, "%s: A cat with this collar combination already exists.\n", PROGRAM_NAME);
            return BAD_CAT;
        }
    }

    if (weight <= 0) {
        fprintf(stderr, "%s: A cat's weight must be greater than or equal to 0.\n", PROGRAM_NAME);
        return BAD_CAT;
    }


    if (collarColor1 == collarColor2) {
        fprintf(stderr, "%s: A cat must have two different collar colors.\n", PROGRAM_NAME);
        return BAD_CAT;
    }


    struct Cat newCat = {
            .gender = gender,
            .breed = breed,
            .isFixed = isFixed,
            .weight = weight,
            .collarColor1 = collarColor1,
            .collarColor2 = collarColor2,
            .license = license
    };
    strncpy(newCat.name, name, MAX_NAME_LENGTH);
    cats[numCats] = newCat;

    ++numCats;

    return GOOD_CAT;
}