#include "config.hpp"
#include "weight.hpp"
#include "cats.hpp"
#include "catDatabase.hpp"
#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

int main() {
    cout << "Starting " << PROGRAM_NAME << endl;

    weight::Weight* w = new weight::Weight(100.0, weight::Weight::POUND, 200.0);
    weight::Weight* w2 = new weight::Weight(115.0, weight::Weight::POUND, 200.0);
    weight::Weight* w3 = new weight::Weight(120.0, weight::Weight::POUND, 200.0);

    w->dump();
    w2->dump();
    w3->dump();

    delete w;
    delete w2;
    delete w3;

#ifndef NDEBUG
    cout << "Starting tests for " << PROGRAM_NAME << endl;

    // Test for default constructor
    weight::Weight* testWeight = new weight::Weight();
    assert(testWeight->validate() == false);
    assert(testWeight->isWeightKnown() == false);
    assert(testWeight->hasMaxWeight() == false);
    delete testWeight;
    // Test for constructor with weight and unit
    testWeight = new weight::Weight(100.0, weight::Weight::POUND);
    assert(testWeight->validate() == true);
    assert(testWeight->getWeight() == 100.0);
    assert(testWeight->getUnitOfWeight() == weight::Weight::POUND);
    assert(testWeight->isWeightKnown() == true);
    assert(testWeight->hasMaxWeight() == false);
    delete testWeight;
    // Test for constructor with weight, max weight, and unit
    testWeight = new weight::Weight(100.0, weight::Weight::POUND, 200.0);
    assert(testWeight->validate() == true);
    assert(testWeight->getWeight() == 100.0);
    assert(testWeight->getUnitOfWeight() == weight::Weight::POUND);
    assert(testWeight->getMaxWeight() == 200.0);
    assert(testWeight->isWeightKnown() == true);
    assert(testWeight->hasMaxWeight() == true);
    // Test testWeight for unit conversion
    testWeight->setWeight(testWeight->getWeight(), weight::Weight::KILO);
    assert(testWeight->getWeight() == (float) (100.0 * weight::Weight::KILOS_IN_A_POUND));
    testWeight->setWeight(100.0, weight::Weight::POUND);
    // Test the == operator
    weight::Weight* testWeight2 = new weight::Weight(100.0, weight::Weight::POUND, 200.0);
    assert(*testWeight == *testWeight2);
    // Test the != operator
    weight::Weight* testWeight3 = new weight::Weight(105.0, weight::Weight::POUND, 200.0);
    assert(*testWeight != *testWeight3);
    // Test the < operator
    weight::Weight* testWeight4 = new weight::Weight(105.0, weight::Weight::POUND, 200.0);
    assert(*testWeight < *testWeight4);
    // Test the = operator
    weight::Weight* testWeight5 = new weight::Weight(105.0, weight::Weight::POUND, 200.0);
    *testWeight = *testWeight5;
    assert(*testWeight == *testWeight5);
    // Test the += operator
    weight::Weight* testWeight6 = new weight::Weight(100.0, weight::Weight::POUND, 200.0);
    *testWeight6 += 10.0;
    assert(testWeight6->getWeight() == 110.0);
    // Delete all testWeight objects
    delete testWeight;
    delete testWeight2;
    delete testWeight3;
    delete testWeight4;
    delete testWeight5;
    delete testWeight6;

    cout << "Finished tests for " << PROGRAM_NAME << endl;
#endif

    cout << "Done with " << PROGRAM_NAME << endl;
    return (EXIT_SUCCESS);
}
