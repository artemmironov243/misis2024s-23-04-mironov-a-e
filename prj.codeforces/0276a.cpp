#include <iostream>
int main() {
	int n = 0, k = 0, f = 0, t = 0, m = -999999998, i = 0;
	std::cin >> n >> k;
	for (i = 0; i < n; i++) {
		std::cin >> f >> t;
		if (t <= k) {
			if (m < f) {
				m = f;
			}
		}
		else {
			if (f - (t - k) > m) {
				m = f - (t - k);
			}
		}
	}
	std::cout << m;
}
 
