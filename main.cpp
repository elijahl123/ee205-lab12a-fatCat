#include "config.hpp"
#include "cats.hpp"
#include "catDatabase.hpp"
#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

int main() {
    cout << "Starting " << PROGRAM_NAME << endl;

    Cat* loki =  new Cat("Loki",  MALE,   PERSIAN,    (Weight) 1.0);
    catDatabase.addCat(loki);
    Cat* milo =  new Cat("Milo",  MALE,   MANX,       (Weight) 1.1);
    catDatabase.addCat(milo);
    Cat* bella = new Cat("Bella", FEMALE, MAINE_COON, (Weight) 1.2);
    catDatabase.addCat(bella);
    Cat* kali =  new Cat("Kali",  FEMALE, SHORTHAIR,  (Weight) 1.3);
    catDatabase.addCat(kali);
    Cat* trin =  new Cat("Trin",  FEMALE, MANX,       (Weight) 1.4);
    catDatabase.addCat(trin);
    Cat* chili = new Cat("Chili", MALE,   SHORTHAIR,  (Weight) 1.5);
    catDatabase.addCat(chili);
    catDatabase.printAllCats();
    catDatabase.deleteAllCats();
    catDatabase.printAllCats();

    cout << "Done with " << PROGRAM_NAME << endl;
    return (EXIT_SUCCESS);
}
