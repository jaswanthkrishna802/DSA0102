# B3 – Performance Experiments
Compile with optimization: `g++ -std=c++17 -O2 -Wall -Wextra main.cpp -o task08`  
Run: `./task08`

The program measures virtual dispatch versus a type switch at 1,000, 1,000,000 and 10,000,000 bills, then compares a simple return-code validation loop with exception-based validation at 0%, 1% and 50% invalid inputs.

Record CPU, RAM, operating system, compiler version, compile flags and repeated-run averages in your report. These are measurements, not universal performance claims. The benchmark uses generated synthetic data and simplified billing calculations.
