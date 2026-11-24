// Assembles a drink from options collected by the fluent builder.
// Both custom and menu drinks use this code.

#include "coffee_drink_builder.h"

CoffeeDrinkBuilder& CoffeeDrinkBuilder::withShots(int shots) {
    shots_ = shots;
    return *this;
}

CoffeeDrinkBuilder& CoffeeDrinkBuilder::withMilk(const std::string& milkType) {
    milk_type_ = milkType;
    return *this;
}

CoffeeDrinkBuilder& CoffeeDrinkBuilder::withSyrup(const std::string& flavor) {
    syrups_.push_back(flavor);
    return *this;
}

CoffeeDrink CoffeeDrinkBuilder::build() const {
    std::string description =
        std::to_string(shots_) + " shot(s) of espresso with " + milk_type_;
    if (!syrups_.empty()) {
        description += " and syrup:";
        for (std::size_t i = 0; i < syrups_.size(); ++i) {
            description += (i == 0 ? " " : ", ") + syrups_[i];
        }
    }
    return CoffeeDrink{description};
}
