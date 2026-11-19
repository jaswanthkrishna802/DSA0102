# Output Predictions – Write These Before Running

The assignment explicitly says predictions must be written before executing the relevant programs. Read the code and independently write your predictions first. The notes below identify the important language rules; do not copy an output prediction after you have already run the program.

## Task 2 – virtual base class constructor trace

For the PDF's supplied small program, predict the constructor messages in this order:
- the shared virtual base `Person` is constructed once;
- direct bases are constructed in declaration order (`Student`, then `Staff`);
- the `TeachingAssistant` constructor body runs last.

Then remove `virtual` from both inheritance declarations and predict the two separate `Person` subobjects and their constructor messages.

## Task 3 – base/member/derived trace

For the PDF's `Engine`, `Vehicle`, and `Car` program:
- base classes are constructed before members;
- members are constructed in member declaration order;
- the derived constructor body runs last;
- destruction reverses the completed construction order.

Write the exact output, including spaces and the `|` marker, before compiling.

## Task 4 – binding and slicing

For the PDF's `Account` / `SeniorAccount` prediction program, the expected value sequence is:

`3.5 4 3.5`

The first call is non-virtual and is selected using the static type `Account*`. The second call is virtual and dispatches to `SeniorAccount`. The sliced `Account` copy contains only the base part, so its virtual call uses the base implementation.

## Task 5 – method chaining

For the PDF's supplied `Cart` program, the expected output is:

`324.00`

The two additions total 360; the 10% discount gives 324. Returning `Cart&` permits chained calls on the same object.

## Your verification record

For every prediction, add:
1. your prediction written before execution;
2. actual compiler output;
3. a short explanation of any difference;
4. a screenshot of the terminal.
