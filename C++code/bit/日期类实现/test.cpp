#define _CRT_SECURE_NO_WARNINGS
#include "date.h"

void test1()
{
	Date d1(2024, 2, 29);
	d1.Print();

	d1 += 1;
	d1.Print();

	/*date d2(2024, 2, 28);
	d2.print();*/

	/*d2 += 10;
	d2.print();
	
	d1 + 10;
	d1.print();*/

	/*Date d2 = d1 + 100;
	d2.Print();

	d1 -= -1;
	d1.Print();

	d1 - 1;
	d1.Print();

	d2 = d1 - 1;
	d2.Print();*/
}

//void test2()
//{
//	Date d1(2024, 1, 1);
//	Date d2(2024, 2, 29);
//	/*cout << (d1 < d2) << endl;
//	cout << (d1 > d2) << endl;
//	cout << (d1 == d2) << endl;*/
//	d1--;
//	d1.Print();
//	d2 = d1++;
//	d1.Print();
//	d2.Print();
//}

void test3()
{
	Date d1(2219, 2, 13);
	Date d2(2219, 2, 12);
	cout << d1 - d2 << endl;
	cout << d2 - d1 << endl;
}

int main()
{
	/*test1();*/
	/*test2();*/
	/*test3();*/
	Date d1;
	Date d2;
	cin >> d1 >> d2;
	cout << d1 << d2;
	return 0;
}