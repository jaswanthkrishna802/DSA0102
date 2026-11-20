# Task 2 – Tokens, Keywords, Identifiers and Constants

Examples:
- Keywords: `class`, `int`, `return`, `switch`
- Identifiers: `SmartCard`, `balancePaise`, `calculateFare`
- Literals/constants: `5000`, `20`, `true`
- Operators: `+`, `-`, `>=`, `&&`
- Punctuators: `{}`, `;`, `()`, `,`

`#define` is a preprocessor substitution and lacks normal C++ type checking/scope. `const` creates a read-only object. `constexpr` permits compile-time evaluation and is suitable for fixed fares. `enum class` is scoped and strongly typed.

Identifiers cannot contain spaces, cannot start with a digit, and cannot be a keyword. Prefer descriptive names and consistent conventions. Macro and constexpr approaches generally do not change runtime complexity; the principal difference is type safety and scope.
