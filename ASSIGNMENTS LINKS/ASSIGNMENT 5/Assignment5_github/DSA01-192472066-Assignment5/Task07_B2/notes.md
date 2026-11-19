# B2 Test Plan

| Test | Input | Expected handling |
|---|---|---|
| Negative bill amount | `-5` | `std::invalid_argument` |
| Amount above threshold | `2e6` | `std::out_of_range`, logged and rethrown |
| Claim above cover | billed 60000, cover 50000 | `ClaimError`, audit log, then user-facing rejection |
| Negative claim | billed -1 | `std::invalid_argument` |
| Invalid numeric text | `std::stod("abc")` | `std::invalid_argument` |
| Unknown package | unrecognized package key | domain `UnknownPackageError` in a full package lookup implementation |
| Missing patient | absent patient key | domain `MissingPatientError` in a full patient lookup implementation |
| Allocation failure | controlled allocation failure | catch `std::bad_alloc` |

The included program demonstrates negative and excessive values, claim handling and a large allocation request. The exact exception produced by an oversized vector request depends on whether the requested size exceeds `max_size()`; it may throw `std::length_error` before allocation is attempted. Record the actual result.

The assignment asks for invalid text, unknown package and missing patient tests too. Add those tests to your final extended implementation and capture their actual output.
