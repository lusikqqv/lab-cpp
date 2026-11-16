#ifndef CABEL_H
#define CABEL_H

class Cabel {
private:
    double impedance;
    double diameter;
    double length;

public:
    Cabel();
    Cabel(double z, double d, double l);
    ~Cabel();

    void input();
    void output() const;

    double getImpedance() const;
    double getDiameter() const;
    double getLength() const;
};

#endif
