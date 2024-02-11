#include <iostream>
#include <sstream>
#include <rational/rational.hpp>


Rational::Rational(const int64_t num, const int64_t denum){
	if (denum == 0) {
		throw std::invalid_argument("Zero denumenator in Rational ctor");
	}
	else if (denum < 0) {
		n_ = -num;
		de_ = -denum;
	}
	else {
		n_ = num;
		de_ = denum;
	}
	cut(*this);
}
Rational::Rational(const Rational& rhs)
	: n_(rhs.n_)
	, de_(rhs.de_)
{}
Rational::Rational(const int64_t num)
	: n_(num)
	, de_(1)
{}
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
void Rational::cut(Rational&) {
	int64_t d = Rational::NOD( n_, de_);
	if (d != 0) {
		n_ /= d;
		de_ /= d;
	}
}
Rational& Rational::operator+=(const Rational& rhs) {
	int64_t d = Rational::NOK(de_, rhs.de_);
	
	n_ *=  d / de_;
	n_ += rhs.n_ * (d/rhs.de_);
	de_ = d;
	cut(*this);
	return *this;
}
Rational& Rational::operator-=(const Rational& rhs) {
	int64_t d = Rational::NOK(de_, rhs.de_);
	n_ *= d / de_;
	n_ -= rhs.n_ * (d / rhs.de_);
	de_ = d;
	cut(*this);
	return *this;
}
Rational& Rational::operator*=(const Rational& rhs) {
	n_ *= rhs.n_;
	de_ *= rhs.de_;
	cut(*this);
	return *this;
}
Rational& Rational::operator/=(const Rational& rhs) {
	if (rhs.n_ != 0) {
		n_ *= rhs.de_;
		de_ *= rhs.n_;
		cut(*this);
		return *this;
	}
	else {
		throw std::invalid_argument("you can't divide by zero");
	}
}
Rational& Rational::operator++() {
	n_ += de_;
	return *this;
}
Rational& Rational::operator--() {
	n_ -= de_;
	return *this;
}

std::istream& Rational::readFrom(std::istream& istrm) {
	int64_t r = 0;
	int64_t d = 0;
	char separat = '/';
	istrm >> r >> separat >> d;
	if (istrm.good()) {
		if (separat == separator && d != 0) {
			n_ = r;
			de_ = d;
		}
		else {
			throw std::invalid_argument("invalid data");
		}
	}
	return istrm;
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	Rational z(rhs);
	ostrm << z.get_Num() << z.separator << z.get_Den();
	return ostrm;
}

std::istream& operator>>(std::istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
	Rational z(lhs);
	z += rhs;
	return z;
}

Rational operator+(const int64_t& lhs, const Rational& rhs) {
	Rational z(lhs);
	z += rhs;
	return z;
}

Rational operator+(const Rational& lhs, const int64_t& rhs) {
	Rational z(rhs);
	z += lhs;
	return z;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
	Rational z(lhs);
	z -= rhs;
	return z;
}

Rational operator-(const int64_t& lhs, const Rational& rhs) {
	Rational z(lhs);
	z -= rhs;
	return z;
}

Rational operator-(const Rational& lhs, const int64_t& rhs) {
	Rational z(lhs);
	Rational k(rhs);
	z -= k;
	return z;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
	Rational z(lhs);
	z *= rhs;
	return z;
}

Rational operator*(const int64_t& lhs, const Rational& rhs) {
	Rational z(lhs);
	z *= rhs;
	return z;
}

Rational operator*(const Rational& lhs, const int64_t& rhs) {
	Rational z(lhs);
	Rational k(rhs);
	z *= k;
	return z;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	Rational z(lhs);
	z /= rhs;
	return z;
}

Rational operator/(const int64_t& lhs, const Rational& rhs) {
	Rational z(lhs);
	z /= rhs;
	return z;
}

Rational operator/(const Rational& lhs, const int64_t& rhs) {
	Rational z(lhs);
	Rational k(rhs);
	z /= k;
	return z;
}

bool operator==(const Rational& lhs, const int64_t& rhs) {
	Rational z(lhs);
	if (z.get_Den() == 1 && rhs == z.get_Num()) {
		return true;
	}
	return false;
}
bool operator==(const int64_t& lhs, const Rational& rhs) {
	Rational z(rhs);
	if (z.get_Den() == 1 && lhs == z.get_Num()) {
		return true;
	}
	return false;
}
bool operator!=(const Rational& lhs, const int64_t& rhs) {
	return !operator==(lhs, rhs);
}
bool operator!=(const int64_t& lhs, const Rational& rhs) {
	return !operator==(lhs, rhs);
}

bool operator>=(const Rational& lhs, const Rational& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.get_Num() >= 0);
}

bool operator>=(const Rational& lhs, const int64_t& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.get_Num() >= 0);
}

bool operator>=(const int64_t& lhs, const Rational& rhs) {
	Rational a;
	a = lhs - rhs;
	return (a.get_Num() >= 0);
}

bool operator<=(const Rational& lhs, const Rational& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.get_Num() <= 0);
}

bool operator<=(const Rational& lhs, const int64_t& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.get_Num() <= 0);
}

bool operator<=(const int64_t& lhs, const Rational& rhs) {
	Rational a;
	a = lhs - rhs;
	return (a.get_Num() <= 0);
}

bool operator>(const Rational& lhs, const Rational& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.get_Num() > 0);
}

bool operator>(const Rational& lhs, const int64_t& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.get_Num() > 0);
}

bool operator>(const int64_t& lhs, const Rational& rhs) {
	Rational a;
	a = lhs - rhs;
	return (a.get_Num() > 0);
}

bool operator<(const Rational& lhs, const Rational& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.get_Num() < 0);
}

bool operator<(const Rational& lhs, const int64_t& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.get_Num() < 0);
}

bool operator<(const int64_t& lhs, const Rational& rhs) {
	Rational a;
	a = lhs - rhs;
	return (a.get_Num() < 0);
}





