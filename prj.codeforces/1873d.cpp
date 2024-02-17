#include <iostream>
#include <vector>
#include <string>
int main() {
	int count = 0;
	std::vector<int> vec;
	std::cin >> count;
	while (count--) {
		int n = 0, k = 0, r = 0;
		std::cin >> n >> k;
		std::string st;
		std::cin >> st;
		for (int i = 0; i < n; i++) {
			if (st[i] == 'B') {
				i += (k - 1);
				r += 1;
			}
		}
		vec.push_back(r);
	}
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << std::endl;
	}
}
