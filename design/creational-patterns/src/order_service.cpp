// Charges an order and formats the receipt.
// The kiosk calls it after selecting a drink.

#include "order_service.h"

#include <sstream>
#include <utility>

OrderService::OrderService(std::shared_ptr<PaymentProcessor> processor)
    : processor_(std::move(processor)) {}

std::string OrderService::checkout(int amountCents) {
    bool approved = processor_->charge(amountCents);
    std::ostringstream receipt;
    receipt << (approved ? "Receipt: charged $"
                         : "Receipt: payment declined for $");
    int dollars = amountCents / 100;
    int cents = amountCents % 100;
    receipt << dollars << "." << (cents < 10 ? "0" : "") << cents;
    return receipt.str();
}
