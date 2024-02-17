#include <iostream>
#include <vector>
int main() {
	int x = 0, j = 0, i = 0, countnab = 0, count = 0, mi = 1000000000, a = 0, b = 0;
	std::vector <int> min;
	std::cin >> countnab;
	for (i = 0; i < countnab; i++) {
		mi = 1000000000;
		std::cin >> count;
		std::cin >> a;
		for (j = 0; j < count - 1; j++) {
			b = a;
			x = 0;
			std::cin >> a;
			while (b <= a) {
				b += 2;
				x += 1;
			}
			if (x < mi) {
				mi = x;
			}
		}
		min.push_back(mi);
		
	}
	for (i = 0; i < min.size(); i++) {
		std::cout << min[i]<< std::endl;
	}
}
