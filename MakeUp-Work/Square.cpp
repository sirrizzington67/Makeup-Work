#include "Square.h"
#include <iostream>
using namespace std;

Square::Square(int s) : side(0) {
    setSide(s);
}

// Side must be >= 0
void Square::setSide(int s) {
    if (s >= 0)
        side = s;
    else
        cout << "Invalid side. Must be >= 0.\n";
}