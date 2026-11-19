# DSA01-192472066-Assignment4

**Course:** Object Oriented Programming with C++ (DSA01)  
**Assignment:** Assignment 4 – Designing Reusable Class Hierarchies

## Student details
- Name: `ENTER YOUR NAME`
- Register number: `192472066`
- Compiler: `g++` — enter the version installed on your computer

## Requirements
All programs are written for C++17. Compile with warnings enabled:

```bash
g++ -std=c++17 -Wall -Wextra source.cpp -o program
```

For Task 4, also try AddressSanitizer where supported:

```bash
g++ -std=c++17 -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer main.cpp -o task04
```

## Repository structure

- `Task01/` — payroll hierarchy and polymorphic pay calculation
- `Task02/` — university hierarchy and virtual inheritance
- `Task03/` — base/member construction and destruction order
- `Task04/` — virtual dispatch, virtual destructor and slicing
- `Task05/` — object pointers and `this` pointer method chaining
- `Task06/` — extensible vehicle rental hierarchy
- `Report/` — written analysis, UML-style diagrams, access table and complexity comparisons
- Each task folder contains its C++ source, an output log template and a task-specific README.

## How to compile and run

Open a terminal in the required task folder. For example:

```bash
cd Task01
g++ -std=c++17 -Wall -Wextra main.cpp -o task01
./task01
```

On Windows PowerShell, run the executable as:

```powershell
.\task01.exe
```

Repeat with the source file and executable name in each task folder. Task 4's sanitizer command is given above.

## Submission checklist

- [ ] Replace `ENTER YOUR NAME` with your name.
- [ ] Confirm the register number and repository name.
- [ ] Check `g++ --version` and update the compiler version here.
- [ ] Compile and execute every program yourself.
- [ ] Compare actual output with the prediction in `Report/Predictions.md`.
- [ ] Save genuine terminal screenshots in each task's `screenshots/` folder.
- [ ] Run Task 4 with AddressSanitizer if your compiler supports it; save the genuine report.
- [ ] Complete any missing personal measurements/observations in `Report/Assignment4-Report.md`.
- [ ] Create the GitHub repository with this exact name.
- [ ] Commit progressively: make at least one meaningful commit for each task.
- [ ] Add the faculty member as a collaborator if the repository is private.
- [ ] Paste the working GitHub URL into the report and assignment cover page.

**Important:** Do not submit this ZIP as proof of execution. The assignment requires you to compile and run each task, add your own screenshots and maintain a progressive Git commit history.
