#include <iostream>
#include <vector>
#include <set>

int main() {
	int t = 0, n = 0, a = 0, k = 0, coun = 0;
	std::cin >> t;
	std::vector <int> answer;
	
	while (t--) {
		std::set <int> myset;
		std::vector<int> condition = { 0, 2147483647 };
		std::cin >> n;
		while (n--) {
			std::cin >> a >> k;
			switch (a) {
			case 1:
				if (condition[0] < k) {
					condition[0] = k;
				}
				break;
				case 2 :
					if (condition[1] > k) {
						condition[1] = k;
					}
					break;
				case 3:
					condition.push_back(k);
					break;
			}
		}
		coun = condition[1] - condition[0] + 1;
		for (int j = 2; j < condition.size(); j++) {
			myset.insert(condition[j]);
		}
		for (auto& iter : myset) {
			if (iter <= condition[1] && iter >= condition[0]) {
				coun -= 1;
			}
		}
		if (coun < 0) {
			coun = 0;
		}
		answer.push_back(coun);
	}
	for (int i = 0; i < answer.size(); i++) {
		std::cout << answer[i] << std::endl;
	}
}