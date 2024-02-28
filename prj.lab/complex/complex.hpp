#ifndef COMPLEX_COMPLEX_HPP
#define COMPLEX_COMPLEX__HPP

#include <iostream>
#include <sstream>

struct Complex {
	Complex() = default;
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);
	Complex(const Complex& rhs);
	Complex& operator=(const Complex& rhs) {
		re = rhs.re;
		im = rhs.im;
		return *this;
	}
	~Complex() = default;
	bool operator ==(const Complex& rhs) const noexcept { return (re == rhs.re && im == rhs.im); }
	bool operator != (const Complex& rhs) const noexcept { return !operator==(rhs); }
	Complex& operator+=(const Complex& rhs) noexcept;
	Complex& operator+=(const double rhs) noexcept { return operator+=(Complex(rhs)); }
	Complex& operator-=(const Complex& rhs) noexcept;
	Complex& operator-=(const double rhs) noexcept { return operator-=(Complex(rhs)); }
	Complex& operator*=(const Complex& rhs) noexcept;
	Complex& operator*=(const double rhs) noexcept { return operator*=(Complex(rhs)); }
	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs) { return operator/=(Complex(rhs)); }
	std::istream& ReadFrom(std::istream& istrm, Complex& rhs) noexcept;
	srd::istream& WriteTo(std::ostream& ostrm) const noexcept;

	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char separator{ '.' };
	static const char rightBrace{ '}' };
};

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept;
Complex operator+(const Complex& lhs, const double& rhs) noexcept;
Complex operator+(const double& lhs, const Complex& rhs) noexcept;

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept;
Complex operator-(const Complex& lhs, const double& rhs) noexcept;
Complex operator-(const double& lhs, const Complex& rhs) noexcept;

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept;
Complex operator*(const Complex& lhs, const double& rhs) noexcept;
Complex operator*(const double& lhs, const Complex& rhs) noexcept;

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double& rhs);
Complex operator/(const double& lhs, const Complex& rhs);

bool testing(const std::string& str);

bool operator==(const Complex& lhs, const double& rhs);
bool operator==(const double& lhs, const Complex& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) noexcept {
  return rhs.WriteTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) noexcept {
  return rhs.ReadFrom(istrm);
}

#endif 

