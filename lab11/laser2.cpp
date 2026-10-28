#include "Laser1.h"

Laser::Laser(const std::string& n, double p,
             double w, const std::string& m)
    : Emitter(n, p, w), mode(m) {}

Laser::~Laser() {}