#include "Customer.h"
#include <iostream>
using namespace std;
Customer::Customer() : Person() {}
Customer::Customer(int customerId, string customerName, string customerPhone)
    : Person(customerId, customerName, customerPhone) {}
Customer::~Customer() {}
void Customer::display() const {
    cout << "Customer ID: " << id << " | Name: " << name << " | Phone: " << phone << '\n';
}
