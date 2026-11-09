#ifndef COAXIAL_CABLE_H
#define COAXIAL_CABLE_H

#include "Cabel1.h"
#include <vector>
#include <string>
#include <fstream>

struct CabelData {
    std::string name;
    double impedance; 
    double diameter; 
    double length;    
};

class CoaxialCabel : public Cabel {
private:
    std::vector<CabelData> cabels;

public:
    CoaxialCabel();
    explicit CoaxialCabel(const std::string& cableName);
    ~CoaxialCabel() override;

    void addCabel(const CabelData& data);
    void input();
    void display(std::ostream& out) const override;
    void displayAll(std::ostream& out) const;

    void saveToFile(const std::string& fileName) const;
    void loadFromFile(const std::string& fileName);
    void editFile(const std::string& fileName);

    std::size_t size() const;

    bool operator<(const CoaxialCabel& other) const;
    friend std::ostream& operator<<(std::ostream& out,
                                    const CoaxialCabel& cabel);
};

#endif
