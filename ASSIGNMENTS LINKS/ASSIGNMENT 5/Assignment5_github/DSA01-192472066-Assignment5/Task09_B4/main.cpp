#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

class Bill {
protected:
    std::string patient;
public:
    explicit Bill(std::string p) : patient(std::move(p)) {}
    virtual ~Bill() = default;
    virtual double total() const = 0;
    virtual std::string type() const = 0;
};

class OutPatient : public Bill {
    double consultation, tests;
public:
    OutPatient(std::string p, double c, double t)
        : Bill(std::move(p)), consultation(c), tests(t) {}
    double total() const override { return consultation + tests; }
    std::string type() const override { return "OP"; }
};

class InPatient : public Bill {
    int days;
    double rate, procedures, medicines;
public:
    InPatient(std::string p, int d, double r, double proc, double med)
        : Bill(std::move(p)), days(d), rate(r), procedures(proc), medicines(med) {}
    double total() const override { return days * rate + procedures + medicines; }
    std::string type() const override { return "IP"; }
};

// New bill type added without modifying existing bill classes.
class MaternityBill : public Bill {
    double package, extraCare;
public:
    MaternityBill(std::string p, double pkg, double extra)
        : Bill(std::move(p)), package(pkg), extraCare(extra) {}
    double total() const override { return package + extraCare; }
    std::string type() const override { return "Maternity"; }
};

class Payer {
public:
    virtual ~Payer() = default;
    virtual double amountCovered(const Bill& bill) const = 0;
};

class SelfPay : public Payer {
public:
    double amountCovered(const Bill& bill) const override { return bill.total(); }
};

class Insurance : public Payer {
    double limit;
    double copayPercent;
public:
    Insurance(double l, double c) : limit(l), copayPercent(c) {}
    double amountCovered(const Bill& bill) const override {
        const double eligible = std::min(bill.total(), limit);
        return eligible * (1.0 - copayPercent / 100.0);
    }
};

// New payer type added without modifying existing payer classes.
class CorporatePayer : public Payer {
    double coveragePercent;
public:
    explicit CorporatePayer(double percent) : coveragePercent(percent) {}
    double amountCovered(const Bill& bill) const override {
        return bill.total() * coveragePercent / 100.0;
    }
};

int main() {
    std::vector<std::unique_ptr<Bill>> bills;
    bills.push_back(std::make_unique<OutPatient>("Ravi", 500, 1200));
    bills.push_back(std::make_unique<InPatient>("Meena", 3, 2500, 40000, 2500));
    bills.push_back(std::make_unique<MaternityBill>("Asha", 65000, 5000));

    SelfPay self;
    Insurance insurance(50000, 10);
    CorporatePayer corporate(80);

    std::vector<const Payer*> payers{&self, &insurance, &corporate};
    for (const auto& bill : bills) {
        std::cout << bill->type() << " total=" << bill->total() << '\n';
        for (const Payer* payer : payers) {
            std::cout << "  covered=" << payer->amountCovered(*bill) << '\n';
        }
    }
}
