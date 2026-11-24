// Selects the recipe for a menu order.
// The kiosk calls this function with an order type.

#include "drink_factory.h"

#include "coffee_drink_builder.h"
#include "drink_prototype_registry.h"

std::string createDrink(OrderType type) {
    // Most menu recipes use the builder. The signature recipe comes from a
    // prototype.
    switch (type) {
        case OrderType::Espresso:
            return CoffeeDrinkBuilder().withShots(1).build().description;
        case OrderType::Latte:
            return CoffeeDrinkBuilder()
                .withShots(1)
                .withMilk("steamed whole milk")
                .build()
                .description;
        case OrderType::Mocha:
            return CoffeeDrinkBuilder()
                .withShots(1)
                .withMilk("steamed whole milk")
                .withSyrup("chocolate")
                .build()
                .description;
        case OrderType::SignatureCaramel: {
            DrinkPrototypeRegistry registry;
            registry.registerPrototype("signature_caramel",
                                       std::make_unique<SignatureDrink>(
                                           "Signature Caramel",
                                           "Signature Caramel: espresso, "
                                           "caramel syrup, whipped cream"));
            auto drink = registry.create("signature_caramel");
            return drink->description();
        }
        default:
            return "unknown order";
    }
}
