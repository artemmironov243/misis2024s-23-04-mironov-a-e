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

Rational& Rational::operator+=(const Rational& rhs) {
	if (de_ == rhs.de_) {
		n_ += rhs.n_;
	}
	else {
		int64_t a = Rational::NOK(de_, rhs.de_);
		n_ = n_ * a / de_ + rhs.n_ * a / rhs.de_;
		de_ = a;
	}
	cut_back();
	return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
	n_ *= rhs.n_;
	de_ *= rhs.de_;
	cut_back();
	return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
	if (0 == rhs.n_) {
		throw std::invalid_argument("Zero denumenator in Rational ctor");
	}
	n_ *= rhs.de_;
	de_ *= rhs.n_;
	cut_back();
	return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
	if (de_ == rhs.de_) {
		n_ -= rhs.n_;
	}
	else {
		int64_t a = Rational::NOK(de_, rhs.de_);
		n_ = n_ * a / de_ - rhs.n_ * a / rhs.de_;
		de_ = a;
	}
	cut_back();
	return *this;
}

Rational& Rational::operator++() {
	n_ += de_;
	cut_back();
	return *this;
}

Rational& Rational::operator--() {
	n_ -= de_;
	cut_back();
	return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
	Rational sum(lhs);
	sum += rhs;
	return sum;
}

Rational operator+(const Rational& lhs, const int64_t& rhs) {
	Rational sum(lhs);
	sum += rhs;
	return sum;
}

Rational operator+(const int64_t& lhs, const Rational& rhs) {
	Rational sum(rhs);
	sum += lhs;
	return sum;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
	Rational minus(lhs);
	minus -= rhs;
	return minus;
}

Rational operator-(const Rational& lhs, const int64_t& rhs) {
	Rational minus(lhs);
	minus -= rhs;
	return minus;
}

Rational operator-(const int64_t& lhs, const Rational& rhs) {
	Rational minus(rhs);
	minus -= lhs;
	minus *= -1;
	return minus;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
	Rational umn(lhs);
	umn *= rhs;
	return umn;
}

Rational operator*(const Rational& lhs, const int64_t& rhs) {
	Rational umn(lhs);
	umn *= rhs;
	return umn;
}

Rational operator*(const int64_t& lhs, const Rational& rhs) {
	Rational umn(rhs);
	umn *= lhs;
	return umn;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	Rational del(lhs);
	del /= rhs;
	return del;
}

Rational operator/(const Rational& lhs, const int64_t& rhs) {
	Rational del(lhs);
	del /= rhs;
	return del;
}

Rational operator/(const int64_t& lhs, const Rational& rhs) {
	Rational del(1, 1);
	del /= rhs;
	del *= lhs;
	return del;
}

bool operator==(const Rational& lhs, const int64_t& rhs) {
	if ((lhs.get_Num() == rhs && lhs.get_Den() == 1) || (lhs.get_Num() == 0 && rhs == 0)) {
		return true;
	}
	return false;
}

bool operator==(const int64_t& lhs, const Rational& rhs) {
	if ((rhs.get_Num() == lhs && rhs.get_Den() == 1) || (rhs.get_Num() == 0 && lhs == 0)) {
		return true;
	}
	return false;
}

bool operator!=(const Rational& lhs, const int64_t& rhs) {
	if (lhs.get_Num() == rhs && lhs.get_Den() == 1) {
		return false;
	}
	return true;
}

bool operator!=(const int64_t& lhs, const Rational& rhs) {
	if (rhs.get_Num() == lhs && rhs.get_Den() == 1) {
		return false;
	}
	return true;
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

std::ostream& Rational::writeTo(std::ostream& ostrm) const {
	ostrm << n_ << separator << de_;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) {
	char separator(0);
	int64_t num(0);
	int64_t denum(0);
	istrm >> num >> separator >> denum;
	if (istrm.good()) {
		if ((Rational::separator == separator)) {
			n_ = num;
			de_ = denum;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}
