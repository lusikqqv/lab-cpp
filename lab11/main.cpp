#include <iostream>
#include "elemmanager1.h"

using namespace std;

int main() {
    EmitterManager manager;

    cout << "ЕЛЕКТРОМАГНІТНІ ВИПРОМІНЮВАЧІ\n";

    manager.input();
    manager.output();
    manager.totalPower();
    manager.maxPower();

    return 0;
}