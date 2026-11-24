// Defines the brew cycle and the dependencies it needs.
// The kiosk provides those dependencies at startup.

#pragma once

#include <memory>
#include <string>

#include "grinder.h"
#include "heating_element.h"
#include "logger.h"

class CoffeeMachine {
   public:
    CoffeeMachine(std::shared_ptr<HeatingElement> heating,
                  std::shared_ptr<Grinder> grinder,
                  std::shared_ptr<Logger> logger, int targetTemperature,
                  int doseGrams, GrindSize grindSize);

    std::string brew();

    std::string describeSettings() const;

   private:
    std::shared_ptr<HeatingElement> heating_;
    std::shared_ptr<Grinder> grinder_;
    std::shared_ptr<Logger> logger_;
    int target_temperature_;
    int dose_grams_;
    GrindSize grind_size_;
};
