#include <iostream>

int main() {
	int tc; std::cin >> tc;
	while (tc--) {
		int n, m, k; std::cin >> n >> m >> k;
		if (n * (m - 1) / m > k) {
			std::cout << "YES" << std::endl;
		}
		else std::cout << "NO" << std::endl;
	}
}
