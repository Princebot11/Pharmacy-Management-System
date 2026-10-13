# Pharmacy Management System (C++ Console OOP)

The Pharmacy Management System is a console-based application developed in C++ using Object-Oriented Programming (OOP). It helps a pharmacy keep track of its medicine stock, supplier and customer details, and medicine sales through a simple menu-driven interface.
## Build and run

From this folder:

```bash
g++ -std=c++11 main.cpp Person.cpp Supplier.cpp Customer.cpp Medicine.cpp Sale.cpp FileManager.cpp Pharmacy.cpp -o pharmacy
./pharmacy
```

## Class/file order

1. `Person.h` / `Person.cpp` — small abstract base class used to demonstrate inheritance and runtime polymorphism.
2. `Supplier.h` / `Supplier.cpp` — supplier details; inherits `Person`.
3. `Customer.h` / `Customer.cpp` — customer details; inherits `Person`.
4. `Medicine.h` / `Medicine.cpp` — medicine record and stock updates.
5. `Sale.h` / `Sale.cpp` — sale details and total calculation.
6. `FileManager.h` / `FileManager.cpp` — text-file save/load.
7. `Pharmacy.h` / `Pharmacy.cpp` — dynamic arrays and application operations.
8. `main.cpp` — menu and calls to `Pharmacy` only.
