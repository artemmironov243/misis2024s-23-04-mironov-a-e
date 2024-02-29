#pragma once
#ifndef COMPLEX_COMPLEX_HPP
#define COMPLEX_COMPLEX__HPP

#include <iostream>
#include <sstream>

struct Complex {
	Complex() {};
	Complex(double real);
	Complex(double real, double imaginary);
	Complex(const Complex& rhs);
	Complex& operator=(const Complex& rhs) {
		re = rhs.re;
		im = rhs.im;
		return *this;
	}
	~Complex() {};
	bool operator ==(const Complex& rhs) const { return (re == rhs.re && im == rhs.im); }
	bool operator != (const Complex& rhs) const { return !operator==(rhs); }
	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double rhs) { return operator*=(Complex(rhs)); }
	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs) { return operator/=(Complex(rhs)); }

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);


	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char separator{ '.' };
	static const char rightBrace{ '}' };
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double& rhs);
Complex operator+(const double& lhs, const Complex& rhs);

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double& rhs);
Complex operator-(const double& lhs, const Complex& rhs);

Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const double& rhs);
Complex operator*(const double& lhs, const Complex& rhs);

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double& rhs);
Complex operator/(const double& lhs, const Complex& rhs);

inline std::ostream& operator<<(std::ostream& os, const Complex& complex) {
	return complex.writeTo(os);
};
inline std::istream& operator>>(std::istream& is, Complex& complex) {
	return complex.readFrom(is);
};

bool testing(const std::string& str);

bool operator==(const Complex& lhs, const double& rhs);
bool operator==(const double& lhs, const Complex& rhs);

#endif 
