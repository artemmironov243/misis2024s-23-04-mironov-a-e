#include <iostream>

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int a = 0, b = 0;
		std::cin >> a >> b;
		int p = 0;
		for (int i = 2; i < a * b + 1; i++) {
			if (a * b % i == 0 && i != a && i != b) {
				p = 1;
			}
		}
		if ((a % 2 != 0 || b % 2 != 0) && ((a % 2 == 0 && a / 2 == b) || (b % 2 == 0 && b / 2 == a))) {
			std::cout << "No" << "\n";
		}
		else if (p == 1) {
			std::cout << "Yes" << "\n";
		}
		else {
			std::cout << "No" << "\n";
		}
	}
}