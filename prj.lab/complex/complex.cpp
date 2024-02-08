#include <iostream>
#include <sstream>
#include <complex/complex.hpp>

std::ostream& operator << (std::ostream& ostrm, const Complex& rhs)
{
	ostrm << rhs.leftBrace << rhs.re << rhs.separator << rhs.im << rhs.rightBrace;
	return ostrm;
}

std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
	return rhs.readFrom(istrm, rhs);
}

bool testParse(const std::string& str)
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

Complex::Complex(const double real)
	: Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
	: re(real)
	, im(imaginary)
{
}

Complex& Complex::operator*=(const Complex& rhs)
{
	re = rhs.re;
	im = rhs.im;
	return *this;
}

Complex& Complex::operator+=(const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}


Complex& Complex::operator-=(const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}


Complex& Complex::operator*=(const Complex& rhs)
{
	double k, e;
	k = re;
	e = im;
	re *= rhs.re;
	im *= rhs.im;
	re -= im;
	im = k * rhs.im + e * rhs.re;
	return *this;
}


Complex& Complex::operator/=(const Complex& rhs)
{
	double k;
	k = re;
	if ((rhs.im * rhs.im + rhs.re * rhs.re) == 0) {
		throw std::invalid_argument("Division by zero");
	}
	re = (re * rhs.re + im * rhs.im) / (rhs.im * rhs.im + rhs.re * rhs.re);
	im = (im * rhs.re - k * rhs.im) / (rhs.im * rhs.im + rhs.re + rhs.re);
	return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex operator+(const Complex& lhs, const double& rhs)
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex operator+(const double& lhs, const Complex& rhs)
{
	Complex sum(rhs);
	sum += lhs;
	return sum;
}
Complex operator-(const Complex& lhs, const Complex& rhs)
{
	Complex minus(lhs);
	minus -= rhs;
	return minus;
}

Complex operator-(const Complex& lhs, const double& rhs)
{
	Complex minus(lhs);
	minus -= rhs;
	return minus;
}

Complex operator-(const double& lhs, const Complex& rhs)
{
	Complex minus(rhs);
	minus -= lhs;
	return minus;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
	Complex umn(lhs);
	umn *= rhs;
	return umn;
}

Complex operator*(const double& lhs, const Complex& rhs)
{
	Complex umn(rhs);
	umn *= lhs;
	return umn;
}

Complex operator*(const Complex& lhs, const double& rhs)
{
	Complex umn(lhs);
	umn *= rhs;
	return umn;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
	Complex raz(lhs);
	raz /= rhs;
	return raz;
}

Complex operator/(const double& lhs, const Complex& rhs)
{
	Complex raz(rhs);
	raz /= lhs;
	return raz;
}

Complex operator/(const Complex& lhs, const double& rhs)
{
	Complex raz(lhs);
	raz /= rhs;
	return raz;
}

bool operator==(const double& rhs, const Complex & lhs){
	return false;
}

bool operator==(const Complex& rhs, const double& lhs){
	return false;
}

std::istream& Complex::readFrom(std::istream& istrm, Complex& rhs)
{
	char leftBrace = '{';
	double real = 0.0;
	char comma = '.';
	double imaganary = 0.0;
	char rightBrace = '}';
	istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
			&& (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaganary;
			rhs = Complex(re, im);

		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}
