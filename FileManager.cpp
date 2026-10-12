#include "FileManager.h"
#include "Pharmacy.h"
#include <fstream>
#include <iostream>
using namespace std;
FileManager::FileManager() {}
FileManager::~FileManager() {}
void FileManager::save(const Pharmacy& p) const {
    ofstream m("medicines.txt"), s("suppliers.txt"), c("customers.txt"), t("sales.txt");
    if (!m || !s || !c || !t) { cout << "Could not open data files for saving.\n"; return; }
    for (int i=0;i<p.getMedicineCount();i++) { const Medicine& x=p.getMedicine(i); m<<x.getId()<<','<<x.getName()<<','<<x.getCategory()<<','<<x.getPrice()<<','<<x.getStock()<<','<<x.getExpiry()<<'\n'; }
    for (int i=0;i<p.getSupplierCount();i++) { const Supplier& x=p.getSupplier(i); s<<x.getId()<<','<<x.getName()<<','<<x.getPhone()<<'\n'; }
    for (int i=0;i<p.getCustomerCount();i++) { const Customer& x=p.getCustomer(i); c<<x.getId()<<','<<x.getName()<<','<<x.getPhone()<<'\n'; }
    for (int i=0;i<p.getSaleCount();i++) { const Sale& x=p.getSale(i); t<<x.getSaleId()<<','<<x.getMedicineId()<<','<<x.getCustomerId()<<','<<x.getQuantity()<<','<<x.getTotal()<<'\n'; }
    cout << "Records saved.\n";
}
void FileManager::load(Pharmacy& p) const {
    ifstream m("medicines.txt"), s("suppliers.txt"), c("customers.txt"), t("sales.txt");
    string line;
    while (getline(m,line)) { try { int id,stock; string name,cat,exp,part; double price; size_t a=0,b;
        b=line.find(','); id=stoi(line.substr(a,b-a)); a=b+1; b=line.find(',',a); name=line.substr(a,b-a); a=b+1; b=line.find(',',a); cat=line.substr(a,b-a); a=b+1; b=line.find(',',a); price=stod(line.substr(a,b-a)); a=b+1; b=line.find(',',a); stock=stoi(line.substr(a,b-a)); exp=line.substr(b+1); p.loadMedicine(Medicine(id,name,cat,price,stock,exp)); } catch (...) {} }
    while (getline(s,line)) { try { size_t a=line.find(','), b=line.find(',',a+1); p.loadSupplier(Supplier(stoi(line.substr(0,a)),line.substr(a+1,b-a-1),line.substr(b+1))); } catch (...) {} }
    while (getline(c,line)) { try { size_t a=line.find(','), b=line.find(',',a+1); p.loadCustomer(Customer(stoi(line.substr(0,a)),line.substr(a+1,b-a-1),line.substr(b+1))); } catch (...) {} }
    while (getline(t,line)) { try { size_t a=0,b; int vals[4]; for(int i=0;i<4;i++){b=line.find(',',a); vals[i]=stoi(line.substr(a,b-a)); a=b+1;} double total=stod(line.substr(a)); p.loadSale(Sale(vals[0],vals[1],vals[2],vals[3],total/vals[3])); } catch (...) {} }
    cout << "Existing records loaded (if data files were present).\n";
}
