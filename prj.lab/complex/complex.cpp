#include <iostream>
#include <sstream>
#include <complex/complex.hpp>

bool testing(const std::string& str)
{
	std::stringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good()) {
		std::cout << "Read sucsess:" << str << " -> " << z << "\n";
	}
	else {
		std::cout << "Read error:" << str << " -> " << z << "\n";
	}
	return istrm.good();
}

std::istream& Complex::readFrom(std::istream& istrm, Complex& rhs) {
	char leftBrace = '{';
	double real = 0.0;
	char comma = '.';
	double imag = 0.0;
	char rightBrace = '}';
	istrm >> leftBrace >> re >> comma >> im >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftbrace == leftBrace) && (Complex::separator == comma) && (Complex::rightbrace == rightBrace)) {
			re = real;
			im = imag;
			rhs = Complex(re, im);
		}
	}
}

std::istream& operator>>(std::istream& istrm, Complex& rhs) {
	return rhs.readFrom(istrm, rhs);
}

std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
	ostrm << rhs.leftbrace << rhs.re << rhs.separator << rhs.im << rhs.rightbrace;
	return ostrm;
}

Complex& Complex::operator+=(const Complex& rhs) {
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex& Complex::operator-=(const Complex& rhs) {
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
	double real = 0.0;
	double imag = 0.0;
	real = re * rhs.re - im * rhs.im;
	imag = re * rhs.im + rhs.re * im;
	re = real;
	im = imag;
	return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
	double k;
	k = re;
	if ((rhs.im * rhs.im + rhs.re * rhs.re) == 0) {
		throw std::invalid_argument("Division by zero");
	}
	re = (re * rhs.re + im * rhs.im) / (rhs.im * rhs.im + rhs.re * rhs.re);
	im = (im * rhs.re - k * rhs.im) / (rhs.im * rhs.im + rhs.re + rhs.re);
	return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
	double re = rhs.re + lhs.re;
	double im = rhs.im + lhs.im;
	return Complex(re, im);
}

Complex operator+(const double& lhs, const Complex& rhs) {
	double re = rhs.re + lhs;
	double im = rhs.im;
	return Complex(re, im);
}

Complex operator+(const Complex& lhs, const double& rhs) {
	double re = rhs + lhs.re;
	double im = lhs.im;
	return Complex(re, im);
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
	double re = lhs.re - rhs.re;
	double im = lhs.im - rhs.im ;
	return Complex(re, im);
}

Complex operator-(const double& lhs, const Complex& rhs) {
	double re = lhs - rhs.re;
	double im = - rhs.im;
	return Complex(re, im);
}

Complex operator-(const Complex& lhs, const double& rhs) {
	double re = lhs.re - rhs;
	double im = lhs.im;
	return Complex(re, im);
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
	double re = rhs.re * lhs.re - rhs.im * lhs.im;
	double im = lhs.re * rhs.im + rhs.re * lhs.im;
	return Complex(re, im);
}

Complex operator*(const double& lhs, const Complex& rhs) {
	Complex umn(rhs);
	umn *= lhs;
	return umn;
}

Complex operator*(const Complex& lhs, const double& rhs) {
	Complex umn(rhs);
	umn *= lhs;
	return umn;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
	Complex del(lhs);
	del /= rhs;
	return del;
}

Complex operator/(const double& lhs, const Complex& rhs) {
	Complex del(lhs);
	del /= rhs;
	return del;
}

Complex operator/(const Complex& lhs, const double& rhs) {
	Complex del(lhs);
	del /= rhs;
	return del;
}

