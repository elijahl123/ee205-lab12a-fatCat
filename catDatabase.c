#include "catDatabase.h"
#include <stdio.h>
#include "config.h"

size_t numCats;

struct Cat cats[MAX_CATS];

size_t initDatabase() {
    numCats = 0;
    return numCats;
}