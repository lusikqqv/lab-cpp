#include "elem1.h"
#include <limits>

ElectromagneticEmitter::ElectromagneticEmitter() {}

ElectromagneticEmitter::~ElectromagneticEmitter() {}

void ElectromagneticEmitter::input() {
    EmitterData e;

    std::cout << "Введіть назву: ";
    std::getline(std::cin >> std::ws, e.name);

    while (true) {
        std::cout << "Введіть довжину хвилі (nm): ";

        if (std::cin >> e.wavelength && e.wavelength > 0)
            break;

        std::cout << "Неприпустиме значення!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    while (true) {
        std::cout << "Введіть потужність (mW): ";

        if (std::cin >> e.power && e.power > 0)
            break;

        std::cout << "Неприпустиме значення!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    data.push_back(e);
}

void ElectromagneticEmitter::output() const {
    for (const auto& e : data) {
        std::cout << "Назва: " << e.name << '\n';
        std::cout << "Довжина хвилі: " << e.wavelength << " nm\n";
        std::cout << "потужність: " << e.power << " mW\n";
    }
}

double ElectromagneticEmitter::getPower() const {
    double sum = 0;

    for (const auto& e : data)
        sum += e.power;

    return sum;
}