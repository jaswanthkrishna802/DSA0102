# Assignment 3 – CO3 (C++)

## Repository name
Rename this folder/repository to `DSA01-<RegisterNumber>-Assignment3` before publishing.

## Compiler
- Tested with: g++ 14.2.0 (update this to the compiler/version you actually use)
- Standard: C++17

## Compile command
```bash
g++ -std=c++17 -Wall -Wextra -pedantic Task01/main.cpp -o task01
```
Run with `./task01` (Windows MinGW: `task01.exe`).

## Folder structure
- `Task01` – constructors and constructor overloading
- `Task02` – deep copy, copy assignment, destructor (Rule of Three)
- `Task03` – dynamic 2D seat map and object lifetime
- `Task04` – Money arithmetic and stream operators
- `Task05` – prefix/postfix increment and checked subscript
- `Task06` – dynamic Text class and operator-overloading rules
- `Task07` – Complex-number class for impedance calculations
- Each task has source code, a task README, and an `evidence/` folder.

## Tasks and run steps
Compile each task separately:
```bash
g++ -std=c++17 -Wall -Wextra -pedantic Task01/main.cpp -o task01
./task01
```
Repeat with `Task02/main.cpp` through `Task07/main.cpp`.

For AddressSanitizer (where supported):
```bash
g++ -std=c++17 -Wall -Wextra -g -fsanitize=address -fno-omit-frame-pointer Task02/main.cpp -o task02_asan
./task02_asan
```

For optimization measurements:
```bash
g++ -std=c++17 -O0 Task05/main.cpp -o task05_O0
g++ -std=c++17 -O2 Task05/main.cpp -o task05_O2
```

## Important submission checklist
- [ ] Replace the repository name placeholder with your actual register number.
- [ ] Add your name/register number only if required by your course; do not publish private details unnecessarily.
- [ ] Execute every program yourself on your system.
- [ ] Save genuine terminal/output screenshots in each `evidence/` folder.
- [ ] Record actual compiler output, sanitizer output, and measured timings. Do not claim a test passed unless you ran it.
- [ ] Complete the task README analysis sections and the report template.
- [ ] Commit progressively: at least one meaningful commit per task.
- [ ] Make the repository public, or add faculty as a collaborator to a private repository.
- [ ] Paste the working GitHub URL on the report cover page and in the submission field.

## Suggested commit sequence
1. `Add Task 01 constructors`
2. `Add Task 02 deep copy and Rule of Three`
3. `Add Task 03 dynamic seat map`
4. `Add Task 04 Money operators`
5. `Add Task 05 increment and subscript operators`
6. `Add Task 06 Text class`
7. `Add Task 07 Complex impedance calculator`
8. `Add experiment evidence and final report`

**Academic integrity:** This ZIP is a starter implementation and evidence structure. Read, understand, test, adapt and defend every part yourself. The assignment asks for your own predictions before execution and your own measurements/screenshots.
