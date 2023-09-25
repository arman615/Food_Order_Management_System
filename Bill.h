#ifndef BILL_H
#define BILL_H

#include "Order.h"

class Bill {
private:
    Order order;
    double totalAmount;

public:
    Bill(const Order& order, double totalAmount);
    const Order& getOrder() const;
    double getTotalAmount() const;
};

#endif // BILL_H
