#ifndef PHARMACY_H
#define PHARMACY_H
#include "Medicine.h"
#include "Supplier.h"
#include "Customer.h"
#include "Sale.h"
#include "FileManager.h"
class Pharmacy {
private:
    Medicine* medicines;
    Supplier* suppliers;
    Customer* customers;
    Sale* sales;
    int medicineCount, supplierCount, customerCount, saleCount;
    int capacity;
    FileManager fileManager;
public:
    Pharmacy();
    ~Pharmacy();
    void menu();
    void addMedicine();
    void displayMedicines() const;
    void searchMedicine() const;
    void updateMedicine();
    void deleteMedicine();
    void addSupplier();
    void addCustomer();
    void sellMedicine();
    void report() const;
    void save() const;
    void load();
    int getMedicineCount() const; int getSupplierCount() const; int getCustomerCount() const; int getSaleCount() const;
    const Medicine& getMedicine(int i) const; const Supplier& getSupplier(int i) const; const Customer& getCustomer(int i) const; const Sale& getSale(int i) const;
    void loadMedicine(const Medicine& x); void loadSupplier(const Supplier& x); void loadCustomer(const Customer& x); void loadSale(const Sale& x);
};
#endif
