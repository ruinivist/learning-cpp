// Models an electric heater with a fixed temperature limit.
// The brew cycle uses its reported temperature.

#include "heating_element.h"

ElectricHeatingElement::ElectricHeatingElement(int maxOutputCelsius)
    : max_output_celsius_(maxOutputCelsius) {}

int ElectricHeatingElement::heat(int targetCelsius) {
    current_temperature_ = targetCelsius > max_output_celsius_
                               ? max_output_celsius_
                               : targetCelsius;
    return current_temperature_;
}

bool ElectricHeatingElement::isAtTemperature(int celsius) const {
    return current_temperature_ >= celsius;
}
