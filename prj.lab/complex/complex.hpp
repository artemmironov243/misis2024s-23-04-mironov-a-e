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
	std::istream& readFrom(std::istream& istrm, Complex& rhs);

	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftbrace{ '{' };
	static const char separator{ '.' };
	static const char rightbrace{ '}' };
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

std::istream& operator >>(std::istream& istrm, Complex& rhs);
std::ostream& operator <<(std::ostream& ostrm, const Complex& rhs);

bool testing(const std::string& str);

bool operator==(const Complex& lhs, const double& rhs);
bool operator==(const double& lhs, const Complex& rhs);

#endif 
