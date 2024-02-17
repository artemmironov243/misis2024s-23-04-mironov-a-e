#include <iostream>
#include <string>

int main() {
	int t = 0;
	std::cin >> t;
	std::string alph = "0abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < t; i++) {
		int val = 0;
		std::cin >> val;
		std::string world = "";
		int x = 1;
		while (val - x > 26 * 2) {
			x++;
		}
		val -= x;
		world += alph[x];
		while (val - x > 26) {
			x++;
		}
		world += alph[x];
		world += alph[val - x];
		std::cout << world << std::endl;
	}
}