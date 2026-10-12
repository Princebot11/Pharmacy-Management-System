# Pharmacy Management System (C++ Console OOP)

A beginner-friendly C++ project based on the supplied IU2541230011 – CPP08 blueprint. It uses separate `.h` and `.cpp` files, dynamic arrays, text-file persistence, and a simple menu.

## Build and run

From this folder:

```bash
g++ -std=c++11 main.cpp Person.cpp Supplier.cpp Customer.cpp Medicine.cpp Sale.cpp FileManager.cpp Pharmacy.cpp -o pharmacy
./pharmacy
```

On Windows, run `pharmacy.exe` after compiling with a C++ compiler. The program creates text data files in the current working directory when saving.

## Class/file order

1. `Person.h` / `Person.cpp` — small abstract base class used to demonstrate inheritance and runtime polymorphism.
2. `Supplier.h` / `Supplier.cpp` — supplier details; inherits `Person`.
3. `Customer.h` / `Customer.cpp` — customer details; inherits `Person`.
4. `Medicine.h` / `Medicine.cpp` — medicine record and stock updates.
5. `Sale.h` / `Sale.cpp` — sale details and total calculation.
6. `FileManager.h` / `FileManager.cpp` — text-file save/load.
7. `Pharmacy.h` / `Pharmacy.cpp` — dynamic arrays and application operations.
8. `main.cpp` — menu and calls to `Pharmacy` only.

## Notes
- This is a learning/demo program, not software for managing a real pharmacy or dispensing medicines.
- Data is saved in plain-text files in the directory where the executable is run.
- IDs should be unique. Enter names/categories without commas because comma-separated text files are used.
- The checklist and UML drafts are in `PROJECT_CHECKLIST.md` and `UML_DRAFTS.md`.
