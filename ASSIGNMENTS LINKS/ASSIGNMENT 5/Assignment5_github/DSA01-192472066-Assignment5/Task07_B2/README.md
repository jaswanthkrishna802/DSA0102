# B2 – Engineer Error Conditions
Compile normally and with AddressSanitizer:
`g++ -std=c++17 -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer main.cpp -o task07`

Run and record all actual output. The oversized vector request may be rejected with `std::length_error` rather than `std::bad_alloc` because the requested size exceeds `max_size()`. This is implementation/library dependent. If demonstrating `std::bad_alloc`, use a controlled allocation test appropriate to your system; do not assume a huge request always produces that exception.
