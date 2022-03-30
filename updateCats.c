#include "catDatabase.h"
#include "updateCats.h"
#include "addCats.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "config.h"
#include "reportCats.h"


bool fixCat(unsigned long index) {
    if (index >= numCats) {
        fprintf(stderr, "%s: Index out of range\n", PROGRAM_NAME);
        return false;
    }

    cats[index].isFixed = true;
    return true;
}

bool updateCatName(unsigned long index, char *newName) {
    if (index >= numCats) {
        fprintf(stderr, "%s: Index out of range\n", PROGRAM_NAME);
        return false;
    }
    if (strlen(newName) > MAX_NAME_LENGTH) {
        fprintf(stderr, "%s: Name is too long. Must be between 1-30 characters.\n", PROGRAM_NAME);
        return false;
    }
    if (strlen(newName) == 0) {
        fprintf(stderr, "%s: Name must not be empty.\n", PROGRAM_NAME);
        return false;
    }

    for (size_t i = 0; i < numCats; ++i) {
        if (strncmp(cats[i].name, newName, MAX_NAME_LENGTH) == 0) {
            fprintf(stderr, "%s: Cat with this name already exists.\n", PROGRAM_NAME);
            return false;
        }
    }

    strncpy(cats[index].name, newName, MAX_NAME_LENGTH);
    return true;
}

bool updateCatWeight(unsigned long index, Weight newWeight) {
    if (index >= numCats) {
        fprintf(stderr, "%s: Index out of range\n", PROGRAM_NAME);
        return false;
    }

    if (newWeight <= 0) {
        fprintf(stderr, "%s: A cat's weight must be greater than or equal to 0.\n", PROGRAM_NAME);
        return false;
    }

    cats[index].weight = newWeight;
    return true;
}

bool updateCatCollar1(const unsigned long index, const enum color collarColor1) {
    if (index >= numCats) {
        fprintf(stderr, "%s: Index out of range\n", PROGRAM_NAME);
        return false;
    }
    for (size_t i = 0; i < numCats && i != index; ++i) {
        if (collarColor1 == cats[i].collarColor1 && cats[index].collarColor2 == cats[i].collarColor2) {
            fprintf(stderr, "%s: A cat with this collar combination already exists.\n", PROGRAM_NAME);
            printf("%zu\n", i);
            return false;
        }
    }
    cats[index].collarColor1 = collarColor1;
    return true;
}

bool updateCatCollar2(const unsigned long index, const enum color collarColor2) {
    if (index >= numCats) {
        fprintf(stderr, "%s: Index out of range\n", PROGRAM_NAME);
        return false;
    }
    for (size_t i = 0; i < numCats && i != index; ++i) {
        if (collarColor2 == cats[i].collarColor2 && cats[index].collarColor1 == cats[i].collarColor1) {
            fprintf(stderr, "%s: A cat with this collar combination already exists.\n", PROGRAM_NAME);
            printf("%zu\n", i);
            return false;
        }
    }
    cats[index].collarColor2 = collarColor2;
    return true;
}

bool updateLicense(const unsigned long index, const unsigned long long license) {
    if (index >= numCats) {
        fprintf(stderr, "%s: Index out of range\n", PROGRAM_NAME);
        return false;
    }
    for (size_t i = 0; i < numCats; ++i) {
        if (cats[i].license == license) {
            fprintf(stderr, "%s: A cat with this license already exists.\n", PROGRAM_NAME);
            return false;
        }
    }
    cats[index].license = license;
    return true;
}
