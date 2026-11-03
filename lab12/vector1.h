#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <vector>

class Vector {
private:
    std::vector<double> elements;

public:
    Vector();
    Vector(const std::vector<double>& values);
    ~Vector();

    void input();
    void output() const;

    double length() const;

    bool operator<=(const Vector& other) const;

    Vector operator+(const Vector& other) const;
};

#endif
