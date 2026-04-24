#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <iomanip>
using namespace std;

// Represents a company employee with age, years of service, and salary
class Employee {
public:
    Employee();
    Employee(int age, int yearsOfService, double salary);

    int    getAge()            const { return itsAge; }
    int    getYearsOfService() const { return itsYearsOfService; }
    double getSalary()         const { return itsSalary; }

    void setAge(int age);
    void setYearsOfService(int years);
    void setSalary(double salary);

    int  getSalaryInThousands() const;
    void display(int employeeNumber) const;

private:
    int    itsAge;
    int    itsYearsOfService;
    double itsSalary;
};

#endif