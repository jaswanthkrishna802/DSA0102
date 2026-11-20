# Task 11 – Final Recommendation

Recommend a table-driven fare policy, integer paise, `long long` totals, `enum class Zone`, and a `SmartCard` class with a private balance. Keep the minimum-balance rule in one method. A fare change should update one configuration/table rather than multiple expressions.

For a configuration-file approach, reading z fares at startup is O(z) time and O(z) storage. Each subsequent lookup remains O(1). It avoids recompiling for fare revisions but requires validation, version control, safe defaults and clear failure behaviour. For millions of journeys, total processing remains O(n).
