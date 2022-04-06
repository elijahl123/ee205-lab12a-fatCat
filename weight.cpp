//
// Created by Elijah Lopez on 4/5/22.
//

#include "weight.hpp"
#include <iostream>
#include <cassert>
#include <iomanip>

using namespace std;
using namespace weight;

const float Weight::UNKNOWN_WEIGHT = -1.0;
const float Weight::KILOS_IN_A_POUND = 0.453592;
const float Weight::SLUGS_IN_A_POUND = 0.031051;
const string Weight::POUND_LABEL = "Pound";
const string Weight::KILO_LABEL = "Kilo";
const string Weight::SLUG_LABEL = "Slug";


void Weight::setMaxWeight(float newMaxWeight) {
    assert(isWeightValid(newMaxWeight));
    maxWeight = newMaxWeight;
    bHasMax = true;
}

Weight::Weight() noexcept = default;

Weight::Weight(float newWeight) {
    setWeight(newWeight);
    assert(validate());
    bIsKnown = true;
}

Weight::Weight(enum UnitOfWeight newUnitOfWeight) noexcept {
    unitOfWeight = newUnitOfWeight;
}

Weight::Weight(float newWeight, enum UnitOfWeight newUnitOfWeight) : Weight(newWeight) {
    unitOfWeight = newUnitOfWeight;
    assert(validate());
}

Weight::Weight(float newWeight, float newMaxWeight): Weight(newWeight) {
    setMaxWeight(newMaxWeight);
    assert(validate());
    bHasMax = true;
}

Weight::Weight(enum UnitOfWeight newUnitOfWeight, float newMaxWeight) : Weight(newUnitOfWeight) {
    setMaxWeight(newMaxWeight);
    assert(validate());
    bHasMax = true;
}

Weight::Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight): Weight(newWeight, newUnitOfWeight) {
    setMaxWeight(newMaxWeight);
    assert(validate());
    bHasMax = true;
}

Weight::~Weight() noexcept {
    weight = 0.0;
    maxWeight = 0.0;
    unitOfWeight = UnitOfWeight::POUND;
    bIsKnown = false;
    bHasMax = false;
}

bool Weight::isWeightKnown() const noexcept {
    return weight != 0;
}

bool Weight::hasMaxWeight() const noexcept {
    return maxWeight != 0;
}

float Weight::getWeight() const noexcept {
    if (Weight::isWeightKnown()) {
        return weight;
    } else {
        return UNKNOWN_WEIGHT;
    }
}

float Weight::getWeight(enum UnitOfWeight newUnitOfWeight) const noexcept {
    if (Weight::isWeightKnown()) {
        return convertWeight(weight, unitOfWeight, newUnitOfWeight);
    } else {
        return UNKNOWN_WEIGHT;
    }
}

float Weight::getMaxWeight() const noexcept {
    if (Weight::hasMaxWeight()) {
        return maxWeight;
    } else {
        return UNKNOWN_WEIGHT;
    }
}

Weight::UnitOfWeight Weight::getUnitOfWeight() const noexcept {
    return unitOfWeight;
}

void Weight::setWeight(float newWeight) {
    if (newWeight == 0) {
        throw out_of_range("Weight cannot be 0");
    } else if (bHasMax && newWeight > maxWeight) {
        throw out_of_range("Weight cannot be greater than max weight");
    } else {
        weight = newWeight;
        bIsKnown = true;
    }
}

void Weight::setWeight(float newWeight, enum UnitOfWeight newUnitOfWeight) {
    if (newWeight == 0) {
        throw out_of_range("Weight cannot be 0");
    } else if (bHasMax && newWeight > maxWeight) {
        throw out_of_range("Weight cannot be greater than max weight");
    } else {
        weight = convertWeight(newWeight, unitOfWeight, newUnitOfWeight);
    }
}

bool Weight::isWeightValid(float newWeight) const noexcept {
    return newWeight > 0;
}

