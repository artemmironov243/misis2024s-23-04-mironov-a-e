#include <iostream>
#include <vector>

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		std::cin >> n;
		std::vector<int> nach;
		int x = 0;
		int min = 1000000000;
		for (int i = 0; i < n; i++) {
			std::cin >> x;
			if (x < min) {
				min = x;
			}
			nach.push_back(x);
		}
		int p = 0;
		int coun = 1;
		for (int i = 0; i < n; i++) {
			if (p == 0 && nach[i] == min) {
				p += 1;
				coun *= min + 1;
			}
			else {
				coun *= nach[i];
			}
		}
		std::cout << coun << std::endl;
	}
}