#ifndef RATIONAL_NUMBER_H_
#define RATIONAL_NUMBER_H_
#include <iostream>;
using namespace std;

class RationalNumber
{
public:
	RationalNumber();
	RationalNumber(int numerator, int denominator);
	int numerator() const;
	int denominator() const;
	friend ostream& operator<<(ostream& ostream, const RationalNumber& rhs);
	friend istream& operator>>(istream& istream, RationalNumber& rhs);
	RationalNumber& operator*= (const RationalNumber& rhs);
	RationalNumber& operator/= (const RationalNumber& rhs);
	RationalNumber& operator+= (const RationalNumber& rhs);
	RationalNumber& operator-= (const RationalNumber& rhs);
	RationalNumber operator* (const RationalNumber& rhs) const;
	RationalNumber operator/ (const RationalNumber& rhs) const;
	RationalNumber operator+ (const RationalNumber& rhs) const;
	RationalNumber operator- (const RationalNumber& rhs) const;
	bool SetValue(int numerator, int denominator);
	void Simplify();
private:
	int numerator_;
	int denominator_;
};

#endif