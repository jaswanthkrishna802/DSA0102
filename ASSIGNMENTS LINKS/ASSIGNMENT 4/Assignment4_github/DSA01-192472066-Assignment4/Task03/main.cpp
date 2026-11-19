#include <iostream>
#include <string>

class Address {
    std::string city;
    int pin;

public:
    Address(const std::string& c, int p) : city(c), pin(p) {
        std::cout << "Address constructed ";
    }
    ~Address() { std::cout << "Address destroyed "; }
    std::string str() const {
        return city + "-" + std::to_string(pin);
    }
};

class Person {
protected:
    std::string name;
    int age;
    Address home;

public:
    Person(const std::string& n, int a, const std::string& city, int pin)
        : name(n), age(a), home(city, pin) {
        std::cout << "Person constructed ";
    }
    virtual ~Person() { std::cout << "Person destroyed "; }
};

class Course {
    std::string title;

public:
    explicit Course(const std::string& t) : title(t) {
        std::cout << "Course constructed ";
    }
    ~Course() { std::cout << "Course destroyed "; }
};

class Student : public Person {
    long long regNo;
    Course course;

public:
    Student(const std::string& n, int a, long long r,
            const std::string& city, int pin, const std::string& c)
        : Person(n, a, city, pin), regNo(r), course(c) {
        std::cout << "Student constructed ";
    }
    ~Student() override { std::cout << "Student destroyed "; }

    void print() const {
        std::cout << "\n" << regNo << " " << name << " (" << age
                  << ") " << home.str() << '\n';
    }
};

int main() {
    {
        Student s("Kavya", 19, 192311001, "Salem", 636001, "C++");
        s.print();
    }
    std::cout << '\n';
}
