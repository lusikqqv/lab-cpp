#ifndef ELECTROMAGNETICEMITTER_H
#define ELECTROMAGNETICEMITTER_H

#include <iostream>
#include <string>
#include <vector>

struct EmitterData {
    std::string name;
    double wavelength;
    double power;
};

class ElectromagneticEmitter {
private:
    std::vector<EmitterData> data;

public:
    ElectromagneticEmitter();
    virtual ~ElectromagneticEmitter();

    void input();
    virtual void output() const;

    double getPower() const;
};

#endif