#include <iostream>
#include <string>
int main() {
	int i = 0, count = 0, x = 0, del = 0;
	std::string name;
	std::cin >> i;
	std::cin >> name;
	for (x = 0; x < i; x++) {
		if (name[x] == 'x') {
			count += 1;
		}
		else {
			if (count > 2) {
				del += count - 2;
			}
			count = 0;
		}
		if (i - 1 == x && count > 2){
			del += count - 2;
		}
	}
	std::cout << del;
}
