    #include <iostream>
#include <utility>
#include "Cabel1.h"

using namespace std;

// Функція приймає об'єкт за значенням
void processCabel(Cabel cabel) {
    cout << "\nКабель усередині функції:\n";
    cabel.output();
}

// Функція повертає об'єкт
Cabel createCabel() {
    Cabel temp(75, 7.2, 100);

    cout << "\nПовернення кабелю з функції...\n";

    return std::move(temp);
}

int main() {
    // Створення об'єкта
    cout << "1. Створення об'єкта:\n";
    Cabel cabel1(50, 5.0, 20);

    cabel1.output();

    // Введення даних
    cout << "\n2. Введення параметрів кабелю:\n";
    Cabel cabel2(0, 0, 0);
    cabel2.input();

    cout << "\nВведені характеристики кабелю:\n";
    cabel2.output();

    // Конструктор копіювання
    cout << "\n3. Перевірка конструктора копіювання:\n";
    Cabel cabel3(cabel1);

    cabel3.output();

    // Оператор копіювання
    cout << "\n4. Перевірка оператора присвоювання копіюванням:\n";
    cabel2 = cabel1;

    // Конструктор переміщення
    cout << "\n5. Перевірка конструктора переміщення:\n";
    Cabel cabel4(std::move(cabel3));

    cabel4.output();

    // Оператор переміщення
    cout << "\n6. Перевірка оператора присвоювання переміщенням:\n";
    Cabel cabel2_new(0, 0, 0);

    cabel2_new = std::move(cabel4);

    cabel2_new.output();

    // Передача об'єкта у функцію за значенням
    cout << "\n7. Передача об'єкта у функцію за значенням:\n";
    processCabel(std::move(cabel1));

    // Повернення об'єкта з функції
    cout << "\n8. Повернення об'єкта з функції:\n";
    Cabel cabel5 = createCabel();

    cabel5.output();

    cout << "\n===== РОБОТУ ПРОГРАМИ ЗАВЕРШЕНО =====\n";

    return 0;
}
