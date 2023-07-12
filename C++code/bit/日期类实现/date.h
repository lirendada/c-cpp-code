#pragma once
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year = 0, int month = 1, int day = 1);
	
	Date operator+(int day) const;
	Date& operator+=(int day);
	
	Date operator-(int day) const;
	Date& operator-=(int day);

	int operator-(const Date& d)const;

	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;

	Date& operator++();

	Date operator++(int);

	Date& operator--();

	Date operator--(int);

	void Print()const;
private:
	int _year, _month, _day;
};