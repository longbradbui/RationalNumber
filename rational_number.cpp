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
	int numerator = (this->numerator() * rhs.denominator()) + (this->denominator() * rhs.numerator());
	int denominator = (this->denominator() * rhs.denominator());
	SetValue(numerator, denominator);
}

RationalNumber& RationalNumber::operator-=(const RationalNumber& rhs)
{
	int numerator = (this->numerator() * rhs.denominator()) - (this->denominator() * rhs.numerator());
	int denominator = (this->denominator() * rhs.denominator());
	SetValue(numerator, denominator);
}

RationalNumber RationalNumber::operator*(const RationalNumber& rhs) const
{
	RationalNumber result = *this;
	result *= rhs;
	return result;
}

RationalNumber RationalNumber::operator/(const RationalNumber& rhs) const
{
	// TODO: insert return statement here
}

RationalNumber RationalNumber::operator+(const RationalNumber& rhs) const
{
	RationalNumber result = *this;

}

RationalNumber RationalNumber::operator-(const RationalNumber& rhs) const
{
	// TODO: insert return statement here
}

bool RationalNumber::SetValue(int numerator, int denominator)
{
	if (denominator == 0) {
		return false;
	}
	numerator_ = numerator;
	denominator_ = denominator;
	Simplify();
	return true;
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
	// TODO: insert return statement here
}

istream& operator>>(istream& istream, RationalNumber& rhs)
{
	// TODO: insert return statement here
}
