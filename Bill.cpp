#include "Bill.h"

Bill::Bill(const Order& order, double totalAmount)
    : order(order), totalAmount(totalAmount) {}

const Order& Bill::getOrder() const {
    return order;
}

double Bill::getTotalAmount() const {
    return totalAmount;
}
