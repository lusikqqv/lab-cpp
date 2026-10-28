#ifndef EMITTERMANAGER_H
#define EMITTERMANAGER_H

#include "LED1.h"
#include "Laser1.h"
#include <vector>

struct LEDRecord {
    LED device;
};

struct LaserRecord {
    Laser device;
};

class EmitterManager {
private:
    std::vector<LEDRecord> leds;
    std::vector<LaserRecord> lasers;

public:
    EmitterManager();
    ~EmitterManager();

    void input();
    void output() const;
    void totalPower() const;
    void maxPower() const;
};

#endif