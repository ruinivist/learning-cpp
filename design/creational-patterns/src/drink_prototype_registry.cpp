// Stores signature recipes and clones them on request.
// The menu factory uses it for signature orders.

#include "drink_prototype_registry.h"

#include <utility>

SignatureDrink::SignatureDrink(std::string name, std::string description)
    : name_(std::move(name)), description_(std::move(description)) {}

std::unique_ptr<DrinkPrototype> SignatureDrink::clone() const {
    // Copy the stored recipe so each order owns its own drink.
    return std::make_unique<SignatureDrink>(*this);
}

std::string SignatureDrink::description() const { return description_; }

void DrinkPrototypeRegistry::registerPrototype(
    const std::string& key, std::unique_ptr<DrinkPrototype> prototype) {
    prototypes_[key] = std::move(prototype);
}

std::unique_ptr<DrinkPrototype> DrinkPrototypeRegistry::create(
    const std::string& key) const {
    auto it = prototypes_.find(key);
    if (it == prototypes_.end()) {
        return nullptr;
    }
    return it->second->clone();
}
