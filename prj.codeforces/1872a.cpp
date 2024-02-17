#include <iostream>
#include <vector>
int main() {
	int a = 0, b = 0, c = 0, count = 0, i = 0, x = 0, l = 0, su = 0;
	std::cin >> x;
	std::vector <int> li;
	for (i = 0; i < x; i++) {
		count = 0;
		std::cin >> a >> b >> c;
		if (a > b) {
			while (b < a) {
				b += c;
				a -= c;
				count += 1;
			}
		}
		else {
			while (a < b) {
				a += c;
				b -= c;
				count += 1;
			}
		}
		li.push_back(count);
	}
	
	for (i = 0; i < li.size(); i++) {
		std::cout << li[i] << std::endl;
	}
}
