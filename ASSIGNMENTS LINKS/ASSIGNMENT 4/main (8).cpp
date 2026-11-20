#include <iostream>
#include <memory>
#include <vector>

class Account {
public:
    double rate() const { return 3.5; }
    virtual double virtualRate() const { return 3.5; }
    virtual ~Account() { std::cout << "Account destroyed\n"; }
};

class SeniorAccount : public Account {
    double* history;

public:
    SeniorAccount() : history(new double[100]{}) {}
    double rate() const { return 4.0; }
    double virtualRate() const override { return 4.0; }
    ~SeniorAccount() override {
        delete[] history;
        std::cout << "SeniorAccount destroyed\n";
    }
};

int main() {
    SeniorAccount senior;
    Account* ptr = &senior;

    std::cout << ptr->rate() << ' '
              << ptr->virtualRate() << '\n';

    Account slicedCopy = senior;
    std::cout << slicedCopy.virtualRate() << '\n';

    std::vector<std::unique_ptr<Account>> accounts;
    accounts.push_back(std::make_unique<Account>());
    accounts.push_back(std::make_unique<SeniorAccount>());

    for (const auto& account : accounts) {
        std::cout << account->virtualRate() << '\n';
    }
}
