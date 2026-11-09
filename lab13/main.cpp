#include "CoaxCabel1.h"
#include <iostream>
#include <limits>
#include <exception>

int main() {
    const std::string fileName = "cabels.txt";
    CoaxialCabel catalog;

    while (true) {
        std::cout << "1. Додати кабелі\n"
                  << "2. Показати дані\n"
                  << "3. Записати дані у файл\n"
                  << "4. Зчитати дані з файлу\n"
                  << "5. Порівняти перші кабелі за хвильовим опором\n"
                  << "6. Виконати двонаправлене читання/запис файлу\n"
                  << "0. Вихід\n"
                  << "Ваш вибір: ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Помилка: потрібно ввести номер пункту меню.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        try {
            switch (choice) {
                case 1: {
                    int count;
                    std::cout << "Кількість кабелів для введення: ";
                    if (!(std::cin >> count) || count <= 0) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        throw std::invalid_argument("Кількість має бути додатним цілим числом.");
                    }
                    for (int i = 0; i < count; ++i) {
                        std::cout << "\nКабель №" << i + 1 << ":\n";
                        catalog.input();
                    }
                    break;
                }
                case 2:
                    std::cout << catalog;
                    break;
                case 3:
                    catalog.saveToFile(fileName);
                    std::cout << "Дані успішно записано у файл " << fileName << ".\n";
                    break;
                case 4:
                    catalog.loadFromFile(fileName);
                    std::cout << "Дані успішно зчитано з файлу.\n";
                    catalog.displayAll(std::cout);
                    break;
                case 5: {
                    CoaxialCabel second("Другий список");
                    std::cout << "Введіть один кабель для порівняння з першим у каталозі:\n";
                    second.input();
                    if (catalog < second)
                        std::cout << "Перший кабель має менший хвильовий опір.\n";
                    else
                        std::cout << "Перший кабель має більший або такий самий хвильовий опір.\n";
                    break;
                }
                case 6:
                    catalog.editFile(fileName);
                    std::cout << "Файл успішно прочитано та перезаписано без зміни вмісту.\n";
                    break;
                case 0:
                    std::cout << "Завершення програми.\n";
                    return 0;
                default:
                    std::cout << "Невідомий пункт меню.\n";
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Помилка: " << e.what() << '\n';
        }
        catch (...) {
            std::cerr << "Невідома помилка.\n";
        }
    }
}
