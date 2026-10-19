#ifndef LASER_H
#define LASER_H

#include "elem1.h"

class Laser : public ElectromagneticEmitter {
private:
    std::string type;
    double efficiency;

public:
    Laser();
    ~Laser() override;

    void inputLaser();
    void output() const override;
};

#endif