#include <iostream>
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		std::cin >> n;
		std::cout << 1 << std::endl;
		for (int i = 1; i < n; i++) {
			std::cout << 1 << " ";
			for (int j = 0; j < i - 1; j++) {
				std::cout << 0 << " ";
			}
			std::cout << 1 << std::endl;
		}
	}
}
