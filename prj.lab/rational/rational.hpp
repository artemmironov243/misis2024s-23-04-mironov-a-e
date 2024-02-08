#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include<iostream>
#include<sstream>
#include<cstdint>

class Rational {
public:
	Rational();
	~Rational();
	Rational(const int64_t num, const int64_t denum);
	Rational(Rational&);
	Rational(const int64_t num);

	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int64_t& rhs) { return operator+=(Rational(rhs)); }
	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const int64_t& rhs) { return operator-=(Rational(rhs)); }
	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const int64_t& rhs) { return operator*=(Rational(rhs)); }
	Rational& operator/=(const Rational& rhs);
	Rational& operator/=(const int64_t& rhs) { return operator/=(Rational(rhs)); }
	Rational& operator++();
	Rational operator--();
	bool operator==(const Rational& rhs) { return (n_ == rhs.n_ && de_ == rhs.de_) || (n_ == 0 && rhs.n_ == 0) }
	bool operator!= (const Rational& rhs) { return !operator==(rhs); }
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	const char separator('/');

	const int64_t& get_Num() { return n_; }
	const int64_t& get_Den() { return d_; }

private:

	int64_t n_ = 0
		int64_t de_ = 1
		void cut_back(Rational&);
	int64_t NOD(int64_t x, int64_t y);
	int64_t NOK(int64_t x, int64_t y);
};


std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
std::istream& operator>>(std::istream& istrm, Rational& rhs);


Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator+(const Rational& lhs, const int64_t& rhs);
Rational operator+(const int64_t& lhs, const Rational& rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const int64_t& rhs);
Rational operator-(const int64_t& lhs, const Rational& rhs);

Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const int64_t& rhs);
Rational operator*(const int64_t& lhs, const Rational& rhs);

Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const int64_t& rhs);
Rational operator/(const int64_t& lhs, const Rational& rhs);

bool operator==(const Rational& lhs, const int64_t& rhs);
bool operator==(const int64_t& lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const int64_t& rhs);
bool operator!=(const int64_t& lhs, const Rational& rhs);

bool operator>=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const int64_t& rhs);
bool operator>=(const int64_t& lhs, const Rational& rhs);

bool operator>(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const int64_t& rhs);
bool operator>(const int64_t& lhs, const Rational& rhs);

bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const int64_t& rhs);
bool operator<=(const int64_t& lhs, const Rational& rhs);

bool operator<(const Rational& lhs, const Rational& rhs);
bool operator<(const Rational& lhs, const int64_t& rhs);
bool operator<(const int64_t& lhs, const Rational& rhs);

#endif
