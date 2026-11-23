#include <iostream>
#include <random>
#include "game.h" 

using namespace std;

int main() {
	int numinp[4];
	int bull = 0;

	random_device r;

	while (true) {
		default_random_engine e1(r());
		uniform_int_distribution<int> uniform_dist(1000, 9999);

		int i = uniform_dist(e1);

		int x = 3;

		while (i > 0) {
			numinp[x--] = i % 10;
			i = i / 10;
		}

		int count = 0;

		for (int v = 0; v < 4; v++) {
			for (int m = 0; m < 4; m++) {
				if (v != m) {
					if (numinp[v] == numinp[m]) {
						count++;
					}
				}
			}
		}

		if (count == 0) {
			// тут просто вывод числа которое комп загадал
			for (int ii = 0; ii < 4; ii++) {
				cout << numinp[ii];
			}
			cout << "\n";
			break;
		}
	}

	while (bull != 4) {
		if (user_Inp() == 0) {
			int cow = 0;
			int z = 0;
			bull = 0;
			while (true) {
				if (numbers[z] == numinp[z]) {
					bull++;
				} else {
					for (int p = 0; p < 4; p++) {
						if (numbers[z] == numinp[p]) {
							cow++;
						}
					}
				}
				z++;
				if (z >= 4) {
					break;
				}
			}

			cout << bull << " быка " << cow << " коровы \n";

		} else {
			return 1;
		}
	}
	return 0;
}
