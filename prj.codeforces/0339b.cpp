#include <iostream>
#include <vector>
int main() {
	int n = 0, m = 0, k = 1;
	long long t = 0;
	std::cin >> n >> m;
	while (m--) {
		int delo = 0;
		std::cin >> delo;
		if (delo >= k) {
			t += delo - k;
			k = delo;
		}
		else {
			t += n + 1 - k;
			t += delo - 1;
			k = delo;
		}
	}
	std::cout << t;
}
