#include <iomanip>
#include <iostream>
#include <string>

class Cart {
    std::string items[10];
    double prices[10]{};
    int n = 0;
    double discount = 0.0;

public:
    Cart& add(const std::string& item, double price) {
        if (n < 10) {
            items[n] = item;
            prices[n] = price;
            ++n;
        }
        return *this;
    }

    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }

    double total() const {
        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            sum += prices[i];
        }
        return sum * (100.0 - discount) / 100.0;
    }
};

int main() {
    Cart c;
    c.add("Rice", 60).add("Dal", 120).setDiscount(10);

    Cart* p = &c;
    p->add("Oil", 180);
    std::cout << std::fixed << std::setprecision(2) << p->total() << '\n';

    Cart& ref = c;
    std::cout << ref.total() << '\n';

    Cart* dynamicCart = new Cart;
    dynamicCart->add("Milk", 50);
    std::cout << dynamicCart->total() << '\n';
    delete dynamicCart;
}
