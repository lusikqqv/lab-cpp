#include "Cabel1.h"
#include <iostream>
#include <limits>

using namespace std;

Cabel::Cabel() : impedance(0), diameter(0), length(0) {}

Cabel::Cabel(double z, double d, double l)
    : impedance(z), diameter(d), length(l) {}

Cabel::~Cabel() {}

void Cabel::input() {
    cout << "Введіть хвильовий опір (Ом): ";
    while (!(cin >> impedance) || impedance <= 0) {
        cout << "Помилка! Введіть додатне число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Введіть діаметр (мм): ";
    while (!(cin >> diameter) || diameter <= 0) {
        cout << "Помилка! Введіть додатне число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Введіть довжину (м): ";
    while (!(cin >> length) || length <= 0) {
        cout << "Помилка! Введіть додатне число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void Cabel::output() const {
    cout << "Опір: " << impedance << " Ом"
         << " | Діаметр: " << diameter << " мм"
         << " | Довжина: " << length << " м";
}

double Cabel::getImpedance() const {
    return impedance;
}

double Cabel::getDiameter() const {
    return diameter;
}

double Cabel::getLength() const {
    return length;
}
