#include "catDatabase.h"
#include <stdio.h>
#include "config.h"

NumCats numCats;

struct Cat cats[MAX_CATS];

NumCats initDatabase() {
    numCats = 0;
    return numCats;
}