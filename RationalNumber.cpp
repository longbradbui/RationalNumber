#include "rational_number.h"
#include <iostream>
using namespace std;

int main()
{
	RationalNumber r1(1, 3);
	RationalNumber r2(3, 4);
	RationalNumber r3, r4, r5, r6, r7, r8;
	r3 = r1 + r2;
	r4 = r1 - r2;
	r5 = r1 * r2;
	r6 = r1 / r2;
	cout << r1;
	cout << r2; 
	cout << r3;
	cout << r4;
	cout << r5;
	cout << r6;
	cout << ((r1 > r2) ? "TRUE" : "FALSE") << endl;
	cout << ((r1 < r2) ? "TRUE" : "FALSE") << endl;
	cout << ((r1 != r2) ? "TRUE" : "FALSE") << endl;
	cout << ((r1 == r2) ? "TRUE" : "FALSE") << endl;
	cout << "What is your desired number? ";
	cin >> r7;
	cout << r7;
	return 0;
}

