# Task 4 – Implicit Conversions

## Predicted output (predict before running)
```text
3 3.5
C 68
1 true
s >= u
```

- `a / b` is integer division, giving 3 before conversion to `double`.
- `static_cast<double>(a) / b` performs floating-point division, giving 3.5.
- `'A' + 2` promotes the character to an integer and gives the character `C`.
- `ch + 1` promotes `char` to `int`, so it prints the numeric character code (commonly 68).
- Assigning 5 to `bool` converts it to `true`; default output is 1, and `boolalpha` prints `true`.
- In `s < u`, usual arithmetic conversions convert the signed `-1` to unsigned, making it a large unsigned value; the comparison is false.

Brace initialization rejects narrowing conversions, for example `int invalid{3.7};` is ill-formed. Explicit casts make intentional conversions visible.
