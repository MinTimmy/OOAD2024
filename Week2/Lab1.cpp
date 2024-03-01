#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    int employeeId;
    double salary;
public:
    Employee(std::string name, int employeeId, double salary) 
        : name(name), employeeId(employeeId), salary(salary) {}

    virtual void displayDetails() const {
        std::cout << "Name: "           << name         << std::endl;
        std::cout << "Employee ID: "    << employeeId   << std::endl;
        std::cout << "Salary: $"        << salary       << std::endl;
    }
};

class Programmer : public Employee {
private:
    std::string programmingLanguage;
public:
    Programmer(std::string name, int employeeId, double salary, std::string programmingLanguage)
        : Employee(name, employeeId, salary), programmingLanguage(programmingLanguage) {}

    void displayDetails() const override {
        Employee::displayDetails();
        std::cout << "Programming Language: " << programmingLanguage << std::endl;
    }
};

class Manager : public Employee {
private:
    int teamSize;
public:
    Manager(std::string name, int employeeId, double salary, int teamSize)
        : Employee(name, employeeId, salary), teamSize(teamSize) {}

    void displayDetails() const override {
        Employee::displayDetails();
        std::cout << "Team Size: " << teamSize << " members" << std::endl;
    }
};

int main() {
    Programmer programmer("John Doe", 1001, 75000, "C++");
    Manager manager("Jane Smith", 2001, 90000, 10);

    std::cout << "Programmer Details:" << std::endl;
    programmer.displayDetails();

    std::cout << "\nManager Details:" << std::endl;
    manager.displayDetails();

    return 0;
}