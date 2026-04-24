#include "TV.h"
#include <iostream>
using namespace std;

TV::TV() : itsStation(1) {}

// Parameterized constructor: defaults to 1, then validates through setter
TV::TV(int station) : itsStation(1) {
    SetStation(station);
}

// Valid range is 1-999
void TV::SetStation(int station) {
    if (station >= 1 && station <= 999)
        itsStation = station;
    else
        cout << "Invalid station. Must be between 1 and 999.\n";
}

void TV::displayStatus() const {
    cout << "TV is on station " << itsStation << "\n";
}

void TV::channelUp() {
    if (itsStation < 999) itsStation++;
}

void TV::channelDown() {
    if (itsStation > 1) itsStation--;
}