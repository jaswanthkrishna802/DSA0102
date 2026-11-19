# A4 – Exception Strategy

## Error conditions and proposed exceptions
- Negative consultation, test, room, medicine or package charge: `std::invalid_argument` or a domain `BillingError`.
- Claim above insurance cover: `ClaimError`.
- Unknown government package: `UnknownPackageError`.
- Missing patient record: `MissingPatientError`.
- Allocation failure: `std::bad_alloc` (normally allow it to propagate unless there is a meaningful recovery strategy).

Conceptual hierarchy:

```text
std::exception
  std::runtime_error
    BillingError
      ClaimError
      UnknownPackageError
      MissingPatientError
```

## Exception specifications
Functions that validate user input, parse data, look up packages or approve claims may throw. Destructors and cleanup operations should not throw; destructors should be non-throwing (`noexcept` by default in normal circumstances). A `noexcept` function promises not to let an exception escape; violating that promise calls `std::terminate`.

## Alternative: return codes
An enum status plus output/error message can report failures without exceptions. Normal-path work remains O(1) for one validation; error handling also performs O(1) work. The caller must check every return value and carry the message/status through each layer. This can make error propagation more verbose but makes control flow explicit.
