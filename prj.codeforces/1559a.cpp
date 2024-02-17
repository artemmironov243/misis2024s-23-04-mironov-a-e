#include <iostream>
#include <vector>
int main() {
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::vector<int> vec;
		int count = 0;
		std::cin >> count;
		for (int j = 0; j < count; j++) {
			int x = 0;
			std::cin >> x;
			vec.push_back(x);
		}
		bool p = true;
		while (p == true) {
			for (int k = 0; k < count - 1; k += 1) {
				vec[k] = vec[k] & vec[k + 1];
				vec[k + 1] = vec[k];
			}
			int r = 0;
			for (int j = 0; j < count; j++) {
				if (vec[j] == vec[0]) {
					r += 1;
				}
			}
			if (r == count) {
				break;
			}
		}
		std::cout << vec[0] << std::endl;
	}
}
