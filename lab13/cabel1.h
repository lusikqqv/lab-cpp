#ifndef CABLE_H
#define CABLE_H

#include <iostream>
#include <string>

class Cabel {
protected:
    std::string name;

public:
    explicit Cabel(const std::string& cabelName = "Кабель");
    virtual ~Cabel();

    void setName(const std::string& cabelName);
    std::string getName() const;

    virtual void display(std::ostream& out) const = 0;
};

#endif
