#include <iostream>
using namespace std;

class Cabel {
    double z, d, l;

public:
    Cabel() : z(50), d(5), l(1) {}
    Cabel
    (double Z, double D, double L) : z(Z), d(D), l(L) {}

    ~Cabel() {
        cout << "Об'єкт видалено\n";
    }

    void input() {
        do { cout << "Введіть опір (Ом): ";
            cin >> z;
            if (z <= 0)
                cout << "Помилка! Введіть число > 0.\n";
        } while (z <= 0);

        do {
            cout << "Введіть діаметр (мм): ";
            cin >> d;
            if (d <= 0)
                cout << "Помилка! Введіть число > 0.\n";
        } while (d <= 0);

        do {
            cout << "Введіть довжину (м): ";
            cin >> l;
            if (l <= 0)
                cout << "Помилка! Введіть число > 0.\n";
        } while (l <= 0);
    }

    void set(double Z, double D, double L) {
        if (Z > 0) z = Z;
        if (D > 0) d = D;
        if (L > 0) l = L;
    }

    void show() const {
        cout << "Опір: " << z << " Ом\n";
        cout << "Діаметр: " << d << " мм\n";
        cout << "Довжина: " << l << " м\n";
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

    cout << "\nВведення даних:\n";
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
