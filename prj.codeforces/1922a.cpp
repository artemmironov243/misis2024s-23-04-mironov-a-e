#include <iostream>
#include <string>

int main() {
	int t = 0, n = 0;
	bool p = false;
	std::string a;
	std::string b;
	std::string c;
	std::cin >> t;
	while (t--) {
		n = 0;
		p = false;
		std::cin >> n >> a >> b >> c;
		for (int i = 0; i < n; i++) {
			if (a[i] != c[i] && b[i] != c[i]) {
				std::cout << "YES" << std::endl;
				p = true;
				break;
			}
		}
		if (!p) {
			std::cout << "NO" << std::endl;
		}
	}
}