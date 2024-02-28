#include <iostream>

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0, f = 0, a = 0, b = 0;
		bool p = true;
		std::cin >> n >> f >> a >> b;
		int x = 0;
		int time = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> x;
			if (f <= 0) {
				p = false;
				break;
			}
			else if (x - time  > (b / a)) {
				time = x;
				f -= b;
			}
			else {
				f -= (x - time) * a;
				time = x;
			}
		}
		if (f <= 0) {
			p = false;
		}
		if (p) {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}

}