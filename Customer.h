#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Person.h"
class Customer : public Person {
public:
    Customer();
    Customer(int customerId, string customerName, string customerPhone);
    ~Customer() override;
    void display() const override;
};
#endif
