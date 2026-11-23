#include "game.h"
#include <iostream>

using namespace std;

int numbers[4];

int user_Inp() {
    int user_inp;
    int z = 3;
    cout << "Введите число из четырех символов: ";
    cin >> user_inp;
    if (user_inp > 9999 || user_inp < 1000) {
        cout << "Число введено не верно (нужно от 1000 до 9999)\n";
        return 1;
    }
    while (user_inp > 0) {
        numbers[z--] = user_inp % 10;
        user_inp = user_inp / 10;
    }
    return 0;
}
