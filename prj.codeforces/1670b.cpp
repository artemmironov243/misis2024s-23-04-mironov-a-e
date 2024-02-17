#include <iostream>
#include <string>
#include <vector>
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int count = 0, i = 0, j = 0;
	std::vector <int> ve;
	std::cin >> count;
	for (i = 0; i < count; i++) {
		std::string st;
		std::vector <char> ch;
		std::string s;
		int n = 0, sym = 0, ma = 0, k = 0, r = 0;
		std::cin >> n >> st >> sym;
		s = "";
		for (j = 0; j < sym; j++) {
			char l;
			std::cin >> l;
			ch.push_back(l);
		}
		ma = 0;
		r = 0;
		for (j = 0; j < n; j++) {
			for (k = 0; k < sym; k++) {
				if (st[j] == ch[k]) {
					if(j - r > ma) {
						ma = j - r;
					}
					r = j;
					break;
				}
			}
		}
		ve.push_back(ma);
	}
	for (i = 0; i < ve.size(); i++) {
		std::cout << ve[i] << std::endl;
	}
}
 
