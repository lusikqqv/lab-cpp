#include "led1.h"
#include <iostream>
#include <limits>

LED::LED() : angle(0) {}

LED::~LED() {}

void LED::inputLED() {
    input();

    while (true) {
        std::cout << "Введіть колір RGB: ";
        std::getline(std::cin >> std::ws, color);

        if (color == "чорний" ||
            color == "синій" ||
            color == "зелений" ||
            color == "блакитний" ||
            color == "червоний" ||
            color == "пурпурний" ||
            color == "жовтий" ||
            color == "білий")
            break;

        std::cout << "Неприпустимий колір .\n";
    }

    while (true) {
        std::cout << "Введіть кут (0-180): ";

        if (std::cin >> angle && angle > 0 && angle <= 180)
            break;

        std::cout << "Неприпустиме значення!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void LED::output() const {
    std::cout << "\n--- RGB LED  ---\n";

    ElectromagneticEmitter::output();

    std::cout << "Колір: " << color << '\n';
    std::cout << "Кут: " << angle << " градусів\n";
}