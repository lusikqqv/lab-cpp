#include "elem1.h"
#include <iostream>

Emitter::Emitter(const std::string& n, double p, double w)
    : name(n), power(p), wavelength(w) {}

Emitter::~Emitter() {}

void showEmitterInfo(const Emitter& e) {
    std::cout << "Назва: " << e.name << '\n';
    std::cout << "Потужність: " << e.power << " мВт\n";
    std::cout << "Довжина хвилі: " << e.wavelength << " нм\n";
}