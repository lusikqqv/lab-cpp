#include <iostream>
using namespace std;

class Cabel {
    double z, d, l;

public:
    Cabel() : z(50), d(5), l(1) {}
    Cabel(double Z, double D, double L) : z(Z), d(D), l(L) {}

    ~Cabel() { cout << "Об'єкт видалено\n"; }

    void input() {
        cout << "Введіть опір (Ом): ";
        cin >> z;
        cout << "Введіть діаметр (мм): ";
        cin >> d;
        cout << "Введіть довжину (м): ";
        cin >> l;

        if (z <= 0 || d <= 0 || l <= 0)
            cout << "Помилка: значення повинні бути > 0!\n";
    }

    void set(double Z, double D, double L) {
        if (Z > 0) z = Z;
        if (D > 0) d = D;
        if (L > 0) l = L;
    }

    void show() const {
        cout << "Опір: " << z << " Ом\n"
             << "Діаметр: " << d << " мм\n"
             << "Довжина: " << l << " м\n";
    }
};

void change(Cabel& c) {
    c.set(75, 8, 25);
}

int main() {
    Cabel cabel1;
    Cabel cabel2(50, 6, 10);

    cout << "Кабель 1:\n";
    cabel1.show();

    cout << "\nВведіть дані для кабелю :\n";
    cabel1.input();

    cout << "\nВведені дані:\n";
    cabel1.show();

    cout << "\nКабель 2:\n";
    cabel2.show();

    change(cabel2);

    cout << "\nПісля зміни через посилання:\n";
    cabel2.show();

    return 0;
}
