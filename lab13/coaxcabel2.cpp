#include "coaxcabel1.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <utility>

CoaxialCabel::CoaxialCabel() : Cabel("Коаксіальний кабель") {}

CoaxialCabel::CoaxialCabel(const std::string& cabelName) : Cabel(cabelName) {}

CoaxialCabel::~CoaxialCabel() = default;

void CoaxialCabel::addCabel(const CabelData& data) {
    if (data.name.empty())
        throw std::invalid_argument("Назва кабелю не може бути порожньою.");
    if (data.impedance <= 0 || data.diameter <= 0 || data.length <= 0)
        throw std::invalid_argument("Усі числові параметри мають бути додатними.");
    cabels.push_back(data);
}

void CoaxialCabel::input() {
    CabelData data;
    std::cout << "Назва кабелю: ";
    std::getline(std::cin >> std::ws, data.name);

    auto readPositive = [](const std::string& prompt) -> double {
        while (true) {
            std::cout << prompt;
            std::string line;
            std::getline(std::cin, line);
            std::stringstream ss(line);
            double value;
            char extra;
            if ((ss >> value) && !(ss >> extra) && value > 0)
                return value;
            std::cout << "Помилка: введіть одне додатне число. Спробуйте ще раз.\n";
        }
    };

    data.impedance = readPositive("Хвильовий опір (Ом): ");
    data.diameter = readPositive("Діаметр (мм): ");
    data.length = readPositive("Довжина (м): ");
    addCabel(data);
}

void CoaxialCabel::display(std::ostream& out) const {
    out << "Тип об'єкта: " << name << '\n';
    displayAll(out);
}

void CoaxialCabel::displayAll(std::ostream& out) const {
    if (cabels.empty()) {
        out << "Список кабелів порожній.\n";
        return;
    }

    out << "\nСписок коаксіальних кабелів:\n";
    out << "------------------------------------------------------------\n";
    for (std::size_t i = 0; i < cabels.size(); ++i) {
        out << i + 1 << ". " << cabels[i].name
            << " | Опір: " << cabels[i].impedance << " Ом"
            << " | Діаметр: " << cabels[i].diameter << " мм"
            << " | Довжина: " << cabels[i].length << " м\n";
    }
    out << "------------------------------------------------------------\n";
}

void CoaxialCabel::saveToFile(const std::string& fileName) const {
    // fstream забезпечує двонаправлену роботу з файлом
    std::fstream file(fileName, std::ios::out | std::ios::trunc);
    if (!file.is_open())
        throw std::runtime_error("Не вдалося відкрити файл для запису: " + fileName);

    for (const auto& item : cabels) {
        file << item.name << '\n'
             << item.impedance << ' '
             << item.diameter << ' '
             << item.length << '\n';
    }

    if (!file.good())
        throw std::runtime_error("Помилка під час запису даних у файл.");
    file.close();
}

void CoaxialCabel::loadFromFile(const std::string& fileName) {
    std::fstream file(fileName, std::ios::in);
    if (!file.is_open())
        throw std::runtime_error("Не вдалося відкрити файл для читання: " + fileName);

    std::vector<CabelData> loaded;
    CabelData item;
    while (std::getline(file, item.name)) {
        if (!(file >> item.impedance >> item.diameter >> item.length))
            throw std::runtime_error("Файл містить некоректні або неповні дані.");
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (item.name.empty() || item.impedance <= 0 ||
            item.diameter <= 0 || item.length <= 0)
            throw std::runtime_error("У файлі знайдено недопустимі значення.");

        loaded.push_back(item);
    }

    if (!file.eof())
        throw std::runtime_error("Помилка читання файлу.");

    cabels = std::move(loaded);
    file.close();
}

void CoaxialCabel::editFile(const std::string& fileName) {
    // Двонаправлений доступ: спочатку читаємо вміст, потім записуємо
    // його назад у той самий файл без зміни даних.
    std::fstream file(fileName, std::ios::in | std::ios::out);
    if (!file.is_open())
        throw std::runtime_error("Не вдалося відкрити файл для читання/запису: " + fileName);

    std::string contents;
    std::string line;
    while (std::getline(file, line)) {
        contents += line;
        contents += '\n';
    }

    if (!file.eof())
        throw std::runtime_error("Помилка читання під час двонаправленої роботи з файлом.");

    file.clear();
    file.seekp(0, std::ios::beg);
    file << contents;
    if (!file.good())
        throw std::runtime_error("Помилка запису під час двонаправленої роботи з файлом.");

    file.close();
}

std::size_t CoaxialCabel::size() const {
    return cabels.size();
}

bool CoaxialCabel::operator<(const CoaxialCabel& other) const {
    if (cabels.empty() || other.cabels.empty())
        throw std::logic_error("Порівняння неможливе: один зі списків порожній.");
    return cabels.front().impedance < other.cabels.front().impedance;
}

std::ostream& operator<<(std::ostream& out, const CoaxialCabel& cable) {
    cable.display(out);
    return out;
}