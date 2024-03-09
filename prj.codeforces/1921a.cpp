#include <iostream>

int main() {
	int t = 0, x = 0, y = 0, x1 = 0, y1 = 0;
	std::cin >> t;
	while (t--) {
		std::cin >> x1 >> y1;
		for (int i = 0; i < 3; i++) {
			std::cin >> x >> y;
			if (x1 == x) {
				std::cout << std::abs(y - y1) * std::abs(y - y1) << std::endl;
			}
		}
	}
}