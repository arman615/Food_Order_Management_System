#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <vector>
#include "MenuItem.h"

class Restaurant {
private:
    std::string name;
    std::vector<MenuItem> menu;
    std::string location;

public:
    Restaurant(const std::string& name, const std::string& location);
    const std::string& getName() const;
    const std::vector<MenuItem>& getMenu() const;
    void addToMenu(const MenuItem& item);
    const std::string& getLocation() const;
};

#endif // RESTAURANT_H
