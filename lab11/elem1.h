#ifndef EMITTER_H
#define EMITTER_H

#include <string>

class Emitter {
private:
    std::string name;
    double power;
    double wavelength;

public:
    Emitter(const std::string& n, double p, double w);
    virtual ~Emitter();

    friend class EmitterManager;
    friend void showEmitterInfo(const Emitter& e);
};

void showEmitterInfo(const Emitter& e);

#endif