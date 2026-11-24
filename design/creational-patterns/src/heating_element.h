// Defines the heater interface and an electric heater.
// The brew cycle uses the interface to request a temperature.

#pragma once

class HeatingElement {
   public:
    virtual ~HeatingElement() = default;

    virtual int heat(int targetCelsius) = 0;

    virtual bool isAtTemperature(int celsius) const = 0;
};

class ElectricHeatingElement : public HeatingElement {
   public:
    explicit ElectricHeatingElement(int maxOutputCelsius);

    int heat(int targetCelsius) override;
    bool isAtTemperature(int celsius) const override;

   private:
    int max_output_celsius_;
    int current_temperature_ = 0;
};
