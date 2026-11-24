// Runs the brew cycle with the injected heater, grinder, and logger.
// The kiosk calls it for a single brew.

#include "coffee_machine.h"

#include <utility>

#include "machine_config.h"

CoffeeMachine::CoffeeMachine(std::shared_ptr<HeatingElement> heating,
                             std::shared_ptr<Grinder> grinder,
                             std::shared_ptr<Logger> logger,
                             int targetTemperature, int doseGrams,
                             GrindSize grindSize)
    : heating_(std::move(heating)),
      grinder_(std::move(grinder)),
      logger_(std::move(logger)),
      target_temperature_(targetTemperature),
      dose_grams_(doseGrams),
      grind_size_(grindSize) {}

std::string CoffeeMachine::brew() {
    // The constructor supplies these collaborators, so the brew cycle can work
    // with different implementations.
    int reachedTemperature = heating_->heat(target_temperature_);
    int groundGrams = grinder_->grind(dose_grams_, grind_size_);
    std::string description =
        "Brewed " + std::to_string(groundGrams) + "g of coffee at " +
        std::to_string(reachedTemperature) + "C. " + describeSettings();
    logger_->log(description);
    return description;
}

std::string CoffeeMachine::describeSettings() const {
    MachineConfig& config = MachineConfig::instance();
    return "Target temperature: " +
           std::to_string(config.target_temperature_celsius) +
           "C, default dose: " + std::to_string(config.default_dose_grams) +
           "g";
}
