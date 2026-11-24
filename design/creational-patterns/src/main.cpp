// Wires up the coffee-kiosk demo. Run it to see one example of each pattern.

#include <iostream>
#include <memory>

#include "coffee_drink_builder.h"
#include "coffee_machine.h"
#include "drink_factory.h"
#include "ingredient_factory.h"
#include "machine_config.h"
#include "order_service.h"

namespace {

class ApprovingPaymentProcessor : public PaymentProcessor {
   public:
    bool charge(int) override { return true; }
};

}  // namespace

int main() {
    const auto& config = MachineConfig::instance();
    CoffeeMachine machine(std::make_shared<ElectricHeatingElement>(100),
                          std::make_shared<BladeGrinder>(),
                          std::make_shared<InMemoryLogger>(),
                          config.target_temperature_celsius,
                          config.default_dose_grams, GrindSize::Fine);
    std::cout << machine.brew() << '\n';

    const auto custom = CoffeeDrinkBuilder()
                            .withShots(2)
                            .withMilk("oat milk")
                            .withSyrup("vanilla")
                            .build();
    std::cout << custom.description << '\n';
    std::cout << createDrink(OrderType::SignatureCaramel) << '\n';

    RegularIngredientFactory regular;
    DecafIngredientFactory decaf;
    const IngredientFactory* families[] = {&regular, &decaf};
    for (const auto* family : families) {
        std::cout << family->createCoffeeBase() << " + " << family->createMilk()
                  << '\n';
    }

    OrderService orders(std::make_shared<ApprovingPaymentProcessor>());
    std::cout << orders.checkout(450) << '\n';
}
