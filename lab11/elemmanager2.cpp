#include "elemmanager1.h"
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>

using namespace std;

// Перевірка введення чисел
double readNumber(const string& message) {
    string line;
    double value;
    char extra;

    while (true) {
        cout << message;
        getline(cin, line);

        stringstream ss(line);

        if (ss >> value &&
            !(ss >> extra) &&
            isfinite(value) &&
            value > 0) {
            return value;
        }

        cout << "Помилка! Введіть додатне число.\n";
    }
}

// Перевірка кількості пристроїв
int readCount(const string& message) {
    string line;
    int count;
    char extra;

    while (true) {
        cout << message;
        getline(cin, line);

        stringstream ss(line);

        if (ss >> count &&
            !(ss >> extra) &&
            count >= 0 &&
            count <= 1000) {
            return count;
        }

        cout << "Помилка! Введіть ціле число від 0 до 1000.\n";
    }
}

// Введення тексту
string readText(const string& message) {
    string text;

    while (true) {
        cout << message;
        getline(cin, text);

        if (text.find_first_not_of(" \t") != string::npos) {
            return text;
        }

        cout << "Помилка! Поле не може бути порожнім.\n";
    }
}

// Введення кольору світлодіода
string readColor() {
    string color;

    while (true) {
        cout << "Колір: ";
        getline(cin, color);

        if (color == "чорний" ||
            color == "синій" ||
            color == "зелений" ||
            color == "блакитний" ||
            color == "червоний" ||
            color == "пурпурний" ||
            color == "жовтий" ||
            color == "білий") {
            return color;
        }

        cout << "Неправильний колір! Спробуйте ще раз.\n";
        cout << "Доступні кольори: чорний, синій, зелений, "
             << "блакитний, червоний, пурпурний, жовтий, білий.\n";
    }
}

// Конструктор
EmitterManager::EmitterManager() {
    cout << "Створено менеджер випромінювачів.\n";
}

// Деструктор
EmitterManager::~EmitterManager() {
    cout << "Менеджер випромінювачів видалено.\n";
}

// Введення даних
void EmitterManager::input() {
    leds.clear();
    lasers.clear();

    int n = readCount("Кількість світлодіодів: ");

    for (int i = 0; i < n; i++) {
        cout << "\nСвітлодіод №" << i + 1 << '\n';

        string name = readText("Назва: ");
        double power = readNumber("Потужність (мВт): ");
        double wave = readNumber("Довжина хвилі (нм): ");
        string color = readColor();

        leds.push_back({LED(name, power, wave, color)});
    }

    int m = readCount("\nКількість лазерів: ");

    for (int i = 0; i < m; i++) {
        cout << "\nЛазер №" << i + 1 << '\n';

        string name = readText("Назва: ");
        double power = readNumber("Потужність (мВт): ");
        double wave = readNumber("Довжина хвилі (нм): ");
        string mode = readText("Режим роботи: ");

        lasers.push_back({Laser(name, power, wave, mode)});
    }
}

// Виведення даних
void EmitterManager::output() const {
    cout << "\n===== СВІТЛОДІОДИ =====\n";

    for (size_t i = 0; i < leds.size(); i++) {
        const LED& led = leds[i].device;

        cout << "\nСвітлодіод №" << i + 1 << '\n';

        showEmitterInfo(led);
        cout << "Колір: " << led.color << '\n';
    }

    cout << "\n===== ЛАЗЕРИ =====\n";

    for (size_t i = 0; i < lasers.size(); i++) {
        const Laser& laser = lasers[i].device;

        cout << "\nЛазер №" << i + 1 << '\n';

        showEmitterInfo(laser);
        cout << "Режим: " << laser.mode << '\n';
    }
}

// Обчислення сумарної потужності
void EmitterManager::totalPower() const {
    double sum = 0;

    for (const auto& item : leds) {
        sum += item.device.power;
    }

    for (const auto& item : lasers) {
        sum += item.device.power;
    }

    cout << "\nСумарна потужність: "
         << sum << " мВт\n";
}

// Пошук максимальної потужності
void EmitterManager::maxPower() const {
    double max = -1;
    string name;
    string type;

    for (const auto& item : leds) {
        const LED& led = item.device;

        if (led.power > max) {
            max = led.power;
            name = led.name;
            type = "Світлодіод";
        }
    }

    for (const auto& item : lasers) {
        const Laser& laser = item.device;

        if (laser.power > max) {
            max = laser.power;
            name = laser.name;
            type = "Лазер";
        }
    }

    if (max < 0) {
        cout << "Список пристроїв порожній.\n";
    } else {
        cout << "\nНайпотужніший пристрій:\n";
        cout << "Тип: " << type << '\n';
        cout << "Назва: " << name << '\n';
        cout << "Потужність: " << max << " мВт\n";
    }
}