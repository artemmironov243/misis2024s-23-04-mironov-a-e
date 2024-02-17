#include <iostream>
int main(){
	int k = 0, n = 0, w = 0, i = 0;
	std::cin >> k >> n >> w;
	for (i = 0; i < w; i++) {
		n -= k;
		k += k;
	}
	std::cout << n;
}
