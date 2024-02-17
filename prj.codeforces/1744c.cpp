#include <iostream>
#include <string>
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		std::string st;
		char color;
		int n = 0, ma = 0;
		std::cin >> n >> color >> st;
		for (int i = 0; i < n; i++) {
			int count = 0;
			if (st[i] == color && st[i] != 'g') {
				while (st[i] != 'g' && i != n - 1) {
					i++;
					count++;
				}
				if (i == n - 1 && st[i] != 'g') {
					count += 1;
					for (int j = 0; j < n; j++) {
						if (st[j] != 'g'){
							count += 1;
						}
						else {
							break;
						}
					}
				}
			}
			else {
				count = 0;
			}
			if (count > ma) {
				ma = count;
			}
		}
		std::cout << ma << std::endl;
	}
}
