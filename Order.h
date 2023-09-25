#ifndef ORDER_H
#define ORDER_H

#include "Customer.h"
#include "Restaurant.h"
#include "MenuItem.h"
#include <vector>

class Order {
private:
    Customer customer;
    Restaurant restaurant;
    std::vector<MenuItem> items;
    std::string status;
    std::string estimatedDeliveryTime;

public:
    Order(const Customer& customer, const Restaurant& restaurant, const std::vector<MenuItem>& items);
    const Customer& getCustomer() const;
    const Restaurant& getRestaurant() const;
    const std::vector<MenuItem>& getItems() const;
    void setStatus(const std::string& status);
    const std::string& getStatus() const;
    void setEstimatedDeliveryTime(const std::string& time);
    const std::string& getEstimatedDeliveryTime() const;
};

#endif // ORDER_H
