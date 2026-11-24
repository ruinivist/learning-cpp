// Defines the interface for charging an order.
// Checkout uses it to decide which receipt to print.

#pragma once

class PaymentProcessor {
   public:
    virtual ~PaymentProcessor() = default;

    virtual bool charge(int amountCents) = 0;
};