bool Weight::validate() const noexcept {
    bool bIsValid;
    if (bIsKnown && isWeightValid(weight)) {
        bIsValid = true;
    } else if (bHasMax && isWeightValid(maxWeight)) {
        bIsValid = true;
    } else {
        bIsValid = false;
    }
    return bIsValid;
}

void Weight::dump() const noexcept {
    assert(validate());
    cout << setw(80) << setfill('=') << "" << endl;
    cout << setfill(' ');
    cout << left;
    cout << boolalpha;
    FORMAT_LINE("Weight", "this") << this << endl;
    FORMAT_LINE("Weight", "isKnown") << Weight::isWeightKnown() << endl;
    FORMAT_LINE("Weight", "weight") << Weight::getWeight() << endl;
    FORMAT_LINE("Weight", "unitOfWeight") << Weight::getUnitOfWeight() << endl;
    FORMAT_LINE("Weight", "hasMax") << Weight::hasMaxWeight() << endl;
    FORMAT_LINE("Weight", "maxWeight") << Weight::getMaxWeight() << endl;
}

bool Weight::operator==(const Weight &rhs_Weight) const {
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight == rhs_weight;
}

bool Weight::operator!=(const Weight &rhs) const {
    return !(rhs == *this);
}

bool Weight::operator<(const Weight &rhs_Weight) const {
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight < rhs_weight;
}

Weight& Weight::operator=(const Weight &rhs) {
    if (this != &rhs) {
        bIsKnown = rhs.bIsKnown;
        weight = rhs.weight;
        unitOfWeight = rhs.unitOfWeight;
        maxWeight = rhs.maxWeight;
        bHasMax = rhs.bHasMax;
    }
    return *this;
}

Weight &Weight::operator+=(float rhs_addToWeight) {
    if (bIsKnown) {
        if (rhs_addToWeight == 0) {
            throw out_of_range("Weight cannot be 0");
        } else if (rhs_addToWeight > maxWeight) {
            throw out_of_range("Weight cannot be greater than max weight");
        } else {
            weight += rhs_addToWeight;
        }
    } else {
        throw out_of_range("Weight is unknown");
    }
    return *this;
}

std::ostream& weight::operator<<( ostream& lhs_stream, const Weight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND: return lhs_stream << Weight::POUND_LABEL ;
        case Weight::KILO:  return lhs_stream << Weight::KILO_LABEL ;
        case Weight::SLUG:  return lhs_stream << Weight::SLUG_LABEL ;
        default:
            throw out_of_range( "The unit can’t be mapped to a string" );
    }
}

float Weight::fromKilogramToPound(float kilogram) noexcept {
    return (float) (kilogram / KILOS_IN_A_POUND);
}

float Weight::fromPoundToKilogram(float pound) noexcept {
    return (float) (pound * KILOS_IN_A_POUND);
}

float Weight::fromSlugToPound(float slug) noexcept {
    return (float) (slug / SLUGS_IN_A_POUND);
}

float Weight::fromPoundToSlug(float pound) noexcept {
    return (float) (pound * SLUGS_IN_A_POUND);
}

float Weight::convertWeight(float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept {
    if (fromUnit == toUnit) {
        return fromWeight;
    } else if (fromUnit == UnitOfWeight::KILO && toUnit == UnitOfWeight::POUND) {
        return Weight::fromKilogramToPound(fromWeight);
    } else if (fromUnit == UnitOfWeight::POUND && toUnit == UnitOfWeight::KILO) {
        return Weight::fromPoundToKilogram(fromWeight);
    } else if (fromUnit == UnitOfWeight::SLUG && toUnit == UnitOfWeight::POUND) {
        return Weight::fromSlugToPound(fromWeight);
    } else if (fromUnit == UnitOfWeight::POUND && toUnit == UnitOfWeight::SLUG) {
        return Weight::fromPoundToSlug(fromWeight);
    } else {
        return UNKNOWN_WEIGHT;
    }
}
