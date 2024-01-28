#include "rational_number.h"

RationalNumber::RationalNumber()
{
	numerator_ = 0;
	denominator_ = 1;
}

RationalNumber::RationalNumber(int numerator, int denominator)
{
	numerator_ = numerator;
	denominator_ = denominator;
	if (denominator == 0)
	{
		denominator_ = 1;
		numerator_ = 0;
	}
	Simplify();
}

int RationalNumber::numerator() const
{
	return numerator_;
}

int RationalNumber::denominator() const
{
	return denominator_;
}

RationalNumber& RationalNumber::operator*=(const RationalNumber& rhs)
{
	numerator_ = this->numerator() * rhs.numerator();
	denominator_ = this->denominator() * rhs.denominator();
	Simplify();
	return *this;
}

RationalNumber& RationalNumber::operator/=(const RationalNumber& rhs)
{
	numerator_ = this->numerator() * rhs.denominator();
	denominator_ = this->denominator() * rhs.numerator();
	Simplify();
	return *this;
}

RationalNumber& RationalNumber::operator+=(const RationalNumber& rhs)
{
	numerator_ = (this->numerator() * rhs.denominator()) + (this->denominator() * rhs.numerator());
	denominator_ = (this->denominator() * rhs.denominator());
	Simplify();
	return *this;
}

RationalNumber& RationalNumber::operator-=(const RationalNumber& rhs)
{
	numerator_ = (this->numerator() * rhs.denominator()) - (this->denominator() * rhs.numerator());
	denominator_ = (this->denominator() * rhs.denominator());
	Simplify();
	return *this;
}

RationalNumber RationalNumber::operator*(const RationalNumber& rhs) const
{
	RationalNumber result = *this;
	result *= rhs;
	return result;
}

RationalNumber RationalNumber::operator/(const RationalNumber& rhs) const
{
	RationalNumber result = *this;
	result /= rhs;
	return result;
}

RationalNumber RationalNumber::operator+(const RationalNumber& rhs) const
{
	RationalNumber result = *this;
	result += rhs;
	return result;
}

RationalNumber RationalNumber::operator-(const RationalNumber& rhs) const
{
	RationalNumber result = *this;
	result -= rhs;
	return result;
}

bool RationalNumber::operator<(const RationalNumber& rhs) const
{
	return ((this->numerator() * rhs.denominator()) < (this->denominator() * rhs.numerator()));
}

bool RationalNumber::operator>(const RationalNumber& rhs) const
{
	return ((this->numerator() * rhs.denominator()) > (this->denominator() * rhs.numerator()));
}

bool RationalNumber::operator<=(const RationalNumber& rhs) const
{
	return ((this->numerator() * rhs.denominator()) <= (this->denominator() * rhs.numerator()));
}

bool RationalNumber::operator>=(const RationalNumber& rhs) const
{
	return ((this->numerator() * rhs.denominator()) >= (this->denominator() * rhs.numerator()));
}

bool RationalNumber::operator==(const RationalNumber& rhs) const
{
	return ((this->denominator() == rhs.denominator()) && (this->numerator() == rhs.numerator()));
}

bool RationalNumber::operator!=(const RationalNumber& rhs) const
{
	return !(*this==rhs);
}

void RationalNumber::Simplify()
{
	int gcd = 1;
	int minimum = min(numerator_, denominator_);
	for (int i = 2; i <= minimum; i++)
	{
		if ((numerator_ % i == 0) && (denominator_ % i == 0))
		{
			gcd = i;
		}
	}
	if (gcd > 1)
	{
		numerator_ /= gcd;
		denominator_ /= gcd;
	}
}

ostream& operator<<(ostream& ostream, const RationalNumber& rhs)
{
	if (rhs.numerator() == rhs.denominator()) {
		cout << "-> 1" << endl;
	}
	else if (rhs.denominator() == 0)
	{
		cout << "-> 0" << endl;
	}
	else
	{
		cout << "-> " << rhs.numerator() << " / " << rhs.denominator() << endl;
	}
	return ostream;
}

istream& operator>>(istream& istream, RationalNumber& rhs)
{
	istream >> rhs.numerator_ >> rhs.denominator_;
	if (rhs.denominator_ == 0)
	{
		rhs.numerator_ = 0;
		rhs.denominator_ = 1;
	}
	else
	{
		rhs.Simplify();
	}
	return istream;
}
