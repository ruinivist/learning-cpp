// Defines shop-wide brewing defaults.
// The kiosk reads them when it constructs the coffee machine.

#pragma once

class MachineConfig {
   public:
    static MachineConfig& instance();

    MachineConfig(const MachineConfig&) = delete;
    MachineConfig& operator=(const MachineConfig&) = delete;

    int target_temperature_celsius = 93;
    int default_dose_grams = 18;

   private:
    MachineConfig() = default;
};
