#ifndef TV_H
#define TV_H

#include <iostream>
using namespace std;

// Represents a TV with a tunable station number (1-999)
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

#endif