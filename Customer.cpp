#include "Customer.h"

Customer::Customer(const std::string& name, const std::string& contactInfo, const std::string& paymentMethod)
    : name(name), contactInfo(contactInfo), paymentMethod(paymentMethod) {}

const std::string& Customer::getName() const {
    return name;
}

const std::string& Customer::getContactInfo() const {
    return contactInfo;
}

const std::string& Customer::getPaymentMethod() const {
    return paymentMethod;
}
