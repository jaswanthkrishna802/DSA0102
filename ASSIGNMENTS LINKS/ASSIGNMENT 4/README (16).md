# Task 6 – Vehicle Rental Fleet

Compile: `g++ -std=c++17 -Wall -Wextra main.cpp -o task06`  
Run: `./task06`

The abstract `Vehicle` class defines a pure virtual `rentalCharge()` function. Each vehicle type supplies its own calculation. The fleet is stored as base-class smart pointers. `ElectricBus` demonstrates adding a new type without modifying the existing vehicle classes.

Note: This is a compact demonstration model. Extend validation, dates, fuel/charge accounting and business rules if your faculty expects those details.
