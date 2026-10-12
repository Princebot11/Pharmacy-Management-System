#ifndef SUPPLIER_H
#define SUPPLIER_H
#include "Person.h"
class Supplier : public Person {
public:
    Supplier();
    Supplier(int supplierId, string supplierName, string supplierPhone);
    ~Supplier() override;
    void display() const override;
};
#endif
