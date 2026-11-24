// Defines the menu orders the kiosk can request.
// The factory maps each order to a drink description.

#pragma once

#include <string>

enum class OrderType { Espresso, Latte, Mocha, SignatureCaramel };

std::string createDrink(OrderType type);
