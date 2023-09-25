#include "Restaurant.h"

Restaurant::Restaurant(const std::string& name, const std::string& location)
    : name(name), location(location) {}

const std::string& Restaurant::getName() const {
    return name;
}

const std::vector<MenuItem>& Restaurant::getMenu() const {
    return menu;
}

void Restaurant::addToMenu(const MenuItem& item) {
    menu.push_back(item);
}

const std::string& Restaurant::getLocation() const {
    return location;
}
