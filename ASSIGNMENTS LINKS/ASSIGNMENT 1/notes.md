# Task 3 – Data Types and Compatibility

Use `long long` integer paise for balances and totals; `int` for hours; `bool` for peak/weekend flags; `enum class Zone` for zones; and `long long` for journey counts and aggregates. `char` is suitable for one character, while IDs usually need `std::string`.

Floating-point decimal values such as 0.1 are generally not exact binary fractions. Integer paise keeps fare addition/subtraction exact for paise-denominated fares. Run `main.cpp` to record `sizeof` and the floating-point difference on your own compiler. Typical systems use 4-byte `int` and 8-byte `long long`/`double`, but actual sizes should be measured.

At 3,000,000 trips with ₹30 each, the total is ₹90,000,000 = 9,000,000,000 paise. That exceeds a typical 32-bit signed `int` maximum, so use `long long`.
