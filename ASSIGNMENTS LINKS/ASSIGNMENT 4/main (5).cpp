#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int id;
    std::string phone;

public:
    Person(const std::string& n, int i, const std::string& p)
        : name(n), id(i), phone(p) {}
    virtual ~Person() = default;
};

class Student : virtual public Person {
protected:
    std::string programme;
    double cgpa;

public:
    Student(const std::string& n, int i, const std::string& p,
            const std::string& pr, double c)
        : Person(n, i, p), programme(pr), cgpa(c) {}
};

class Staff : virtual public Person {
protected:
    std::string department;
    double salary;

public:
    Staff(const std::string& n, int i, const std::string& p,
          const std::string& d, double s)
        : Person(n, i, p), department(d), salary(s) {}
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(const std::string& n, int i, const std::string& p,
                      const std::string& pr, double c,
                      const std::string& d, double s)
        : Person(n, i, p),
          Student(n, i, p, pr, c),
          Staff(n, i, p, d, s) {}
    void display() const {
        std::cout << name << " " << id << " " << phone << '\n'
                  << programme << " " << cgpa << '\n'
                  << department << " " << salary << '\n';
    }
};

class ResearchScholar : public Student {
    double fellowship;

public:
    ResearchScholar(const std::string& n, int i, const std::string& p,
                    const std::string& pr, double c, double f)
        : Person(n, i, p), Student(n, i, p, pr, c), fellowship(f) {}

    void display() const {
        std::cout << name << " " << programme << " " << fellowship << '\n';
    }
};

int main() {
    TeachingAssistant ta("Kiran", 201, "9876543210", "CSE", 8.5,
                         "Computer Science", 35000);
    ResearchScholar rs("Divya", 202, "9876501234", "ECE", 9.1, 12000);
    ta.display();
    rs.display();
}
