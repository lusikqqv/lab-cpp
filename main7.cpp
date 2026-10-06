#include "cabeel7.h"

int main() {
    CoaxialCable cables;

    cables.input();
    cables.output();

    double z;

    while (true) {
        std::cout << "\nВведіть опір для пошуку: ";

        if (std::cin >> z && z > 0) {
            break;
        }

        std::cout << "Помилка! Введіть додатне число.\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    cables.findByImpedance(z);

    return 0;
}