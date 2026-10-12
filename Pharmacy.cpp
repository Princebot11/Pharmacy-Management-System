#include "Pharmacy.h"
#include <iostream>
#include <limits>
using namespace std;
Pharmacy::Pharmacy() : medicineCount(0), supplierCount(0), customerCount(0), saleCount(0), capacity(100) {
    medicines = new Medicine[capacity]; suppliers = new Supplier[capacity]; customers = new Customer[capacity]; sales = new Sale[capacity];
}
Pharmacy::~Pharmacy() { delete[] medicines; delete[] suppliers; delete[] customers; delete[] sales; }
void Pharmacy::menu() {
    load(); int choice;
    do {
        cout << "\n=== PHARMACY MANAGEMENT SYSTEM ===\n1. Add Record\n2. Display Records\n3. Search Record (Medicine)\n4. Update Record (Medicine)\n5. Delete Record (Medicine)\n6. Main Transaction (Sell Medicine)\n7. Report\n8. Save / Load\n9. Exit\nChoice: ";
        if (!(cin >> choice)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(),'\n'); cout<<"Invalid input.\n"; continue; }
        try {
            switch(choice) {
                case 1: { int op; cout<<"1. Medicine\n2. Supplier\n3. Customer\nChoice: "; cin>>op; if(op==1)addMedicine(); else if(op==2)addSupplier(); else if(op==3)addCustomer(); else cout<<"Invalid choice.\n"; break; }
                case 2: displayMedicines(); for(int i=0;i<supplierCount;i++){ Person* person=&suppliers[i]; person->display(); } for(int i=0;i<customerCount;i++){ Person* person=&customers[i]; person->display(); } break;
                case 3: searchMedicine(); break;
                case 4: updateMedicine(); break;
                case 5: deleteMedicine(); break;
                case 6: sellMedicine(); break;
                case 7: report(); break;
                case 8: { int op; cout<<"1. Save\n2. Load\nChoice: "; cin>>op; if(op==1) save(); else if(op==2) load(); else cout<<"Invalid choice.\n"; break; }
                case 9: save(); cout<<"Goodbye.\n"; break;
                default: cout<<"Choose a listed option.\n";
            }
        } catch(const exception& e) { cout<<"Error: "<<e.what()<<'\n'; }
    } while(choice!=9);
}
void Pharmacy::addMedicine() {
    if(medicineCount>=capacity) { cout<<"Medicine storage is full.\n"; return; }
    int id,stock; double price; string name,cat,exp;
    cout<<"Medicine ID: "; cin>>id; for(int i=0;i<medicineCount;i++)if(medicines[i].getId()==id){cout<<"ID already exists.\n";return;}
    cout<<"Name (no commas): "; cin>>ws; getline(cin,name); cout<<"Category: "; getline(cin,cat); cout<<"Price: "; cin>>price; cout<<"Stock: "; cin>>stock; cout<<"Expiry (e.g. 2027-12): "; cin>>ws; getline(cin,exp);
    medicines[medicineCount++]=Medicine(id,name,cat,price,stock,exp); cout<<"Medicine added.\n";
}
void Pharmacy::displayMedicines() const { if(!medicineCount)cout<<"No medicines found.\n"; for(int i=0;i<medicineCount;i++)medicines[i].display(); }
void Pharmacy::searchMedicine() const { int id; cout<<"Enter medicine ID: "; cin>>id; for(int i=0;i<medicineCount;i++)if(medicines[i].getId()==id){medicines[i].display();return;} cout<<"Medicine not found.\n"; }
void Pharmacy::updateMedicine() { int id,stock; double price; string name,cat,exp; cout<<"Medicine ID to update: ";cin>>id; for(int i=0;i<medicineCount;i++)if(medicines[i].getId()==id){cout<<"New name: ";cin>>ws;getline(cin,name);cout<<"New category: ";getline(cin,cat);cout<<"New price: ";cin>>price;cout<<"New stock: ";cin>>stock;cout<<"New expiry: ";cin>>ws;getline(cin,exp);medicines[i].setDetails(name,cat,price,stock,exp);cout<<"Medicine updated.\n";return;} cout<<"Medicine not found.\n"; }
void Pharmacy::deleteMedicine() { int id; cout<<"Medicine ID to delete: ";cin>>id;for(int i=0;i<medicineCount;i++)if(medicines[i].getId()==id){for(int j=i;j<medicineCount-1;j++)medicines[j]=medicines[j+1];medicineCount--;cout<<"Medicine deleted.\n";return;}cout<<"Medicine not found.\n"; }
void Pharmacy::addSupplier() { if(supplierCount>=capacity)return; int id; string name,phone; cout<<"Supplier ID: ";cin>>id;cout<<"Name: ";cin>>ws;getline(cin,name);cout<<"Phone: ";getline(cin,phone);suppliers[supplierCount++]=Supplier(id,name,phone);cout<<"Supplier added.\n"; }
void Pharmacy::addCustomer() { if(customerCount>=capacity)return; int id; string name,phone; cout<<"Customer ID: ";cin>>id;cout<<"Name: ";cin>>ws;getline(cin,name);cout<<"Phone: ";getline(cin,phone);customers[customerCount++]=Customer(id,name,phone);cout<<"Customer added.\n"; }
void Pharmacy::sellMedicine() {
    if(saleCount>=capacity){cout<<"Sales storage is full.\n";return;} int id,cid,qty; cout<<"Medicine ID: ";cin>>id; int index=-1;for(int i=0;i<medicineCount;i++)if(medicines[i].getId()==id)index=i;if(index<0){cout<<"Medicine not found.\n";return;}
    cout<<"Customer ID (0 for walk-in): ";cin>>cid; cout<<"Quantity: ";cin>>qty; if(qty<=0||qty>medicines[index].getStock()){cout<<"Invalid quantity or insufficient stock.\n";return;}
    int saleId=saleCount+1; sales[saleCount++]=Sale(saleId,id,cid,qty,medicines[index].getPrice()); medicines[index].updateStock(-qty); cout<<"Sale complete. Total = "<<sales[saleCount-1].getTotal()<<'\n';
}
void Pharmacy::report() const { cout<<"\n--- Pharmacy Report ---\nMedicines: "<<medicineCount<<"\nSuppliers: "<<supplierCount<<"\nCustomers: "<<customerCount<<"\nSales: "<<saleCount<<'\n'; double total=0;for(int i=0;i<saleCount;i++)total+=sales[i].getTotal();cout<<"Sales total: "<<total<<'\n';cout<<"Low stock (5 or less):\n";for(int i=0;i<medicineCount;i++)if(medicines[i].getStock()<=5)medicines[i].display(); }
void Pharmacy::save() const { fileManager.save(*this); }
void Pharmacy::load() { medicineCount=supplierCount=customerCount=saleCount=0;fileManager.load(*this); }
int Pharmacy::getMedicineCount() const{return medicineCount;} int Pharmacy::getSupplierCount() const{return supplierCount;} int Pharmacy::getCustomerCount() const{return customerCount;} int Pharmacy::getSaleCount() const{return saleCount;}
const Medicine& Pharmacy::getMedicine(int i) const{return medicines[i];} const Supplier& Pharmacy::getSupplier(int i) const{return suppliers[i];} const Customer& Pharmacy::getCustomer(int i) const{return customers[i];} const Sale& Pharmacy::getSale(int i) const{return sales[i];}
void Pharmacy::loadMedicine(const Medicine& x){if(medicineCount<capacity)medicines[medicineCount++]=x;}
void Pharmacy::loadSupplier(const Supplier& x){if(supplierCount<capacity)suppliers[supplierCount++]=x;}
void Pharmacy::loadCustomer(const Customer& x){if(customerCount<capacity)customers[customerCount++]=x;}
void Pharmacy::loadSale(const Sale& x){if(saleCount<capacity)sales[saleCount++]=x;}
