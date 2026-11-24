// Supplies regular and decaf ingredient families.
// The kiosk can swap the coffee base and milk together.

#include "ingredient_factory.h"

std::string RegularIngredientFactory::createCoffeeBase() const {
    return "regular arabica beans, full caffeine";
}

std::string RegularIngredientFactory::createMilk() const {
    return "whole milk";
}

std::string DecafIngredientFactory::createCoffeeBase() const {
    return "decaf arabica beans, caffeine removed";
}

std::string DecafIngredientFactory::createMilk() const { return "oat milk"; }
