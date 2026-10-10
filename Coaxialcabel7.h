#ifndef CABLE_H
#define CABLE_H

#include <iostream>
#include <array>
#include <string>

const int SIZE = 5;

struct Cable {
    std::string name;
    double impedance;
    double diameter;
    double length;
};

class CoaxialCable {
private:
    std::array<Cable, SIZE> cables;

public:
    CoaxialCable();
    ~CoaxialCable();

    void input();
    void output() const;
    void findByImpedance(double z) const;
};

#endif
