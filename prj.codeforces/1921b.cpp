#include <iostream>
#include <string>

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		std::string first;
		std::string end;
		std::cin >> n >> first >> end;
		int plus = 0;
		int minus = 0;
		for (int i = 0; i < n; i++) {
			if (first[i] == end[i]) {
				continue;
			}
			else if(first[i] == '0'){
				plus += 1;
			}
			else {
				minus += 1;
			}
		}
		std::cout << std::max(minus, plus) << std::endl;
	}
}