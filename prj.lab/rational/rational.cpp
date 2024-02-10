#include "rational.hpp"

Rational::Rational(const int64_t num, const int64_t denum)
	: n_(num), de_(denum) {
	if (0 == de_) {
		throw std::invalid_argument("Zero denumenator in Rational ctor");
	}
	if (de_ < 0) {
		de_ = -denum;
		n_ = -num;
	}
	else {
		n_ = num;
		de_ = denum;
	}
	cut_back();
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}

int64_t Rational::NOK(int64_t x, int64_t y) {
	int64_t z = 2;
	while (z % x != 0 || z % y != 0) {
		z++;
	}
	return z;
}

int64_t Rational::NOD(int64_t x, int64_t y) {
	if (x != 0 && y != 0) {
		int64_t z = std::min(std::abs(x), y);
		while (std::abs(x) % z != 0 || y % z != 0) {
			z--;
		}
		return z;
	}
	return 0;
}

void Rational::cut_back() {
	int64_t d = Rational::NOD(n_, de_);
	if (d != 0) {
		n_ /= d;
		de_ /= d;
	}
}

Rational::Rational(const int64_t num)
	: Rational(num, 1)
{
}

Rational& Rational::operator=(const Rational& rhs) {
	n_ = rhs.n_;
	de_ = rhs.de_;
	return *this;
}
