#include "Sale.h"
#include <iostream>
#include <stdexcept>
using namespace std;
Sale::Sale() : saleId(0), medicineId(0), customerId(0), quantity(0), total(0) {}
Sale::Sale(int id, int medId, int custId, int qty, double unitPrice)
    : saleId(id), medicineId(medId), customerId(custId), quantity(qty), total(qty * unitPrice) {
    if (id <= 0 || medId <= 0 || custId < 0 || qty <= 0 || unitPrice < 0)
        throw invalid_argument("Invalid sale details.");
}
Sale::~Sale() {}
double Sale::calculateTotal(double unitPrice) const { return quantity * unitPrice; }
void Sale::display() const {
    cout << "Sale ID: " << saleId << " | Medicine ID: " << medicineId << " | Customer ID: " << customerId
         << " | Quantity: " << quantity << " | Total: " << total << '\n';
}
int Sale::getSaleId() const { return saleId; }
int Sale::getMedicineId() const { return medicineId; }
int Sale::getCustomerId() const { return customerId; }
int Sale::getQuantity() const { return quantity; }
double Sale::getTotal() const { return total; }
