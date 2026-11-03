#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>

#include "Vector1.h"

int main() {
    int n;
    
    while (true) {
        std::string line;
        std::cout << "Введіть кількість векторів (2-100): ";
        std::getline(std::cin, line);

        std::stringstream ss(line);

        if (ss >> n && !(ss >> line) && n >= 2 && n <= 100) {
            break;
        }

        std::cout << "Помилка! Введіть ціле число від 2 до 100.\n";
    }

    std::vector<Vector> vectors(n);

    
    for (int i = 0; i < n; i++) {
        std::cout << "\nвектор " << i + 1 << ":\n";
        vectors[i].input();
    }

    std::cout << "\nПочаткові вектори:\n";

    for (int i = 0; i < n; i++) {
        std::cout << "вектор " << i + 1 << ": ";
        vectors[i].output();

        std::cout << "  Довжина = "
                  << vectors[i].length() << "\n";
    }

    std::cout << "\nПорівняння перших двох векторів:\n";

    if (vectors[0] <= vectors[1]) {
        std::cout << "Довжина вектора 1 <= Довжина вектора 2\n";
    } else {
        std::cout << "Довжина вектора 1 > Довжина вектора 2\n";
    }

    std::cout << "\nКонкатенація першого та другого векторів:\n";

    Vector combined = vectors[0] + vectors[1];

    combined.output();

    std::cout << "\nСумарна довжина вектора = "
              << combined.length() << "\n";

    std::sort(vectors.begin(), vectors.end(),
        [](const Vector& a, const Vector& b) {
            return a.length() < b.length();
        });

    std::cout << "\nВектори, відсортовані за зростанням довжини:\n";

    for (int i = 0; i < n; i++) {
        std::cout << "вектор " << i + 1 << ": ";
        vectors[i].output();

        std::cout << "  довжина = "
                  << vectors[i].length() << "\n";
    }

    // Обчислення середньої довжини
    double average = 0;

    for (const Vector& v : vectors) {
        average += v.length();
    }

    average /= n;

    std::cout << "\nСередня довжина вектора = "
              << std::fixed << std::setprecision(2)
              << average << "\n";

    std::cout << "\nПрограму успішно завершено!\n";

    return 0;
}