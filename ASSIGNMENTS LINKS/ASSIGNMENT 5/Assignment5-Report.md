# Assignment 5 – Reliable Software with Runtime Polymorphism and Exceptions

**Student name:** ENTER YOUR NAME  
**Register number:** 192472066  
**Course:** Object Oriented Programming with C++ (DSA01)  
**GitHub repository URL:** PASTE YOUR URL HERE  
**Compiler/version:** ENTER ACTUAL `g++ --version` RESULT  
**System:** ENTER OS / CPU / RAM

## Part A – Design

### A1. Polymorphic Bill hierarchy
Every bill provides `total()`, `type()` and `print()`. Shared patient data belongs in the abstract `Bill` base. `total()` is pure virtual; derived classes implement outpatient, inpatient, day-care and emergency calculations. See `Task01_A1/design.md` for UML and pseudocode.

Alternative switch design: both approaches total n bills in O(n), with O(1) per-bill calculation. A type-switch class may reserve unused fields and requires modifying switch logic when a new bill category is added.

### A2. Runtime binding
Early binding resolves non-virtual calls using the static type. Late binding resolves virtual calls using the dynamic type. A conceptual vtable contains entries for virtual functions; the derived table points to the derived override. A polymorphic base must have a virtual destructor when objects may be deleted through base pointers.

The supplied output prediction is in `Report/Predictions.md`. Include your own prediction, actual output and destructor experiment.

### A3. Abstract Payer
`Payer` defines pure virtual `amountCovered(const Bill&)`. `SelfPay`, `Insurance` and `GovernmentScheme` implement different coverage policies. A new corporate payer can derive from the interface without changing existing payer classes.

Alternative function object: a callable policy can be stored in `std::function`; invocation is O(1) for a simple policy. Compare state storage and ease of extension.

### A4. Exception strategy
Potential failures include negative charges, claims above cover, unknown package codes, missing patient records and allocation failures. Define domain exceptions derived from `std::runtime_error` where appropriate; use standard exceptions for standard-library failures. Mark genuinely non-throwing cleanup operations `noexcept`; destructors should not allow exceptions to escape.

Alternative return-code design: validation and reporting are O(1) per item in either design. Return codes require callers to check and propagate status/message values explicitly.

### A5. Recovery and rethrowing
Catch at a layer that can recover or add context. Use `throw;` to rethrow the active exception unchanged. RAII objects release resources during stack unwinding. See `Task05_A5`.

## Part B – Implementation and experimental investigation

### B1. Billing validation
Compile and run `Task06_B1/main.cpp`. Verify totals by hand:
- Outpatient: 500 + 1200 = 1700
- Inpatient: 3 × 2500 + 40000 = 47500
- Combined: 49200

Add tests for DayCare and Emergency. Compare output when `total()` is no longer virtual. Record the compiler diagnostic and test virtual-destructor behaviour under AddressSanitizer.

### B2. Error conditions
Run negative values, above-cover claims, invalid numeric text (`std::stod`), unknown package, missing patient and allocation-failure tests. Record the exact exception type and message. Include a top-level handler and destructor evidence.

Important: requesting a vector size above `max_size()` may throw `std::length_error` before attempting allocation, rather than `std::bad_alloc`. Record what actually happens on your system. Do not claim a `bad_alloc` test succeeded unless it did.

### B3. Performance measurements
Run `Task08_B3` compiled with `-O2`. Record a table:

| Bills | Virtual (ms) | Switch (ms) | Checksums agree? |
|---:|---:|---:|---|
| 1,000 | ENTER | ENTER | ENTER |
| 1,000,000 | ENTER | ENTER | ENTER |
| 10,000,000 | ENTER | ENTER | ENTER |

Exception vs return-code validation:

| Invalid inputs | Return code (ms) | Exceptions (ms) |
|---:|---:|---:|
| 0% | ENTER | ENTER |
| 1% | ENTER | ENTER |
| 50% | ENTER | ENTER |

Run several trials and report averages. Include compiler flags, CPU, RAM and operating system. Do not invent or copy timings from another machine.

### B4. Final engineering decision
The demonstration in `Task09_B4` adds `MaternityBill` and `CorporatePayer`. Run the old tests again and include a clean AddressSanitizer report. Decide whether the architecture is suitable for 15 hospitals and 200,000 bills/day using your own measurements, maintainability and extension evidence.

Discuss the alternative plug-in/configuration approach: rule interpretation may add runtime work, but non-programmer configuration can make rate changes easier. Consider validation, security, auditability and the risk of invalid configuration.

## Evidence checklist
- [ ] Part A UML class diagram
- [ ] Part A conceptual vtable diagrams
- [ ] Part A exception hierarchy
- [ ] SIMATS-format pseudocode (not C++ code in place of pseudocode)
- [ ] Output predictions written before execution
- [ ] All C++ programs compile with C++17 warnings enabled
- [ ] Actual output screenshots for every task
- [ ] AddressSanitizer evidence for required experiments
- [ ] B3 timings from this computer with `-O2`
- [ ] Test inputs and observed exception messages
- [ ] New bill and payer extension
- [ ] Working GitHub link on report and cover page
- [ ] At least one progressive commit per task
