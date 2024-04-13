#include <iostream>

int main() {
	long long t, a, b;
	long long m;
	std::cin >> t;
	while (t--) {
		std::cin >> a >> b >> m;
		long long sum = 2;
		sum += m / a;
		sum += m / b;
		std::cout << sum << "\n";
	}
}