#include "Order.h"

Order::Order(const Customer& customer, const Restaurant& restaurant, const std::vector<MenuItem>& items)
    : customer(customer), restaurant(restaurant), items(items), status("Preparing"), estimatedDeliveryTime("") {}

const Customer& Order::getCustomer() const {
    return customer;
}

const Restaurant& Order::getRestaurant() const {
    return restaurant;
}

const std::vector<MenuItem>& Order::getItems() const {
    return items;
}

void Order::setStatus(const std::string& status) {
    this->status = status;
}

const std::string& Order::getStatus() const {
    return status;
}

void Order::setEstimatedDeliveryTime(const std::string& time) {
    estimatedDeliveryTime = time;
}

const std::string& Order::getEstimatedDeliveryTime() const {
    return estimatedDeliveryTime;
}
