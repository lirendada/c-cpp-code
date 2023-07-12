#define _CRT_SECURE_NO_WARNINGS
#include "date.h"

//获取当月天数的函数
inline int GetMonthDay(int year, int month)
{
	static int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = arr[month];
	if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		day = 29;
	}
	return day;
}

//构造函数
Date::Date(int year, int month, int day)
{
	if (year >= 0 && month > 0 && month < 13 && day > 0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		printf("数据不准确\n");	
	}
}

//打印函数
void Date::Print()const
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		*this -= day;
	}
	else
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_month = 1;
				_year++;
			}
		}
	}
	return *this;
}

Date Date::operator+(int day) const
{
	Date tmp = *this;
	if (day < 0)
	{
		tmp -= day;
	}
	else
	{
		tmp += day;
	}
	return tmp;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		*this += (-day);
	}
	else
	{
		_day -= day;
		while (_day < 0)
		{
			_month--;
			if (_month == 0)
			{
				_month = 12;
				_year--;
			}
			_day += GetMonthDay(_year, _month);
		}

	}
	return *this;
}

Date Date::operator-(int day) const
{
	Date tmp = *this;
	if (day < 0)
	{
		tmp += day;
	}
	else
	{
		tmp -= day;
	}
	return tmp;
}

int Date::operator-(const Date& d) const
{
	Date tmp = *this;
	Date cur = d;
	int flag = 1;
	if (tmp < cur)
	{
		tmp = d;
		cur = *this;
		flag = -1;
	}

	int n = 0;
	while (cur < tmp)
	{
		n++;
		cur += 1;
	}

	return n * flag;
}

bool Date::operator<(const Date& d) const
{
	if (_year < d._year)
	{
		return true;
	}
	if (_year == d._year)
	{
		if (_month < d._month)
			return true;
		if (_month == d._month)
		{
			if (_day < d._day)
				return true;
		}
	}

	return false;
}

bool Date::operator<=(const Date& d) const
{
	return *this < d && *this == d;
}

bool Date::operator==(const Date& d) const
{
	return _year == d._year &&
		_month == d._month &&
		_day == d._day;
}

bool Date::operator>(const Date& d) const
{
	return !(*this <= d);
}

bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}

bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

Date& Date::operator++()
{
	(*this) += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp = *this;
	++(*this);
	return tmp;
}

Date& Date::operator--()
{
	(*this) -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp = *this;
	--(*this);
	return tmp;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}
