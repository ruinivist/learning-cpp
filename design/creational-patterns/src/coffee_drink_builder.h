// Defines the options for a drink under construction.
// The kiosk and menu factory both use this builder.

#pragma once

#include <string>
#include <vector>

#include "coffee_drink.h"

// Each setter returns the same builder so callers can chain options before
// calling build().
class CoffeeDrinkBuilder {
   public:
    CoffeeDrinkBuilder& withShots(int shots);
    CoffeeDrinkBuilder& withMilk(const std::string& milkType);
    CoffeeDrinkBuilder& withSyrup(const std::string& flavor);

    CoffeeDrink build() const;

   private:
    int shots_ = 1;
    std::string milk_type_ = "whole milk";
    std::vector<std::string> syrups_;
};
