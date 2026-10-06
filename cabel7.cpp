#include "cabeel7.h"
#include <sstream>

CoaxialCable::CoaxialCable() {
    std::cout << "Конструктор викликано\n";
}

CoaxialCable::~CoaxialCable() {
    std::cout << "Деструктор викликано\n";
}

double readNumber(const std::string& message) {
    double value;
    std::string input;

    while (true) {
        std::cout << message;
        std::cin >> input;

        std::stringstream ss(input);

        if (ss >> value && ss.eof() && value > 0)
            return value;

        std::cout << "Помилка! Введіть правильне додатне число.\n";
    }
}

void CoaxialCable::input() {
    for (int i = 0; i < SIZE; i++) {

        std::cout << "\nКабель " << i + 1 << ":\n";

        std::cout << "Назва: ";
        std::cin >> cables[i].name;

        cables[i].impedance =
            readNumber("Хвильовий опір (Ом): ");

        cables[i].diameter =
            readNumber("Діаметр (мм): ");

        cables[i].length =
            readNumber("Довжина (м): ");
    }
}

void CoaxialCable::output() const {
    std::cout << "\n--- Дані про кабелі ---\n";

    for (const auto& c : cables) {
        std::cout << "Назва: " << c.name
                  << ", Опір: " << c.impedance << " Ом"
                  << ", Діаметр: " << c.diameter << " мм"
                  << ", Довжина: " << c.length << " м\n";
    }
}

void CoaxialCable::findByImpedance(double z) const {
    bool found = false;

    std::cout << "\nКабелі з опором " << z << " Ом:\n";

    for (const auto& c : cables) {
        if (c.impedance == z) {
            std::cout << c.name << " — "
                      << c.diameter << " мм, "
                      << c.length << " м\n";
            found = true;
        }
    }

    if (!found)
        std::cout << "Кабелів з таким опором не знайдено.\n";
}