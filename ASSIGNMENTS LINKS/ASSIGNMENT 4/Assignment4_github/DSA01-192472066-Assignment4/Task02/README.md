# Task 2 – From Requirement to Hierarchy

Compile: `g++ -std=c++17 -Wall -Wextra main.cpp -o task02`  
Run: `./task02`

`TeachingAssistant` inherits from `Student` and `Staff`. Both virtually inherit `Person`, so the most-derived object contains one shared `Person` subobject. `ResearchScholar` uses multilevel inheritance from `Student`.
