#include "Employee.h"
#include <iostream>
using namespace std;

int main() {
    Employee emp1;
    emp1.setAge(30);
    emp1.setYearsOfService(5);
    emp1.setSalary(75000.0);

    Employee emp2;
    emp2.setAge(42);
    emp2.setYearsOfService(15);
    emp2.setSalary(95000.0);

    emp1.display(1);
    emp2.display(2);

    cout << "\n";
    Employee t1, t2, t3;
    t1.setSalary(75000.0); cout << t1.getSalaryInThousands() << "\n";
    t2.setSalary(75499.0); cout << t2.getSalaryInThousands() << "\n";
    t3.setSalary(75500.0); cout << t3.getSalaryInThousands() << "\n";

    cout << "\n\n";
    Employee emp3(30, 5, 75000.0);
    emp3.display(3);

    return 0;
}