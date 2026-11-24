// Defines regular and decaf ingredient families.
// The kiosk can select a family through the same interface.

#pragma once

#include <string>

// One factory supplies both ingredients, so one choice selects a matching
// family.
class IngredientFactory {
   public:
    virtual ~IngredientFactory() = default;
    virtual std::string createCoffeeBase() const = 0;
    virtual std::string createMilk() const = 0;
};

class RegularIngredientFactory : public IngredientFactory {
   public:
    std::string createCoffeeBase() const override;
    std::string createMilk() const override;
};

class DecafIngredientFactory : public IngredientFactory {
   public:
    std::string createCoffeeBase() const override;
    std::string createMilk() const override;
};
