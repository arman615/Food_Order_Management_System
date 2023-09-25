#ifndef FOODORDERMANAGEMENTSYSTEM_H
#define FOODORDERMANAGEMENTSYSTEM_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Restaurant.h"
#include "Customer.h"
#include "Order.h"
#include "Bill.h"

class FoodOrderManagementSystem {
private:
    std::vector<Restaurant> restaurants;
    std::vector<Customer> customers;
    std::vector<Order> orders;
    std::vector<Bill> bills;

public:
    void registerRestaurant(const std::string& name, const std::string& location);
    void addToMenu(const std::string& restaurantName, const MenuItem& item);
    void registerCustomer(const std::string& name, const std::string& contactInfo, const std::string& paymentMethod);
    void placeOrder(const std::string& customerName, const std::string& restaurantName, const std::vector<MenuItem>& items);
    void trackOrder(const std::string& customerName, const std::string& restaurantName);
    void generateBill(const std::string& customerName, const std::string& restaurantName);
    void printBill(const std::string& customerName, const std::string& restaurantName);
    void saveBillToFile(const std::string& customerName, const std::string& restaurantName);
};

#endif // FOODORDERMANAGEMENTSYSTEM_H
