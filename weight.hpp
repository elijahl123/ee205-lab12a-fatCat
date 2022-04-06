///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file weight.hpp
/// @version 1.0
///
/// @author Elijah Lopez <elijahl7@hawaii.edu>
/// @date   05_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef EE205_LAB12A_FATCAT_WEIGHT_HPP
#define EE205_LAB12A_FATCAT_WEIGHT_HPP

#include <iostream>

#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

class Weight {
public:
    enum UnitOfWeight { POUND, KILO, SLUG };
private:
    bool bIsKnown = false;
    bool bHasMax = false;
    UnitOfWeight unitOfWeight = POUND;
    float weight{};
    float maxWeight{};

    void setMaxWeight(float newMaxWeight);
public:
    // A default weight
    Weight() noexcept;
    // A weight with a value
    Weight(float newWeight);
    // A weight with a UnitOfWeight. Once UnitOfWeight is set, it can't be changed.
    Weight(UnitOfWeight newUnitOfWeight) noexcept;
    // A weight with a value and UnitOfWeight. Once UnitOfWeight is set, it can't be changed.
    Weight(float newWeight, UnitOfWeight newUnitOfWeight);
    // A weight with a value and a maximum weight. Once maximum weight is set, it can't be changed.
    Weight(float newWeight, float newMaxWeight);
    // A weight with a UnitOfWeight and a maximum weight. Once UnitOfWeight and maximum weight are set, they can't be changed. Once maximum weight is set, it can't be changed.
    Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight);
    // A weight with a value, UnitOfWeight and a maximum weight. Once UnitOfWeight and maximum weight are set, they can't be changed. Once maximum weight is set, it can't be changed.
    Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight);

    // true if the weight is known
    bool isWeightKnown() const noexcept;
    // true if the maximum weight is set
    bool hasMaxWeight() const noexcept;
    // Get the weight in the Weight's units. If the weight is not known, return UNKNOWN_WEIGHT.
    float getWeight() const noexcept;
    // Get the weight in a specified unit.
    float getWeight(UnitOfWeight newUnitOfWeight) const noexcept;
    // Get the maximum weight in the Weight's units. If the maximum weight is not set, return UNKNOWN_WEIGHT.
    float getMaxWeight() const noexcept;
    // Get the UnitOfWeight for this Weight.
    UnitOfWeight getUnitOfWeight() const noexcept;

    /// Set the weight.
    /// \exception out_of_range	When the weight is <=0 or > maxWeight (if maxWeight is set)
    void setWeight(float newWeight);
    /// Set the weight as a specified unit.
    void setWeight(float newWeight, UnitOfWeight newUnitOfWeight);
    /// Check the weight.
    /// Verify that checkWeight > 0
    /// If bHasMax, then checkWeight must be <= maxWeight
    bool isWeightValid(float newWeight) const noexcept;

    /// Check Weight to ensure it's healthy.
    bool validate() const noexcept;
    /// Print the weight class.
    void dump() const noexcept;

    bool operator==(const Weight &rhs_Weight) const;
    bool operator<(const Weight &rhs_Weight) const;
    bool operator!=(const Weight &rhs) const;

    Weight &operator=(const Weight &rhs_Weight);
    Weight& operator+=( float rhs_addToWeight );

    friend std::ostream &operator<<(std::ostream &lhs_stream, Weight::UnitOfWeight rhs_UnitOfWeight);

public:
    static const float UNKNOWN_WEIGHT;
    static const float KILOS_IN_A_POUND;
    static const float SLUGS_IN_A_POUND;
    static const std::string POUND_LABEL;
    static const std::string KILO_LABEL;
    static const std::string SLUG_LABEL;

    static float fromKilogramToPound(float kilogram) noexcept;
    static float fromPoundToKilogram(float pound) noexcept;
    static float fromSlugToPound(float slug) noexcept;
    static float fromPoundToSlug(float pound) noexcept;
    static float convertWeight(float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept;

};


#endif //EE205_LAB12A_FATCAT_WEIGHT_HPP
