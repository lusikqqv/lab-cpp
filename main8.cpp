#include "cabel8.h"

int main() {
    CoaxialCable cables;

    int choice;

    while (true) {
        std::cout << "\n===== МЕНЮ =====\n";
        std::cout << "1 - Додати кабель\n";
        std::cout << "2 - Показати кабелі\n";
        std::cout << "3 - Вставити кабель\n";
        std::cout << "4 - Видалити кабель\n";
        std::cout << "5 - Обміняти кабелі\n";
        std::cout << "6 - Очистити список\n";
        std::cout << "0 - Вихід\n";
        std::cout << "Ваш вибір: ";

        if (!(std::cin >> choice)) {
            std::cout << "Помилка! Введіть номер пункту.\n";
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n'
            );
            continue;
        }

        if (choice == 0)
            break;

        switch (choice) {
        case 1:
            cables.add();
            break;

        case 2:
            cables.print();
            break;

        case 3: {
            int index;
            std::cout << "Індекс для вставки: ";
            std::cin >> index;
            cables.insert(index);
            break;
        }

        case 4: {
            int index;
            std::cout << "Індекс для видалення: ";
            std::cin >> index;
            cables.remove(index);
            break;
        }

        case 5: {
            int a, b;
            std::cout << "Індекс першого кабелю: ";
            std::cin >> a;
            std::cout << "Індекс другого кабелю: ";
            std::cin >> b;
            cables.swapCables(a, b);
            break;
        }

        case 6:
            cables.clear();
            break;

        default:
            std::cout << "Помилка! Такого пункту немає.\n";
        }
    }

    return 0;
}