#include "reportCats.h"
#include "catDatabase.h"
#include <stdio.h>
#include <string.h>
#include "config.h"

void printCat(unsigned long index) {

    if (index > MAX_CATS) {
        fprintf(stderr, "%s: Bad cat [%lu]\n", PROGRAM_NAME, index);
        return;
    } else if (index < numCats) {
        printf("cat index = [%lu]  name=[%s]  gender=[%d]  breed=[%d]  isFixed=[%d]  weight=[%f]  collarColor1=[%d]  collarColor2=[%d]  license=[%llu]\n", index, cats[index].name, cats[index].gender, cats[index].breed, cats[index].isFixed, cats[index].weight, cats[index].collarColor1, cats[index].collarColor2, cats[index].license);
    } else {
        fprintf(stderr, "%s: Cat index out of bounds.\n", PROGRAM_NAME);
    }
}

void printAllCats() {
    for (size_t i = 0; i < numCats; ++i) {
        printf("cat index = [%lu]  name=[%s]  gender=[%d]  breed=[%d]  isFixed=[%d]  weight=[%f]  collarColor1=[%d]  collarColor2=[%d]  license=[%llu]\n", i, cats[i].name, cats[i].gender, cats[i].breed, cats[i].breed, cats[i].weight, cats[i].collarColor1, cats[i].collarColor2, cats[i].license);
    }
}

int findCat(char *name) {

    if (strlen(name) > MAX_NAME_LENGTH) {
        fprintf(stderr, "%s: Cat name is too long\n", PROGRAM_NAME);
        return -1;
    }

    for (int i = 0; i < MAX_CATS; ++i) {
        if (strncmp(name, cats[i].name, MAX_NAME_LENGTH) == 0) {
            return i;
        }
    }

    return -1;

}