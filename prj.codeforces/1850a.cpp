#include <iostream>
#include <string>
#include <vector>
int main() {
	std::vector <std::string> ch;
	int n = 0, a = 0, b = 0, c = 0, i = 0;
	std::cin >> n;
	for (i = 0; i < n; i++) {
		std::cin >> a >> b >> c;
		if (a + b >= 10 || b + c >= 10 || a + c >= 10) {
			ch.push_back("YES");
		}
		else {
			ch.push_back("NO");
		}
	}
	for (i = 0; i < ch.size(); i++) {
		std::cout << ch[i] << std::endl;
	}
}
