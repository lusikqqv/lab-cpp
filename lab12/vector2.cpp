#include "Vector1.h"
#include <cmath>
#include <sstream>
#include <string>
#include <limits>

Vector::Vector() {}

Vector::Vector(const std::vector<double>& values) {
    elements = values;
}

Vector::~Vector() {}

void Vector::input() {
    int n;

    while (true) {
        std::string line;
        std::cout << "Введіть кількість елементів: ";
        std::getline(std::cin, line);

        std::stringstream ss(line);

        if (ss >> n && !(ss >> line) && n > 0 && n <= 100) {
            break;
        }

        std::cout << "Помилка! Введіть ціле число від 1 до 100.\n";
    }

    elements.clear();

    for (int i = 0; i < n; i++) {
        double value;

        while (true) {
            std::string line;
            std::cout << "елемент [" << i << "]: ";
            std::getline(std::cin, line);

            std::stringstream ss(line);

            if (ss >> value && std::isfinite(value) &&
                !(ss >> line)) {
                elements.push_back(value);
                break;
            }

            std::cout << "Помилка! Введіть коректне число.\n";
        }
    }
}

void Vector::output() const {
    std::cout << "(";

    for (size_t i = 0; i < elements.size(); i++) {
        std::cout << elements[i];

        if (i + 1 < elements.size()) {
            std::cout << ", ";
        }
    }

    std::cout << ")";
}

double Vector::length() const {
    double sum = 0;

    for (double value : elements) {
        sum += value * value;
    }

    return std::sqrt(sum);
}

// Перевантаження оператора <=
bool Vector::operator<=(const Vector& other) const {
    return length() <= other.length();
}

// Перевантаження оператора +
Vector Vector::operator+(const Vector& other) const {
    Vector result;

    result.elements = elements;

    for (double value : other.elements) {
        result.elements.push_back(value);
    }

    return result;
}