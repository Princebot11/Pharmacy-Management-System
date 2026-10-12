#include "Medicine.h"
#include <iostream>
#include <stdexcept>
using namespace std;
Medicine::Medicine() : medicineId(0), name(""), category(""), price(0), stock(0), expiry("") {}
Medicine::Medicine(int id, string medicineName, string medicineCategory, double medicinePrice, int medicineStock, string expiryDate)
    : medicineId(id), name(medicineName), category(medicineCategory), price(medicinePrice), stock(medicineStock), expiry(expiryDate) {
    if (id <= 0 || medicinePrice < 0 || medicineStock < 0 || medicineName.empty())
        throw invalid_argument("Invalid medicine details.");
}
Medicine::~Medicine() {}
void Medicine::display() const {
    cout << "ID: " << medicineId << " | Name: " << name << " | Category: " << category
         << " | Price: " << price << " | Stock: " << stock << " | Expiry: " << expiry << '\n';
}
void Medicine::updateStock(int change) {
    if (stock + change < 0) throw invalid_argument("Stock cannot be negative.");
    stock += change;
}
int Medicine::getId() const { return medicineId; }
string Medicine::getName() const { return name; }
string Medicine::getCategory() const { return category; }
double Medicine::getPrice() const { return price; }
int Medicine::getStock() const { return stock; }
string Medicine::getExpiry() const { return expiry; }
void Medicine::setDetails(string medicineName, string medicineCategory, double medicinePrice, int medicineStock, string expiryDate) {
    if (medicineName.empty() || medicinePrice < 0 || medicineStock < 0) throw invalid_argument("Invalid medicine details.");
    name = medicineName; category = medicineCategory; price = medicinePrice; stock = medicineStock; expiry = expiryDate;
}
