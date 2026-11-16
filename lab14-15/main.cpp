#include <iostream>
#include <limits>
#include "Cabel1.h"
#include "dll1.h"

using namespace std;

int readChoice() {
    int choice;

    while (!(cin >> choice)) {
        cout << "Помилка! Введіть ціле число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return choice;
}

double readImpedance() {
    double value;

    while (!(cin >> value) || value <= 0) {
        cout << "Помилка! Введіть додатне число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return value;
}

int main() {
    DoublyLinkedList list;
    Cabel cabel;

    int choice;
    double impedance;

    do {
        cout << "\n====================================\n";
        cout << "   ОБРОБКА КОАКСІАЛЬНИХ КАБЕЛІВ\n";
        cout << "====================================\n";

        cout << "1. Додати кабель на початок\n";
        cout << "2. Додати кабель у кінець\n";
        cout << "3. Додати кабель після заданого\n";
        cout << "4. Видалити перший кабель\n";
        cout << "5. Видалити останній кабель\n";
        cout << "6. Видалити кабель за опором\n";
        cout << "7. Вивести список (прямий порядок)\n";
        cout << "8. Вивести список (зворотний порядок)\n";
        cout << "9. Перевірити, чи список порожній\n";
        cout << "0. Вихід\n";

        cout << "====================================\n";
        cout << "Ваш вибір: ";

        choice = readChoice();

        switch (choice) {
        case 1:
            cout << "\nВведення нового кабелю:\n";
            cabel.input();
            list.pushFront(cabel);
            break;

        case 2:
            cout << "\nВведення нового кабелю:\n";
            cabel.input();
            list.pushBack(cabel);
            break;

        case 3:
            if (list.isEmpty()) {
                cout << "Список порожній!\n";
                break;
            }

            cout << "Введіть хвильовий опір кабелю, після якого "
                 << "потрібно вставити новий: ";

            impedance = readImpedance();

            cout << "\nВведення нового кабелю:\n";
            cabel.input();

            list.insertAfter(impedance, cabel);
            break;

        case 4:
            list.popFront();
            break;

        case 5:
            list.popBack();
            break;

        case 6:
            cout << "Введіть хвильовий опір кабелю для видалення: ";
            impedance = readImpedance();
            list.removeByValue(impedance);
            break;

        case 7:
            list.displayForward();
            break;

        case 8:
            list.displayBackward();
            break;

        case 9:
            if (list.isEmpty()) {
                cout << "Список порожній.\n";
            } else {
                cout << "Список містить елементи.\n";
            }
            break;

        case 0:
            cout << "Завершення роботи програми.\n";
            break;

        default:
            cout << "Неправильний пункт меню!\n";
        }

    } while (choice != 0);

    return 0;
}
