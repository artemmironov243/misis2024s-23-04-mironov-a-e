#include <iostream>
#include <vector>

int main() {
	int t = 0;
	std::cin >> t;
	for (int h = 0; h < t; h++) {
		int n = 0, x = 0, y = 0, count = 0;
		std::cin >> n >> x >> y;
		std::vector<int> vec;
		int val = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> val;
			vec.push_back(val);
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((vec[i] + vec[j]) % x == 0 && (vec[j] - vec[i]) % y == 0) {
					count += 1;
				}
			}
		}
		std::cout << count << std::endl;
	}
}