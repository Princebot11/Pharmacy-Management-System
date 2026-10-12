#ifndef SALE_H
#define SALE_H
class Sale {
private:
    int saleId;
    int medicineId;
    int customerId;
    int quantity;
    double total;
public:
    Sale();
    Sale(int id, int medId, int custId, int qty, double unitPrice);
    ~Sale();
    double calculateTotal(double unitPrice) const;
    void display() const;
    int getSaleId() const;
    int getMedicineId() const;
    int getCustomerId() const;
    int getQuantity() const;
    double getTotal() const;
};
#endif
