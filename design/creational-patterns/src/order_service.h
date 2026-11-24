// Defines checkout for a single order.
// The kiosk supplies the payment processor at construction.

#pragma once

#include <memory>
#include <string>

#include "payment_processor.h"

class OrderService {
   public:
    explicit OrderService(std::shared_ptr<PaymentProcessor> processor);

    std::string checkout(int amountCents);

   private:
    std::shared_ptr<PaymentProcessor> processor_;
};
