#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Bill {
protected:
    std::string patient;
public:
    explicit Bill(const std::string& p) : patient(p) {}
    virtual ~Bill() = default;
    virtual double total() const = 0;
    virtual std::string type() const { return "Bill"; }
    void print() const {
        std::cout << type() << ' ' << patient << ": " << total() << '\n';
    }
};

class OutPatient : public Bill {
    double consultation, tests;
public:
    OutPatient(const std::string& p, double c, double t)
        : Bill(p), consultation(c), tests(t) {}
    double total() const override { return consultation + tests; }
    std::string type() const override { return "OP"; }
};

class InPatient : public Bill {
    int days;
    double perDay, surgery, medicines;
public:
    InPatient(const std::string& p, int d, double rate, double s, double m = 0)
        : Bill(p), days(d), perDay(rate), surgery(s), medicines(m) {}
    double total() const override { return days * perDay + surgery + medicines; }
    std::string type() const override { return "IP"; }
};

class DayCare : public Bill {
    double packagePrice;
public:
    DayCare(const std::string& p, double price)
        : Bill(p), packagePrice(price) {}
    double total() const override { return packagePrice; }
    std::string type() const override { return "DayCare"; }
};

class Emergency : public Bill {
    double baseCharge, hourlyRate, hours;
public:
    Emergency(const std::string& p, double base, double rate, double h)
        : Bill(p), baseCharge(base), hourlyRate(rate), hours(h) {}
    double total() const override { return baseCharge + hourlyRate * hours; }
    std::string type() const override { return "Emergency"; }
};

int main() {
    std::vector<std::unique_ptr<Bill>> bills;
    bills.push_back(std::make_unique<OutPatient>("Ravi", 500, 1200));
    bills.push_back(std::make_unique<InPatient>("Meena", 3, 2500, 40000));

    double sum = 0;
    for (const auto& bill : bills) {
        bill->print();
        sum += bill->total();
    }
    std::cout << "Total " << sum << '\n';
}
