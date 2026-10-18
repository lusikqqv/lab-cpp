#ifndef COAXIALCABLE_H
#define COAXIALCABLE_H

#include <iostream>
#include <vector>
#include <string>

struct coaxial_cable_t {
    std::string name;
    double impedance;
    double diameter;
    double length;
};

class CoaxialCable {
private:
    std::vector<coaxial_cable_t> cables;

public:
    CoaxialCable();
    ~CoaxialCable();

    void add();
    void insert(int index);
    void remove(int index);
    void swapCables(int a, int b);
    void clear();

    void print() const;

private:
    double inputPositive(const std::string& message);
};

#endif
