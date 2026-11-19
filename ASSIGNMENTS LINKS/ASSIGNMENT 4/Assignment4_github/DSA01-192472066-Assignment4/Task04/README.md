# Task 4 – Pointers to Derived Classes

Compile normally: `g++ -std=c++17 -Wall -Wextra main.cpp -o task04`  
Compile with AddressSanitizer where supported: `g++ -std=c++17 -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer main.cpp -o task04`  
Run: `./task04`

The example demonstrates static binding of a non-virtual method, runtime dispatch of a virtual method, slicing, and safe ownership with `std::unique_ptr`. The base destructor is virtual.
