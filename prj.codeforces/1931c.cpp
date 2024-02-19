#include <iostream>
#include <vector>
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		std::cin >> n;
		std::vector<int> vec;
		int x = 0;
		while (n--) {
			std::cin >> x;
			vec.push_back(x);
		}
		x = vec[0];
		int sum_front = 1;
		int sum_back = 1;
		for (int i = 1; i < vec.size(); i++) {
			if (vec[i] == x) {
				sum_front += 1;
			}
			else {
				break;
			}
		}
		x = vec[vec.size() - 1];
		for (int i = vec.size() - 2; i > -1; i--) {
			if (vec[i] == x) {
				sum_back += 1;
			}
			else {
				break;
			}
		}
		if (vec[0] == vec[vec.size() - 1]) {
			if (sum_front != vec.size()) {
				std::cout << ((vec.size() - sum_front) - sum_back) << std::endl;
			}
			else {
				std::cout << 0 << std::endl;
			}
		}
		else if (sum_front >= sum_back) {
			std::cout << vec.size() - sum_front << std::endl;
		}
		else {
			std::cout << vec.size() - sum_back << std::endl;
		}
	}
}