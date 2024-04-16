#include <iostream>

int main() {
	long t;
	std::cin >> t;
	while (t--) {
		int n, a, b;
		std::cin >> n >> a >> b;
		if (b > 2 * a) b = 2 * a;
		std::cout << (n / 2) * b + (n % 2) * a << "\n";
	}
}