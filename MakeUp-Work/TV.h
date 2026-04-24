#ifndef TV_H
#define TV_H

#include <iostream>
using namespace std;

class TV {
public:
    TV();
    TV(int station);

    void SetStation(int station);
    int  GetStation() const { return itsStation; }

    void displayStatus() const;
    void channelUp();
    void channelDown();

private:
    int itsStation;
};

TV::TV() : itsStation(1) {}

TV::TV(int station) : itsStation(1) {
    SetStation(station);
}

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

#endif