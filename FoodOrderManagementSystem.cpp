#include "FoodOrderManagementSystem.h"

void FoodOrderManagementSystem::registerRestaurant(const std::string& name, const std::string& location) {
    Restaurant newRestaurant(name, location);
    restaurants.push_back(newRestaurant);
    std::cout << "Restaurant registered successfully.\n";
}

void FoodOrderManagementSystem::addToMenu(const std::string& restaurantName, const MenuItem& item) {
    for (Restaurant& restaurant : restaurants) {
        if (restaurant.getName() == restaurantName) {
            restaurant.addToMenu(item);
            std::cout << "Menu item added successfully.\n";
            return;
        }
    }
    std::cout << "Restaurant not found.\n";
}

void FoodOrderManagementSystem::registerCustomer(const std::string& name, const std::string& contactInfo, const std::string& paymentMethod) {
    Customer newCustomer(name, contactInfo, paymentMethod);
    customers.push_back(newCustomer);
    std::cout << "Customer registered successfully.\n";
}

void FoodOrderManagementSystem::placeOrder(const std::string& customerName, const std::string& restaurantName, const std::vector<MenuItem>& items) {
    Customer* customerPtr = nullptr;
    for (Customer& customer : customers) {
        if (customer.getName() == customerName) {
            customerPtr = &customer;
            break;
        }
    }
    if (customerPtr == nullptr) {
        std::cout << "Customer not found.\n";
        return;
    }

    Restaurant* restaurantPtr = nullptr;
    for (Restaurant& restaurant : restaurants) {
        if (restaurant.getName() == restaurantName) {
            restaurantPtr = &restaurant;
            break;
        }
    }
    if (restaurantPtr == nullptr) {
        std::cout << "Restaurant not found.\n";
        return;
    }

    Order newOrder(*customerPtr, *restaurantPtr, items);
    orders.push_back(newOrder);

    std::cout << "Order placed successfully.\n";
}

void FoodOrderManagementSystem::trackOrder(const std::string& customerName, const std::string& restaurantName) {
    for (const Order& order : orders) {
        if (order.getCustomer().getName() == customerName && order.getRestaurant().getName() == restaurantName) {
            std::cout << "Order Status: " << order.getStatus() << std::endl;
            std::cout << "Estimated Delivery Time: " << order.getEstimatedDeliveryTime() << std::endl;
            return;
        }
    }
    std::cout << "Order not found.\n";
}

void FoodOrderManagementSystem::generateBill(const std::string& customerName, const std::string& restaurantName) {
    Order* orderPtr = nullptr;
    for (Order& order : orders) {
        if (order.getCustomer().getName() == customerName && order.getRestaurant().getName() == restaurantName) {
            orderPtr = &order;
            break;
        }
    }
    if (orderPtr == nullptr) {
        std::cout << "Order not found.\n";
        return;
    }

    double totalAmount = 0.0;
    for (const MenuItem& item : orderPtr->getItems()) {
        totalAmount += item.getPrice();
    }

    Bill newBill(*orderPtr, totalAmount);
    bills.push_back(newBill);

    std::cout << "Bill generated successfully.\n";
}

void FoodOrderManagementSystem::printBill(const std::string& customerName, const std::string& restaurantName) {
    for (const Bill& bill : bills) {
        if (bill.getOrder().getCustomer().getName() == customerName && bill.getOrder().getRestaurant().getName() == restaurantName) {
            const Order& order = bill.getOrder();
            std::cout << "---------- Bill ----------\n";
            std::cout << "Customer: " << order.getCustomer().getName() << std::endl;
            std::cout << "Restaurant: " << order.getRestaurant().getName() << std::endl;
            std::cout << "Ordered Items:\n";
            for (const MenuItem& item : order.getItems()) {
                std::cout << "- " << item.getName() << " $" << item.getPrice() << std::endl;
            }
            std::cout << "Total Amount: $" << bill.getTotalAmount() << std::endl;
            std::cout << "--------------------------\n";
            return;
        }
    }
    std::cout << "Bill not found.\n";
}

void FoodOrderManagementSystem::saveBillToFile(const std::string& customerName, const std::string& restaurantName) {
    for (const Bill& bill : bills) {
        if (bill.getOrder().getCustomer().getName() == customerName && bill.getOrder().getRestaurant().getName() == restaurantName) {
            const Order& order = bill.getOrder();
            std::ofstream file(customerName + "_" + restaurantName + "_bill.txt");
            if (file.is_open()) {
                file << "---------- Bill ----------\n";
                file << "Customer: " << order.getCustomer().getName() << std::endl;
                file << "Restaurant: " << order.getRestaurant().getName() << std::endl;
                file << "Ordered Items:\n";
                for (const MenuItem& item : order.getItems()) {
                    file << "- " << item.getName() << " $" << item.getPrice() << std::endl;
                }
                file << "Total Amount: $" << bill.getTotalAmount() << std::endl;
                file << "--------------------------\n";
                file.close();
                std::cout << "Bill saved to file successfully.\n";
            } else {
                std::cout << "Unable to save bill to file.\n";
            }
            return;
        }
    }
    std::cout << "Bill not found.\n";
}
