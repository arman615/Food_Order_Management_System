#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

class MenuItem {
private:
    std::string name;
    double price;

public:
    MenuItem(const std::string& name, double price);
    const std::string& getName() const;
    double getPrice() const;
};

#endif // MENUITEM_H
