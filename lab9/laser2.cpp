#include "laser1.h"
#include <limits>

Laser::Laser() : efficiency(0) {}

Laser::~Laser() {}

void Laser::inputLaser() {
    input();

    std::cout << "введіть тип лазеру: ";
    std::getline(std::cin >> std::ws, type);

    while (true) {
        std::cout << "Введіть ефективність (0-100): ";

        if (std::cin >> efficiency &&
            efficiency > 0 && efficiency <= 100)
            break;

        std::cout << "Неприпустиме значення!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void Laser::output() const {
    std::cout << "\n--- Лазер ---\n";

    ElectromagneticEmitter::output();

    std::cout << "Тип: " << type << '\n';
    std::cout << "Ефективність: " << efficiency << " %\n";
}
