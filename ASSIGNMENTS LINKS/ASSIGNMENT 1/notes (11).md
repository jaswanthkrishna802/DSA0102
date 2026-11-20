# Task 7 – Procedural vs OOP

The program includes both a procedural free-function approach and a `SmartCard` class. Both use O(1) time per eligibility check and O(1) storage per card. A private balance helps enforce the invariant that a paid journey leaves at least ₹50. Public balance data could be modified without validation. Centralizing the minimum-balance rule means a policy change can be made in one place.
