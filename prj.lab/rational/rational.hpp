#pragma once
#ifndef RATIONAL_HPP
#define RATIONAL_HPP


#include <iostream>
#include <sstream>

class Rational {
public:
	Rational() {};
	~Rational() {};
	Rational(const int64_t num, const int64_t denum);
	Rational(const int64_t num);
	Rational(const Rational& rhs);

	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int64_t rhs) { return operator+=(Rational(rhs)); }
	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const int64_t rhs) { return operator-=(Rational(rhs)); }
	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const int64_t rhs) {return operator*=(Rational(rhs)); }
	Rational& operator/=(const Rational& rhs);
	Rational& operator/=(const int64_t rhs) { return operator/=(Rational(rhs)); }

	Rational& operator++();
	Rational& operator--();

	bool operator==(const Rational& rhs) const { return (n_ == rhs.n_ && de_ == rhs.de_) || (n_ == 0 && rhs.n_ == 0); }
	bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
	std::istream& readFrom(std::istream& istrm);
	
	static const char separator = '/';

	const int64_t& get_Num() { return n_; }
	const int64_t& get_Den() { return de_; }

private:
	int64_t n_ = 0;
	int64_t de_ = 1;
	void cut(Rational&);
	int64_t NOD(int64_t x, int64_t y);
	int64_t NOK(int64_t x, int64_t y);
};

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

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
std::istream& operator>>(std::istream& istrm, Rational& rhs);

#endif
