#include <iostream>
#include <vector>
#include <array>
#include <string>
int main() {
	std::vector<int> comp;
	std::vector<std::string> st;
	int count = 0, f = 0, n = 0, k = 0, x = 0, y = 0, i = 0, j = 0, l = 0, xl = 0, yl = 0, r = 0, p = 0;
	std::cin >> count;
	for (j = 0; j < count; j++) {
		std::string s = "";
		std::cin >> n >> k >> x >> y;
		l = n / k;
		comp.push_back(k);
		comp.push_back(l);
		xl = x % k;
		if (xl == 0) {
			xl = k;
		}
		yl = y % k;
		if (yl == 0) {
			yl = k;
		}
		for (i = 0; i < k; i++) {
			s += ".";
		}
		r = 0;
		for (i = 0; i < k; i++) {
			std::string X = "X";
			if (i == xl - 1) {
				s.replace(yl - 1, 1, X);
			}
			else {
				if (r == yl - 1) {
					s.replace(yl, 1, X);
					r += 2;
				}
				else {
					s.replace(r, 1, X);
					r += 1;
				}
			}
				
			st.push_back(s);
			s = "";
			for (p = 0; p < k; p++) {
				s += ".";
			}
		}
	}
	r = 0;
	for (i = 0; i < comp.size(); i += 2){// количество наборов
		for (j = 0; j < comp[i + 1]; j++) { // количество повторений блоков
			for (p = r; p < comp[i] + r; p++ ) { // кол-во строк в блоке
				for (f = 0; f < comp[i + 1]; f++) { // кол-во столбцов
					if (f == comp[i + 1] - 1) {
						std::cout << st[p] << std::endl;
					}
					else {
						std::cout << st[p];
					}
				}
			}
		}
		r += comp[i];
	}
}
