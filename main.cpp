#include "FoodOrderManagementSystem.h"

int main() {
    FoodOrderManagementSystem foodOrderManagementSystem;

    foodOrderManagementSystem.registerRestaurant("Pizza Hut", "New York");
    foodOrderManagementSystem.registerRestaurant("Burger King", "Los Angeles");

    MenuItem pizza("Margherita Pizza", 12.99);
    foodOrderManagementSystem.addToMenu("Pizza Hut", pizza);

    MenuItem burger("Cheeseburger", 8.49);
    foodOrderManagementSystem.addToMenu("Burger King", burger);

    foodOrderManagementSystem.registerCustomer("Arman", "arman@example.com", "Credit Card");
    foodOrderManagementSystem.registerCustomer("Gago", "gago@example.com", "Cash");

    std::vector<MenuItem> orderItemsArman = {pizza};
    foodOrderManagementSystem.placeOrder("Arman", "Pizza Hut", orderItemsArman);

    std::vector<MenuItem> orderItemsGago = {burger};
    foodOrderManagementSystem.placeOrder("Gago", "Burger King", orderItemsGago);

    foodOrderManagementSystem.trackOrder("Arman", "Pizza Hut");
    foodOrderManagementSystem.trackOrder("Gago", "Burger King");

    foodOrderManagementSystem.generateBill("Arman", "Pizza Hut");
    foodOrderManagementSystem.generateBill("Gago", "Burger King");

    foodOrderManagementSystem.printBill("Arman", "Pizza Hut");
    foodOrderManagementSystem.printBill("Gago", "Burger King");

    foodOrderManagementSystem.saveBillToFile("Arman", "Pizza Hut");
    foodOrderManagementSystem.saveBillToFile("Gago", "Burger King");

    return 0;
}
