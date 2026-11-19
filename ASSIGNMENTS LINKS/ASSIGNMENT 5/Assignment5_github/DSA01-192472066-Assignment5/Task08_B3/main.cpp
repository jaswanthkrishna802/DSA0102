#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

struct BillData {
    int kind;
    double a, b, c;
};

double virtualTotalOut(double a, double b) { return a + b; }
double virtualTotalIn(double a, double b, double c) { return a * b + c; }

class Bill {
public:
    virtual double total() const = 0;
    virtual ~Bill() = default;
};

class OP : public Bill {
    double a, b;
public:
    OP(double x, double y) : a(x), b(y) {}
    double total() const override { return virtualTotalOut(a, b); }
};

class IP : public Bill {
    double days, rate, surgery;
public:
    IP(double d, double r, double s) : days(d), rate(r), surgery(s) {}
    double total() const override { return virtualTotalIn(days, rate, surgery); }
};

double switchTotal(const BillData& b) {
    switch (b.kind) {
        case 0: return b.a + b.b;
        case 1: return b.a * b.b + b.c;
        default: return 0.0;
    }
}

template <typename F>
double timeRun(const char* label, F function) {
    const auto start = std::chrono::steady_clock::now();
    volatile double sink = function();
    const auto stop = std::chrono::steady_clock::now();
    const auto ms = std::chrono::duration<double, std::milli>(stop - start).count();
    std::cout << label << ": " << std::fixed << std::setprecision(3)
              << ms << " ms (checksum " << sink << ")\n";
    return ms;
}

int main() {
    std::mt19937 rng(42);
    std::uniform_real_distribution<double> dist(10.0, 500.0);

    for (std::size_t n : {1000u, 1000000u, 10000000u}) {
        std::vector<BillData> data;
        data.reserve(n);
        for (std::size_t i = 0; i < n; ++i) {
            const int kind = static_cast<int>(i % 2);
            data.push_back({kind, dist(rng), dist(rng), dist(rng)});
        }

        std::vector<std::unique_ptr<Bill>> polymorphic;
        polymorphic.reserve(n);
        for (const auto& item : data) {
            if (item.kind == 0)
                polymorphic.push_back(std::make_unique<OP>(item.a, item.b));
            else
                polymorphic.push_back(std::make_unique<IP>(item.a, item.b, item.c));
        }

        std::cout << "\nBills: " << n << '\n';
        timeRun("virtual", [&]() {
            double sum = 0;
            for (const auto& bill : polymorphic) sum += bill->total();
            return sum;
        });
        timeRun("switch", [&]() {
            double sum = 0;
            for (const auto& bill : data) sum += switchTotal(bill);
            return sum;
        });
    }

    constexpr int count = 1000000;
    for (int invalidPercent : {0, 1, 50}) {
        std::vector<double> values(count, 100.0);
        const int invalidCount = count * invalidPercent / 100;
        for (int i = 0; i < invalidCount; ++i) values[static_cast<std::size_t>(i)] = -1.0;

        std::cout << "\nInvalid percentage: " << invalidPercent << "%\n";
        timeRun("return-code", [&]() {
            long long accepted = 0;
            for (double value : values) {
                if (value >= 0) ++accepted;
            }
            return static_cast<double>(accepted);
        });
        timeRun("exceptions", [&]() {
            long long accepted = 0;
            for (double value : values) {
                try {
                    if (value < 0) throw std::invalid_argument("negative");
                    ++accepted;
                } catch (const std::invalid_argument&) {
                }
            }
            return static_cast<double>(accepted);
        });
    }
}
