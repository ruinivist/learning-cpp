// Defines recipes that can copy themselves.
// The menu factory uses the registry for signature orders.

#pragma once

#include <memory>
#include <string>
#include <unordered_map>

class DrinkPrototype {
   public:
    virtual ~DrinkPrototype() = default;
    virtual std::unique_ptr<DrinkPrototype> clone() const = 0;
    virtual std::string description() const = 0;
};

class SignatureDrink : public DrinkPrototype {
   public:
    SignatureDrink(std::string name, std::string description);

    std::unique_ptr<DrinkPrototype> clone() const override;
    std::string description() const override;

   private:
    std::string name_;
    std::string description_;
};

class DrinkPrototypeRegistry {
   public:
    void registerPrototype(const std::string& key,
                           std::unique_ptr<DrinkPrototype> prototype);
    std::unique_ptr<DrinkPrototype> create(const std::string& key) const;

   private:
    std::unordered_map<std::string, std::unique_ptr<DrinkPrototype>>
        prototypes_;
};
