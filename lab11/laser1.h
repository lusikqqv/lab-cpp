#ifndef LASER_H
#define LASER_H

#include "elem1.h"
#include <string>

class Laser : public Emitter {
private:
    std::string mode;

public:
    Laser(const std::string& n, double p,
          double w, const std::string& m);

    ~Laser() override;

    friend class EmitterManager;
};

#endif