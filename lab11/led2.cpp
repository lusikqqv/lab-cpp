#include "LED1.h"

LED::LED(const std::string& n, double p,
         double w, const std::string& c)
    : Emitter(n, p, w), color(c) {}

LED::~LED() {}