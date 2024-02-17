#include <iostream>
#include <vector>



int Sred(const std::vector<int>& vec) {
	int sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		sum += vec[i];
	}
	if (sum == 0) {
		return -1;
	}
	if (sum % vec.size() == 0) {
		return sum / vec.size();
	}
	else {
		return 0;
	}
}


int main() {
	int t = 0;
	std::cin >> t;
	for (int j = 0; j < t; j++) {
		int n = 0;
		std::cin >> n;
		
		std::vector<int> vec;
		int x = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> x;
			vec.push_back(x);
		}
		int z = Sred(vec);
		
		if (z == 0) {
			std::cout << "NO\n";
		}
		else if (z == -1) {
			std::cout << "YES\n";
		}
		else {
			int sum = 0;
			x = 0;
			for (int i = n - 1; i > -1; i--) {
				sum += vec[i];
				x += 1;
				if (sum > x * z) {
					std::cout << "NO\n";
					n = 0;
					break;
					
				}
			}
			if (n != 0) {
				std::cout << "YES\n";
			}
		}
	}
}

