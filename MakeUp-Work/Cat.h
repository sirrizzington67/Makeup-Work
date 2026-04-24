#ifndef CAT_H
#define CAT_H

#include <string>
using namespace std;

class Cat {
public:
    Cat(int age = 0, double weight = 0.0, string name = "Unknown");

    int    getAge()    const { return itsAge; }
    double getWeight() const { return itsWeight; }
    string getName()   const { return itsName; }

    void setAge(int age);
    void setWeight(double weight);
    void setName(const string& name);

    void meow()        const;
    void displayInfo() const;

private:
    int    itsAge;
    double itsWeight;
    string itsName;
};

#endif