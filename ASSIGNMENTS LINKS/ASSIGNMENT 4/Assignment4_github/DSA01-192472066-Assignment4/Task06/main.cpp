#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Vehicle {
protected:
    std::string registration;
    double dailyRate;
    bool rented = false;

public:
    Vehicle(const std::string& reg, double rate)
        : registration(reg), dailyRate(rate) {}
    virtual double rentalCharge(int days) const = 0;
    virtual std::string type() const = 0;

    void rent() {
        if (!rented) {
            rented = true;
            std::cout << registration << " rented\n";
        } else {
            std::cout << registration << " is already rented\n";
        }
    }

    void returnVehicle(int lateDays = 0) {
        if (rented) {
            rented = false;
            std::cout << registration << " returned; late charge: "
                      << lateDays * dailyRate * 0.5 << '\n';
        } else {
            std::cout << registration << " was not rented\n";
        }
    }

    void display(int days) const {
        std::cout << type() << " " << registration
                  << " charge for " << days << " day(s): "
                  << rentalCharge(days) << '\n';
    }

    virtual ~Vehicle() = default;
};

class Bicycle : public Vehicle {
public:
    Bicycle(const std::string& reg, double rate) : Vehicle(reg, rate) {}
    double rentalCharge(int days) const override { return dailyRate * days; }
    std::string type() const override { return "Bicycle"; }
};

class MotorVehicle : public Vehicle {
protected:
    double fuelOrCharge;
    std::string serviceDue;

public:
    MotorVehicle(const std::string& reg, double rate, double level,
                 const std::string& due)
        : Vehicle(reg, rate), fuelOrCharge(level), serviceDue(due) {}
};

class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(const std::string& reg, double rate, double fuel,
               const std::string& due)
        : MotorVehicle(reg, rate, fuel, due) {}
    double rentalCharge(int days) const override { return dailyRate * days; }
    std::string type() const override { return "TwoWheeler"; }
};

class Car : public MotorVehicle {
protected:
    int seats;

public:
    Car(const std::string& reg, double rate, double fuel,
        const std::string& due, int s)
        : MotorVehicle(reg, rate, fuel, due), seats(s) {}
    double rentalCharge(int days) const override { return dailyRate * days; }
    std::string type() const override { return "Car"; }
};

class ElectricCar : public Car {
    double batteryKWh;
    double chargePerKWh;

public:
    ElectricCar(const std::string& reg, double rate, double level,
                const std::string& due, int s, double capacity, double unitRate)
        : Car(reg, rate, level, due, s),
          batteryKWh(capacity), chargePerKWh(unitRate) {}

    double rentalCharge(int days) const override {
        return dailyRate * days + batteryKWh * chargePerKWh;
    }
    std::string type() const override { return "ElectricCar"; }
};

class ElectricBus : public Vehicle {
    int seats;

public:
    ElectricBus(const std::string& reg, double rate, int s)
        : Vehicle(reg, rate), seats(s) {}
    double rentalCharge(int days) const override {
        return dailyRate * days + seats * 2.0;
    }
    std::string type() const override { return "ElectricBus"; }
};

int main() {
    std::vector<std::unique_ptr<Vehicle>> fleet;
    fleet.push_back(std::make_unique<Bicycle>("BI-101", 100));
    fleet.push_back(std::make_unique<TwoWheeler>("TW-202", 250, 8, "2026-12-01"));
    fleet.push_back(std::make_unique<Car>("CA-303", 1500, 30, "2026-12-10", 5));
    fleet.push_back(std::make_unique<ElectricCar>("EV-404", 1800, 80,
                                                  "2026-12-15", 5, 60, 8));
    fleet.push_back(std::make_unique<ElectricBus>("EB-505", 3000, 30));

    for (const auto& vehicle : fleet) {
        vehicle->display(2);
        vehicle->rent();
        vehicle->returnVehicle(1);
    }
}
