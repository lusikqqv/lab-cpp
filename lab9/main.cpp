#include <iostream>
#include <vector>
#include <memory>
#include <limits>

#include "LED1.h"
#include "Laser1.h"

int main() {
    std::vector<std::unique_ptr<ElectromagneticEmitter>> devices;

    int n;

    while (true) {
        std::cout << "Введіть кількість пристроїв: ";

        if (std::cin >> n && n > 0)
            break;

        std::cout << "Неприпустиме значення!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (int i = 0; i < n; i++) {
        int choice;

        std::cout << "\nПристрій " << i + 1 << '\n';

        while (true) {
            std::cout << "1 - Світлодіод\n";
            std::cout << "2 - Лазер\n";
            std::cout << "Виберіть пристрій: ";

            if (std::cin >> choice && (choice == 1 || choice == 2))
                break;

            std::cout << "Неприпустиме значення!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (choice == 1) {
            auto led = std::make_unique<LED>();
            led->inputLED();
            devices.push_back(std::move(led));
        }
        else {
            auto laser = std::make_unique<Laser>();
            laser->inputLaser();
            devices.push_back(std::move(laser));
        }
    }

    double totalPower = 0;

    std::cout << "\n===== Результат =====\n";

    for (const auto& device : devices) {
        device->output();
        totalPower += device->getPower();
    }

    std::cout << "\nЗагальна потужність: "
              << totalPower << " mW\n";

    return 0;
}