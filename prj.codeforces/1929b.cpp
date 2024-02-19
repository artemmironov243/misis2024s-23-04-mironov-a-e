#include <iostream>

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0, k = 0, coun = 0;
		std::cin >> n >> k;
		if (k > n * 2) {
			coun = n;
			k -= n * 2;
			for (int i = 0; i < n - 2; i++) {
				if (k < 1) {
					break;
				}
				k -= 2;
				coun += 1;
			}
			while (k > 0) {
				k -= 1;
				coun += 1;
			}
			
		}
		else {
			coun += k / 2 + k % 2;
		}
		std::cout << coun << std::endl;
	}
}