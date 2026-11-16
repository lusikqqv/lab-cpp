#ifndef CABEL_H
#define CABEL_H

class Cabel {
private:
    double* data;

public:
    // Конструктор з параметрами
    Cabel(double impedance, double diameter, double length);

    // Деструктор
    ~Cabel();

    // Конструктор копіювання
    Cabel(const Cabel& other);

    // Оператор присвоювання копіюванням
    Cabel& operator=(const Cabel& other);

    // Конструктор переміщення
    Cabel(Cabel&& other) noexcept;

    // Оператор присвоювання переміщенням
    Cabel& operator=(Cabel&& other) noexcept;

    // Методи роботи з кабелем
    void input();
    void output() const;
};

#endif
