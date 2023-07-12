#define _CRT_SECURE_NO_WARNINGS
#include "date.h"


int main()
{
	Date d1(2004, 2, 28);
	d1.Print();

	d1 += 10;
	d1.Print();

	Date d2 = d1 + 10;
	d2.Print();

	d2 -= 30;
	d2.Print();

	cout << (d1 - d2) << endl;

	d2--;
	d2.Print();

	cout << d2 << d1;
	cin >> d1;
	cout << d1;

	return 0;
}