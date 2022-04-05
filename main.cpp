#include "config.hpp"
#include "cats.hpp"
#include "catDatabase.hpp"
#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

int main() {
    cout << "Starting " << PROGRAM_NAME << endl;

    char lokiName[] = "Loki";
    Cat* loki =  new Cat(lokiName,  MALE,   PERSIAN,    (Weight) 1.0);
    catDatabase.addCat(loki);
    char miloName[] = "Milo";
    Cat* milo =  new Cat(miloName,  MALE,   MANX,       (Weight) 1.1);
    catDatabase.addCat(milo);
    char bellaName[] = "Bella";
    Cat* bella = new Cat(bellaName, FEMALE, MAINE_COON, (Weight) 1.2);
    catDatabase.addCat(bella);
    char kaliName[] = "Kali";
    Cat* kali =  new Cat(kaliName,  FEMALE, SHORTHAIR,  (Weight) 1.3);
    catDatabase.addCat(kali);
    char trinName[] = "Trin";
    Cat* trin =  new Cat(trinName,  FEMALE, MANX,       (Weight) 1.4);
    catDatabase.addCat(trin);
    char chiliName[] = "Chili";
    Cat* chili = new Cat(chiliName, MALE,   SHORTHAIR,  (Weight) 1.5);
    catDatabase.addCat(chili);
    catDatabase.printAllCats();
    catDatabase.deleteAllCats();
    catDatabase.printAllCats();

#ifndef NDEBUG
    // Verify that a cat created with Cat() has all the default values set
    Cat* defaultCat = new Cat();
    assert(strncmp(defaultCat->getName(), "", MAX_CAT_NAME_LEN) == 0);
    assert(defaultCat->getGender() == UNKNOWN_GENDER);
    assert(defaultCat->getBreed() == UNKNOWN_BREED);
    assert(defaultCat->getIsCatFixed() == false);
    assert(defaultCat->getWeight() == UNKNOWN_WEIGHT);
    // Verify that a cat created with Cat() is not valid
    assert(defaultCat->validate() == false);
    // Set name to nullptr
    assert(defaultCat->setName(nullptr) == false);
    // Set name to empty string
    assert(defaultCat->setName("") == false);
    // Set a 1 character name
    assert(defaultCat->setName("a") == true);
    // Set a MAX_CAT_NAME_LEN-1 name
    char testName[MAX_CAT_NAME_LEN];
    for (int i = 0; i < MAX_CAT_NAME_LEN - 1; i++) {
        testName[i] = 'a';
    }
    testName[MAX_CAT_NAME_LEN - 1] = '\0';
    assert(defaultCat->setName(testName) == true);
    // Set a MAX_CAT_NAME+1 name
    char testName2[MAX_CAT_NAME_LEN + 1];
    for (int i = 0; i < MAX_CAT_NAME_LEN + 1; i++) {
        testName2[i] = 'a';
    }
    testName2[MAX_CAT_NAME_LEN + 1] = '\0';
    assert(defaultCat->setName(testName2) == false);
    // Fix a default cat and check it before and after it’s fixed
    assert(defaultCat->getIsCatFixed() == false);
    assert(defaultCat->fixCat() == true);
    assert(defaultCat->getIsCatFixed() == true);
    // Set the weight to 0
    assert(defaultCat->setWeight(0) == false);
    // Set the weight to 1/1024
    assert(defaultCat->setWeight(1.0 / 1024) == true);
    // Verify that a cat created with Cat(...) is valid
    Cat* testCat = new Cat("testCat", MALE, PERSIAN, (Weight) 1.0);
    assert(testCat->validate() == true);
    // Verify that if you try to create a Cat(...) with any combination of UNKNOWN_GENDER, UNKNOWN_BREED or UNKNOWN_WEIGHT
    Cat* testCat2 = new Cat("testCat2", UNKNOWN_GENDER, UNKNOWN_BREED, UNKNOWN_WEIGHT);
    assert(testCat2->validate() == false);
    // Find a cat by name
    catDatabase.addCat(testCat);
    assert(catDatabase.findCatByName("testCat") == 0);
    // Find a cat by name that doesn’t exist
    assert(catDatabase.findCatByName("testCat2") == -1);
    // Delete testCat
    assert(catDatabase.deleteCat(testCat) == true);

#endif

    cout << "Done with " << PROGRAM_NAME << endl;
    return (EXIT_SUCCESS);
}
