#include <iostream>
int main() {
	int x = 5;
	int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, v = 0;
	while (x > 0){
		x -= 1;
		std::cin >> a1 >> a2 >> a3 >> a4 >> a5;
		if (x == 4 || x == 0) {
			if (a1 == 1 || a5 == 1) {
				v = 4;
			}
			if (a2 == 1 || a4 == 1) {
				v = 3;
			}
			if (a3 == 1) {
				v = 2;
			}
		}
		if (x == 3 || x == 1) {
			if (a1 == 1 || a5 == 1) {
				v = 3;
			}
			if (a2 == 1 || a4 == 1) {
				v = 2;
			}
			if (a3 == 1) {
				v = 1;
			}
		}
		if (x == 2) {
			if (a1 == 1 || a5 == 1) {
				v = 2;
			}
			if (a2 == 1 || a4 == 1) {
				v = 1;
			}
			if (a3 == 1) {
				v = 0;
			}
		}
	}
	std::cout << v;
}
