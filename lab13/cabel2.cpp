#include "Cabel1.h"

Cabel::Cabel(const std::string& cabelName) : name(cabelName) {}

Cabel::~Cabel() = default;

void Cabel::setName(const std::string& cabelName) {
    name = cabelName;
}

std::string Cabel::getName() const {
    return name;
}
