# A5 – Recovery, Rethrowing and RAII
Compile: `g++ -std=c++17 -Wall -Wextra main.cpp -o task05`  
Run: `./task05`

Predict first. Expected trace: `~f ~main caught 42`. The `throw` transfers control out of `f`; automatic objects are destroyed during stack unwinding. The statement after `f()` is not reached.
