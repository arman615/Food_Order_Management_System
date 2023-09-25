#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std::string name;
    std::string contactInfo;
    std::string paymentMethod;

public:
    Customer(const std::string& name, const std::string& contactInfo, const std::string& paymentMethod);
    const std::string& getName() const;
    const std::string& getContactInfo() const;
    const std::string& getPaymentMethod() const;
};

#endif // CUSTOMER_H
