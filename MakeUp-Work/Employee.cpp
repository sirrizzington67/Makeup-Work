#include "Employee.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Default constructor: initializes all members to 0
Employee::Employee()
    : itsAge(0), itsYearsOfService(0), itsSalary(0.0)
{}

// Parameterized constructor: validates input through setters
Employee::Employee(int age, int yearsOfService, double salary)
    : itsAge(0), itsYearsOfService(0), itsSalary(0.0)
{
    setAge(age);
    setYearsOfService(yearsOfService);
    setSalary(salary);
}

void Employee::setAge(int age) {
    if (age > 0)
        itsAge = age;
    else
        cout << "Invalid age. Must be greater than 0.\n";
}

void Employee::setYearsOfService(int years) {
    if (years >= 0)
        itsYearsOfService = years;
    else
        cout << "Invalid years of service. Must be >= 0.\n";
}

void Employee::setSalary(double salary) {
    if (salary >= 0.0)
        itsSalary = salary;
    else
        cout << "Invalid salary. Must be >= 0.\n";
}

// Rounds salary to nearest $1,000 using (salary + 500) / 1000
int Employee::getSalaryInThousands() const {
    return static_cast<int>((itsSalary + 500.0) / 1000.0);
}

void Employee::display(int employeeNumber) const {
    cout << fixed << setprecision(2);
    cout << "Employee " << employeeNumber << ":\n";
    cout << "  Age:              " << itsAge            << " years\n";
    cout << "  Years of Service: " << itsYearsOfService << " years\n";
    cout << "  Salary:           $" << setw(10) << itsSalary << "\n\n";
}