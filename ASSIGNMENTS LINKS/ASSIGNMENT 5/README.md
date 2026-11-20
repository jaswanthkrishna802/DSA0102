# DSA01-192472066-Assignment5

**Course:** Object Oriented Programming with C++ (DSA01)  
**Assignment 5:** Reliable Software with Runtime Polymorphism and Exceptions  
**Register number:** 192472066  
**Student name:** ENTER YOUR NAME

## Compiler and standard
Use `g++` with C++17. Record your actual version using:

```bash
g++ --version
```

Compile ordinary programs using:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o program
```

For resource-safety testing:

```bash
g++ -std=c++17 -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer main.cpp -o program
```

For performance experiments:

```bash
g++ -std=c++17 -O2 -Wall -Wextra main.cpp -o benchmark
```

## Folder map
- `Task01_A1/` – abstract Bill hierarchy, UML and daily total pseudocode
- `Task02_A2/` – early/late binding, virtual dispatch and destructor experiment
- `Task03_A3/` – abstract Payer hierarchy and extension
- `Task04_A4/` – billing exception types and exception specifications
- `Task05_A5/` – catch/rethrow and RAII stack unwinding
- `Task06_B1/` – implemented hospital billing hierarchy and completed TODO program
- `Task07_B2/` – error injection, validation, catch/rethrow and completed TODO program
- `Task08_B3/` – virtual vs switch and return-code vs exception benchmarks
- `Task09_B4/` – extension with a new bill type and payer
- `Report/` – report template, predictions and evidence checklist

## How to compile and run
Open a terminal in a task folder. Example:

```bash
cd Task06_B1
g++ -std=c++17 -Wall -Wextra main.cpp -o task06
./task06
```

On Windows PowerShell, run `.\task06.exe`.

## Mandatory submission checklist
- [ ] Replace `ENTER YOUR NAME`.
- [ ] Confirm register number and repository name.
- [ ] Record your actual compiler version.
- [ ] Compile and execute every task yourself.
- [ ] Write output predictions before running the corresponding programs.
- [ ] Save genuine terminal screenshots in each task's `screenshots/` folder.
- [ ] Run AddressSanitizer tests and save the actual reports.
- [ ] Run the performance tests with `-O2`; record your machine, compiler and measured timings.
- [ ] Complete the written report, UML/vtable diagrams and pseudocode.
- [ ] Create the GitHub repository with this exact name.
- [ ] Make at least one meaningful commit per task (nine task folders).
- [ ] Add faculty as collaborator if the repository is private.
- [ ] Put the working GitHub URL in this README and the report cover page.

**Important:** This ZIP is a starter package. It does not contain proof of personal execution, screenshots, real sanitizer evidence or real benchmark measurements. Generate those by compiling and running the programs on your own computer.
