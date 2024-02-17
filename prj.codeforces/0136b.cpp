#include <iostream>
#include <string>
#include <math.h>
int main() {
	long long a = 0, b = 0, a3 = 0, b3 = 0, c = 0, c0 = 0, n = 0;
	std::cin >> a >> b;
	long long i = 1, c1 = 1, c2 = 1;
	while (a > 2) {
		a3 += a % 3 * i;
		a /= 3;
		i *= 10;
		c1 += 1;

	}
	a3 += a * i;
	i = 1;
	while (b > 2) {
		b3 += b % 3 * i;
		b /= 3;
		i *= 10;
		c2 += 1;
	}
	b3 += b * i;
	if (c1 < c2) {
		c1 = c2;
		n = 3 * pow(10, c2 - 1);
		a3 += n;
	}
	else if (c2 < c1) {
		c2 = c1;
		n = 3 * pow(10, c1 - 1);
		b3 += n;
	}
	long long a1 = 0, b1 = 0;
	for (i = 0; i < c2; i++) {
		a1 = a3 % 10;
		a3 /= 10;
		b1 = b3 % 10;
		b3 /= 10;
		if (b1 - a1 > 0) {
			n = ((b1 - a1) % 3) * pow(10, i);
			c += n;
		}
		else if (b1 - a1 == 0) {
			c += 0 * pow(10, i);
		}
		else {
			n = ((3 + (b1 - a1)) % 3) * pow(10, i);
			c += n;
		}
	}
	for (i = 0; i < c2; i++) {
		c0 += c % 10 * pow(3, i);
		c /= 10;
	}
	std::cout << c0 << std::endl;
}
