#include "Supplier.h"
#include <iostream>
using namespace std;
Supplier::Supplier() : Person() {}
Supplier::Supplier(int supplierId, string supplierName, string supplierPhone)
    : Person(supplierId, supplierName, supplierPhone) {}
Supplier::~Supplier() {}
void Supplier::display() const {
    cout << "Supplier ID: " << id << " | Name: " << name << " | Phone: " << phone << '\n';
}
