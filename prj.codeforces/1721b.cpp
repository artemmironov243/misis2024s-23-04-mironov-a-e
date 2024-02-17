#include <iostream>
#include <vector>
int main() {
	int count = 0, i = 0, m = 0, n = 0, sx = 0, sy = 0, d = 0, j = 0, k = 0, p = 0, c = 0;
	std::vector<int> end;
	std::cin >> count;
	for (i = 0; i < count; i++) {
		std::cin >> m >> n >> sx >> sy >> d;
		if ((sx + d < m && sy - d > 1) || (sx - d > 1 && sy + d < n)){
			end.push_back(m + n - 2);
		}
		else{
			end.push_back(-1);
		}
	}
	for (i = 0; i < end.size(); i++) {
		std::cout << end[i] << std::endl;
	}
}
 
