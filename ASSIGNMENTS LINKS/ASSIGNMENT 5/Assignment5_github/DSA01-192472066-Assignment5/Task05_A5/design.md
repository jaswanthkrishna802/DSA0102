# A5 – Catching, Logging and Rethrowing

Catch an exception at the layer that can add useful context or perform a local recovery. A lower layer may log and use `throw;` to rethrow the same active exception. The application boundary catches known domain exceptions and reports a clear message to the user. A final `catch (...)` can prevent an exception from escaping a top-level boundary, but should not hide errors silently.

## Stack unwinding and RAII
When an exception exits a scope, automatic objects whose construction completed are destroyed in reverse construction order. RAII types such as `std::string`, `std::vector`, `std::unique_ptr` and file-stream objects release their resources in destructors. This avoids manually duplicating cleanup code in every catch block.

## Alternative: manual delete in catch blocks
Manual cleanup can have similar asymptotic time, but each error path must release every acquired resource. Adding a new throw point creates another opportunity for a leak. RAII centralizes cleanup in object lifetime and is safer.
