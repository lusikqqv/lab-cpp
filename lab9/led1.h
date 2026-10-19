#ifndef LED_H
#define LED_H

#include "elem1.h"

class LED : public ElectromagneticEmitter {
private:
    std::string color;
    double angle;

public:
    LED();
    ~LED() override;

    void inputLED();
    void output() const override;
};

#endif