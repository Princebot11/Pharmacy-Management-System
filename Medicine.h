#ifndef MEDICINE_H
#define MEDICINE_H
#include <string>
using namespace std;
class Medicine {
private:
    int medicineId;
    string name;
    string category;
    double price;
    int stock;
    string expiry;
public:
    Medicine();
    Medicine(int id, string medicineName, string medicineCategory, double medicinePrice, int medicineStock, string expiryDate);
    ~Medicine();
    void display() const;
    void updateStock(int change);
    int getId() const;
    string getName() const;
    string getCategory() const;
    double getPrice() const;
    int getStock() const;
    string getExpiry() const;
    void setDetails(string medicineName, string medicineCategory, double medicinePrice, int medicineStock, string expiryDate);
};
#endif
