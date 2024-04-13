#include <iostream>
#include <set>
#include <vector>

int main() {
	std::string strin;
	std::vector<char> vec;
	std::cin >> strin;
	for (int i = 0; i < strin.size(); i++) {
		int flag = 0;
		for (int j = 0; j < vec.size(); j++) {
			if (vec[j] == strin[i]) {
				flag = 1;
			}
		}
		if (!flag) {
			vec.push_back(strin[i]);
		}
	}
	if (vec.size() % 2 == 0) {
		std::cout << "CHAT WITH HER!" << "\n";
	}
	else {
		std::cout << "IGNORE HIM!" << "\n";
	}
}