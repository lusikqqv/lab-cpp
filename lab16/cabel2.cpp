#include "Cabel1.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <utility>

using namespace std;

// Конструктор з параметрами
Cabel::Cabel(double impedance, double diameter, double length) {
    data = new double[3];

    data[0] = impedance;
    data[1] = diameter;
    data[2] = length;

    cout << "Викликано звичайний конструктор.\n";
}

// Деструктор
Cabel::~Cabel() {
    delete[] data;
    cout << "Викликано деструктор.\n";
}

// Конструктор копіювання
Cabel::Cabel(const Cabel& other) {
    data = new double[3];

    copy(other.data, other.data + 3, data);

    cout << "Викликано конструктор копіювання.\n";
}

// Оператор присвоювання копіюванням
Cabel& Cabel::operator=(const Cabel& other) {
    if (this != &other) {
        double* newData = new double[3];

        copy(other.data, other.data + 3, newData);

        delete[] data;
        data = newData;
    }

    cout << "Викликано оператор присвоювання копіюванням.\n";

    return *this;
}

// Конструктор переміщення
Cabel::Cabel(Cabel&& other) noexcept {
    data = other.data;
    other.data = nullptr;

    cout << "Викликано конструктор переміщення.\n";
}

// Оператор присвоювання переміщенням
Cabel& Cabel::operator=(Cabel&& other) noexcept {
    if (this != &other) {
        delete[] data;

        data = other.data;
        other.data = nullptr;
    }

    cout << "Викликано оператор присвоювання переміщенням.\n";

    return *this;
}

// Введення характеристик кабелю
void Cabel::input() {
    double value;

    const char* names[] = {
        "Введіть хвильовий опір (Ом): ",
        "Введіть діаметр (мм): ",
        "Введіть довжину (м): "
    };

    for (int i = 0; i < 3; i++) {
        while (true) {
            cout << names[i];

            if (cin >> value && value > 0) {
                data[i] = value;
                break;
            }

            cout << "Помилка! Введіть додатне число.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Виведення характеристик кабелю
void Cabel::output() const {
    if (data == nullptr) {
        cout << "Кабель порожній (об'єкт переміщено).\n";
        return;
    }

    cout << "Хвильовий опір: " << data[0] << " Ом\n";
    cout << "Діаметр: " << data[1] << " мм\n";
    cout << "Довжина: " << data[2] << " м\n";
}
