#include "Coaxialcabel8.h"
#include <limits>

CoaxialCable::CoaxialCable() {
    std::cout << "Конструктор викликано.\n";
}

CoaxialCable::~CoaxialCable() {
    std::cout << "Деструктор викликано. Об'єкти видалено.\n";
}

double CoaxialCable::inputPositive(const std::string& message) {
    double value;

    while (true) {
        std::cout << message;

        if (std::cin >> value && value > 0) {
            return value;
        }

        std::cout << "Помилка! Введіть число більше 0.\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void CoaxialCable::add() {
    coaxial_cable_t cable;

    std::cout << "Назва кабелю: ";
    std::getline(std::cin >> std::ws, cable.name);

    cable.impedance = inputPositive("Хвильовий опір (Ом): ");
    cable.diameter = inputPositive("Діаметр (мм): ");
    cable.length = inputPositive("Довжина (м): ");

    cables.push_back(cable);

    std::cout << "Кабель додано.\n";
}

void CoaxialCable::insert(int index) {
    if (index < 0 || index > static_cast<int>(cables.size())) {
        std::cout << "Помилка! Неправильний індекс.\n";
        return;
    }

    coaxial_cable_t cable;

    std::cout << "Назва кабелю: ";
    std::getline(std::cin >> std::ws, cable.name);

    cable.impedance = inputPositive("Хвильовий опір (Ом): ");
    cable.diameter = inputPositive("Діаметр (мм): ");
    cable.length = inputPositive("Довжина (м): ");

    cables.insert(cables.begin() + index, cable);

    std::cout << "Кабель вставлено.\n";
}

void CoaxialCable::remove(int index) {
    if (index < 0 || index >= static_cast<int>(cables.size())) {
        std::cout << "Помилка! Неправильний індекс.\n";
        return;
    }

    cables.erase(cables.begin() + index);
    std::cout << "Кабель видалено.\n";
}

void CoaxialCable::swapCables(int a, int b) {
    if (a < 0 || b < 0 ||
        a >= static_cast<int>(cables.size()) ||
        b >= static_cast<int>(cables.size())) {
        std::cout << "Помилка! Неправильний індекс.\n";
        return;
    }

    std::swap(cables[a], cables[b]);

    std::cout << "Кабелі обміняно.\n";
}

void CoaxialCable::clear() {
    cables.clear();
    std::cout << "Всі кабелі видалено.\n";
}

void CoaxialCable::print() const {
    if (cables.empty()) {
        std::cout << "Список кабелів порожній.\n";
        return;
    }

    for (size_t i = 0; i < cables.size(); i++) {
        std::cout << "\nКабель №" << i + 1 << "\n";
        std::cout << "Назва: " << cables[i].name << "\n";
        std::cout << "Хвильовий опір: " << cables[i].impedance << " Ом\n";
        std::cout << "Діаметр: " << cables[i].diameter << " мм\n";
        std::cout << "Довжина: " << cables[i].length << " м\n";
    }
}
