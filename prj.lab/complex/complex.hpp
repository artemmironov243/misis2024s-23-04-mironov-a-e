#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <sstream>

struct Complex {
	Complex() {}
	~Complex() {}
	explicit Complex(const double real);	
	Complex(const double real, const double imaginary);
	bool operator==(const Complex& rhs) const { return (re == rhs.re) && (im == rhs.im); }
	bool operator!=(const Complex& rhs) const { return !operator==(rhs); }
	Complex & operator+=(const Complex& rhs);
	Complex & operator+=(const double rhs) { return operator+=(Complex(rhs)); }
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double rhs) { return operator/=(Complex(rhs)); }
	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs) { return operator/=(Complex(rhs)); }
	std::istream & readFrom(std::istream & istrm, Complex& rhs);

	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double& rhs);
Complex operator+(const double& lhs, const Complex& rhs);

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const double& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double& rhs);

Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const double& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const double& rhs);

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double& rhs);
Complex operator/(const double& lhs, const Complex& rhs);

std::ostream& operator << (std::ostream& ostrm, const Complex& rhs);
std::istream& operator>>(std::istream& istrm, Complex& rhs);

bool testParse(const std::string& str);

bool operator==(const Complex& lhs, const double& rhs);
bool operator==(const double& lhs, const Complex& rhs);

#endif
