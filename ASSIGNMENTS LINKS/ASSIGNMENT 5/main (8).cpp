#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class ClaimError : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

double approve(double billed, double cover) {
    if (billed < 0 || cover < 0)
        throw std::invalid_argument("negative amount");
    if (billed > cover)
        throw ClaimError("exceeds cover");
    return billed;
}

double settle(double billed, double cover) {
    try {
        return approve(billed, cover);
    } catch (const ClaimError& e) {
        std::cout << "audit: " << e.what() << '\n';
        throw;
    }
}

void validate(double amount) {
    if (amount < 0) throw std::invalid_argument("negative");
    if (amount > 1e6) throw std::out_of_range("too large");
    std::cout << "ok ";
}

void process(double amount) {
    try {
        validate(amount);
    } catch (const std::out_of_range& e) {
        std::cout << "[log " << e.what() << "] ";
        throw;
    }
}

int main() {
    for (double amount : {100.0, -5.0, 2e6}) {
        try {
            process(amount);
            std::cout << "done ";
        } catch (const std::exception& e) {
            std::cout << "caught " << e.what() << ' ';
        }
    }
    std::cout << '\n';

    double cases[][2] = {{40000, 50000}, {60000, 50000}, {-1, 50000}};
    for (auto& c : cases) {
        try {
            double paid = settle(c[0], c[1]);
            std::cout << "approved " << paid << '\n';
        } catch (const ClaimError& e) {
            std::cout << "claim rejected: " << e.what() << '\n';
        } catch (const std::exception& e) {
            std::cout << "error: " << e.what() << '\n';
        }
    }

    try {
        std::vector<int> values;
        values.resize(values.max_size());
    } catch (const std::bad_alloc&) {
        std::cout << "allocation failed safely\n";
    } catch (const std::exception& e) {
        std::cout << "allocation request rejected: " << e.what() << '\n';
    } catch (...) {
        std::cout << "unknown allocation failure\n";
    }
}
