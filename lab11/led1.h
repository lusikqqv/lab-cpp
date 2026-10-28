#ifndef LED_H
#define LED_H

#include "elem1.h"
#include <string>

class LED : public Emitter {
private:
    std::string color;

public:
    LED(const std::string& n, double p,
        double w, const std::string& c);

    ~LED() override;

    friend class EmitterManager;
};

#endif