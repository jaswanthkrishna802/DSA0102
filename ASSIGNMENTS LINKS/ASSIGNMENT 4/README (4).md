# Task 3 – Constructors, Destructors and Member Classes

Compile: `g++ -std=c++17 -Wall -Wextra main.cpp -o task03`  
Run: `./task03`

The base class and member objects are initialized before the derived-class constructor body. Destruction takes place in reverse order. The `Student` constructor initializes its `Person` base and `Course` member using an initializer list.
