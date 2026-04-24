#include "Cat.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Initializes all members through setters for validation
Cat::Cat(int age, double weight, string name)
    : itsAge(0), itsWeight(0.0), itsName("Unknown")
{
    setAge(age);
    setWeight(weight);
    setName(name);
}

void Cat::setAge(int age) {
    if (age >= 0)
        itsAge = age;
    else
        cout << "Invalid age. Must be >= 0.\n";
}

void Cat::setWeight(double weight) {
    if (weight >= 0.0)
        itsWeight = weight;
    else
        cout << "Invalid weight. Must be >= 0.\n";
}

void Cat::setName(const string& name) {
    if (!name.empty())
        itsName = name;
    else
        cout << "Invalid name. Must not be empty.\n";
}

void Cat::meow() const {
    cout << itsName << " says meow!\n";
}

void Cat::displayInfo() const {
    cout << fixed << setprecision(1);
    cout << "Name:   " << itsName   << "\n";
    cout << "Age:    " << itsAge    << " years\n";
    cout << "Weight: " << itsWeight << " lbs\n";
}