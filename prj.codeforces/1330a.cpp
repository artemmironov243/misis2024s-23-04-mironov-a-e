#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	int count = 0, d = 0, i = 0, j = 0, x = 0, r = 0;
	std::cin >> count;
	std::vector <int> en;
	for (i = 0; i < count; i++) {
		int were = 0, will = 0;
		std::cin >> were >> will;
		d = were + will;
		std::vector<int> arr;
		for (j = 0; j < were + will; j++){
			arr.push_back(0);
		}
		for (j = 0; j < were; j++) {
			std::cin >> x;
			if (x <= will + were) {
				arr[x - 1] = x;
			}
		}
		for (j = 0; j < arr.size(); j++) {
			if (arr[j] == 0 && will > 0) {
				will -= 1;
				arr.at(j) = 1;
			}
		}
		r = 0;
		for (j = 0; j < arr.size(); j++) {
			if (arr[j] > 0) {
				r += 1;
			}
			else {
				break;
			}
		}
		en.push_back(r);
	}
	for (i = 0; i < en.size(); i++) {
		std::cout << en[i] << std::endl;
	}
}
