#include <iostream>
#include <complex/complex.hpp>
int main() {
	testParse("{8.9,9");
	testParse("{8.9, 9");
	testParse("{8.9,9");

	Complex x, y;
	double d;

	// Test Case 1
	x = Complex{ 1.5, 2.0 };
	y = Complex{ 2.5, 3.5 };
	std::cout << x << " + " << y << " == " << x + y << " Expected: {4.0, 5.5}\n";
	// Test Case 2
	x = Complex{ 3.0, 5.0 };
	y = Complex{ 1.5, 2.5 };
	std::cout << x << " - " << y << " == " << x - y << " Expected: {1.5, 2.5}\n";

	// Test Case 3
	x = Complex{ 1.5, 2.0 };
	y = Complex{ 2.0, 3.0 };
	std::cout << x << " * " << y << " == " << x * y << " Expected: {-3,8.5}\n";

	// Test Case 4
	x = Complex{ 3.0, 5.0 };
	y = Complex{ 1.5, 2.5 };
	std::cout << x << " / " << y << " == " << x / y << " Expected: {2, 0}\n";

	// Test Case 5
	x = Complex{ 1.0, 2.0 };
	y = Complex{ 3.0, 4.0 };
	std::cout << x << " + " << y << " == " << x + y << " Expected: {4.0, 6.0}\n";

	// Test Case 6
	x = Complex{ 2.5, 3.0 };
	y = Complex{ 1.5, 2.0 };
	std::cout << x << " - " << y << " == " << x - y << " Expected: {1.0, 1.0}\n";

	// Test Case 7
	x = Complex{ 1.0, 2.0 };
	y = Complex{ 2.0, 3.0 };
	std::cout << x << " * " << y << " == " << x * y << " Expected: {-4.0, 7.0}\n";

	// Test Case 8
	x = Complex{ 3.0, 5.0 };
	y = Complex{ 2.0, 2.0 };
	std::cout << x << " / " << y << " == " << x / y << " Expected: {2, 0.5}\n";

	// Test Case 9
	x = Complex{ 2.0, 3.0 };
	y = Complex{ 1.0, 1.0 };
	std::cout << x << " + " << y << " == " << x + y << " Expected: {3.0, 4.0}\n";

	// Test Case 10
	x = Complex{ 3.0, 4.0 };
	y = Complex{ 1.0, 2.0 };
	std::cout << x << " - " << y << " == " << x - y << " Expected: {2.0, 2.0}\n";

	// Test Case 11
	d = 2.5;
	x = Complex{ 1.5, 1.0 };
	std::cout << d << " + " << x << " == " << d + x << " Expected: {4.0, 1.0}\n";

	// Test Case 12
	x = Complex{ 1.8, 2.2 };
	d = 3.5;
	std::cout << x << " - " << d << " == " << x - d << " Expected: {-1.7, 2.2}\n";

	// Test Case 13
	d = 2.0;
	x = Complex{ 1.5, -1.0 };
	std::cout << d << " * " << x << " == " << d * x << " Expected: {3.0, -2.0}\n";

	// Test Case 14
	x = Complex{ -4.0, 5.5 };
	d = 2.5;
	std::cout << x << " / " << d << " == " << x / d << " Expected: {-1.6, 2.2}\n";

	// Test Case 15
	d = 1.5;
	x = Complex{ 3.0, -2.0 };
	std::cout << d << " + " << x << " == " << d + x << " Expected: {4.5, -2.0}\n";

	// Test Case 16
	x = Complex{ 1.0, 2.0 };
	d = 3.5;
	std::cout << x << " - " << d << " == " << x - d << " Expected: {-2.5, 2.0}\n";

	// Test Case 17
	d = 2.0;
	x = Complex{ 1.0, -1.0 };
	std::cout << d << " * " << x << " == " << d * x << " Expected: {2.0, -2.0}\n";

	// Test Case 18
	x = Complex{ -6.0, 8.0 };
	d = 2.5;
	std::cout << x << " / " << d << " == " << x / d << " Expected: {-2.4, 3.2}\n";

	// Test Case 19
	d = 2.5;
	x = Complex{ 1.0, 1.5 };
	std::cout << d << " + " << x << " == " << d + x << " Expected: {3.5,1.5}\n";

	// Test Case 20
	x = Complex{ 3.0, -2.0 };
	d = 1.5;
	std::cout << x << " - " << d << " == " << x - d << " Expected: {1.5, -2}\n";

	// Test Case 21
	d = 4.0;
	x = Complex{ 2.0, -1.0 };
	std::cout << d << " / " << x << " == " << d / x << " Expected: {1.6, 0.8}\n";

	// Test Case 23
	x = Complex{ 11.1, 9.8 };
	y = Complex{ 7, -9 };
	x /= y;
	std::cout << x << " Expected: {-0.0807,1.2961}\n";

	// Test Case 24
	x = Complex{ 100, 90 };
	d = 10.0;
	x /= d;
	std::cout << x << " Expected: {10,9}\n";


	// Test Case 26
	x -= y;
	std::cout << x << " Expected: {1.12,2.49}\n";

	// Test Case 27
	x *= y;
	std::cout << x << " Expected: {-4.1443,7.4924}\n";

	// Test Case 28
	x = Complex{ 1,1 };
	d = 2.0;
	x += d;
	std::cout << x << " Expected: {3, 1}\n";

	// Test Case 29
	x -= d;
	x *= d;
	std::cout << x << " Expected: {2,2}\n";

	// Test Case 30
	x /= d;
	std::cout << x << " Expected: {1,1}\n";

	// Test Case 32
	x = Complex{ 12,13 };
	y = Complex{ 1,1 };
	x = y;
	std::cout << x << " Expected: {1,1}\n";

	// Test Case 33
	d = 12.5;
	x = Complex{ 12.5, 12.5 };
	std::cout << (d == x) << " Expected: 0\n";
	std::cout << (x == d) << " Expected: 0\n";

	// Test Case 34
	y = Complex{ 12.5, 12.5 };
	std::cout << (y == x) << " Expected: 1\n";
	std::cout << (x == y) << " Expected: 1\n";
	std::cout << (y != x) << " Expected: 0\n";
	std::cout << (x != y) << " Expected: 0\n";

	// Test Case 35
	y = Complex{ 1,1 };
	std::cout << (y == x) << " Expected: 0\n";
	std::cout << (x == y) << " Expected: 0\n";
	std::cout << (y != x) << " Expected: 1\n";
	std::cout << (x != y) << " Expected: 1\n";

	// Test Case 36
	d = 4.5;
	x = Complex{ 12, 35 };
	std::cout << d << " - " << x << " == " << d - x << " Expected: {-7.5, -35}\n";
}