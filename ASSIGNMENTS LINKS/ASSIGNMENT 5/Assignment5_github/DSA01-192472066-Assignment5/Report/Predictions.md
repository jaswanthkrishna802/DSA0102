# Output Predictions – Complete Before Execution

The assignment says output predictions must be written before running the relevant programs. Write your own prediction in your lab record or below before compiling/running. Do not fill this in retrospectively.

## A2 supplied program
Predict the numeric total and destructor messages. Then compile and verify.

## A5 supplied program
Trace stack unwinding: the local guard in `f()` is destroyed first, then the guard in `main()`, then the matching handler runs. Predict the exact output including spaces.

## B1 supplied TODO program
The PDF's expected output is:
```text
OP Ravi: 1700
IP Meena: 47500
Total 49200
```

## B2 supplied process program
For the sequence 100, -5 and 2e6:
- 100 validates and then prints `done`;
- -5 throws `invalid_argument`, which is not caught by the `out_of_range` handler in `process`, so it reaches the outer `std::exception` handler;
- 2e6 throws `out_of_range`, is logged in `process`, rethrown with `throw;`, and caught by the outer handler.

Predict the exact combined spacing before running.

## B2 claim completion
The PDF's expected output for the claim tests is:
```text
approved 40000
audit: exceeds cover
claim rejected: exceeds cover
error: negative amount
```

## Actual results
For every test, record the actual output, explain differences and attach a genuine terminal screenshot.
