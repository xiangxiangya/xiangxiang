#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<iostream>
using namespace std;

#if 0
class student
{
	char name[20];
	char sex[3];
	int age;
};
class a{
	void fun();
};
int main()
{
	a b;
	cout << sizeof(b) << endl;
	system("pause");
	return 0;
}
#endif


#if 0
class data
{
public:
	data(const data & d)//拷贝构造函数
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	data(int year=1990, int month=1, int day=1)//全缺省构造函数
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	bool operator==(const data &d)//对==进行重载，相应的对！=也进行重载
	{
		if (d._year == _year&&d._month == _month&&d._day == _day)
		{
			return 1;
		}
		else
			return 0;
	}
	bool operator!=(const data &d)
	{
		return !(*this==d);
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{

	data d1(1999 ,10, 14);
	//data d2();//这里不是用类创建了一个对象而是一个函数的声明
	data d2(d1);
	if (d1 == d2)
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}
	/*d1.Print();
	d2.Print();*/
	return 0;
}
#endif

#if 0
class a
{
public:
	a(int p=1)
	{
		b = p;
	}
	int b = 10;
};

int main()
{
	a b = (2);
	cout << sizeof(a) << endl;
	system("pause");
	return 0;
}
#endif 


#if 0
class data
{
public:
	data(int year = 1999, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{

	}
	static void fun()
	{
	}
	void Print()
	{
		cout <<_year << "-" << _month << "-" << _day << endl;
	}
	
private:
	int _year;
	int _month;
	int _day;
	static int a;
	int b;
};

int data::a = 0;

int main()
{
	data a = 100;
	a.Print();
	system("pause");
	return 0;
}
#endif


#if 0
class String
{
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};

int main()
{
	String s1("hello");
	String s2(s1);
	system("pause");
	return 0;
}
#endif


#if 0
class data
{
public:
	data(int year = 1999, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{

	}
	data operator=(const data &d)//
	{
		if (this != &d )
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	data d1(2001, 20, 30);
	data d2 = d1;
	data d3;
	data d4;
	d4 = d3 = d1;
	system("pause");
	return 0;
}
#endif


class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)//构造函数
		:_year ( year)
		, _month(month)
		, _day(day)
		, flag(0)
	{
		if (year < 0 || (month<0 && month>12) || (day>(Getdayofmonth(year, month))||day<0))
		{
			flag = 1;
			cout << "输入的日期不合法" << endl;
			return;
		}
	}

	int Getdayofmonth(int year, int month)
	{
		int day[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((0 == year % 4) && (year % 100 != 0) || (year % 400) == 0)
		{
			day[2]++;
		}
		return day[month];
	}
	Date(const Date& d)//拷贝构造函数
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	Date operator+(int days)//在当前日期的基础上加上一个天数的日期
	{
		Date tmp=*this;
		tmp._day += days;
		while (tmp._day > Getdayofmonth(tmp._year, tmp._month))
		{
			tmp._day -= (Getdayofmonth(tmp._year, tmp._month));
			if (tmp._month == 12)
			{
				tmp._year++;
				tmp._month = 1;
			}
			else
			{
				tmp._month++;
			}
		}
		return tmp;
	}
	Date operator-(int days)//在当前日期的基础上减去一个天数的日期
	{
		Date tmp = *this;
		tmp._day -= days;
		while (tmp._day < Getdayofmonth(tmp._year, tmp._month)&&tmp._day<0)
		{
			if (tmp._month == 1)
			{
				tmp._month = 12;
				tmp._year--;
			}
			else
			{
				tmp._month--;
			}
			tmp._day += Getdayofmonth(tmp._year, tmp._month);
		}
		return tmp;
	}
	int operator-(const Date& d)
	{
		Date MIN(*this);
		Date MAX(d);
		int count = 0;
		if (*this > d)
		{
			swap(MIN,MAX);
		}
	
		while (MIN != MAX)
		{
			count++;
			MIN++;
		}
		return count;
	}
	Date& operator++()//前置++无需传参，只需要对隐藏的this指针修改即可
	{
		*this = *this + 1;
		return*this;
	}
	Date operator++(int)//为了作区分，后置++传一个int参数但不用
	{
		Date tmp (*this);
		*this = *this + 1;
		return tmp;
	}
	Date& operator--();//前置--
	Date operator--(int);//后置--
	bool operator>(const Date& d)const
	{
		if (_year > d._year || _year == d._year&&_month > d._month || \
			_year == d._year&&_month == d._month&&_day > d._day)
		{
			return true;
		}
		return false;
	}
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const
	{
		if (_year < d._year || _year == d._year&&_month < d._month || \
			_year == d._year&&_month == d._month&&_day < d._day)
		{
			return true;
		}
		return false;
	}
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const
	{
		if (_year == d._year &&_month == d._month &&_day == d._day)
		{
			return true;
		}
		return false;
	}
	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}
	void Print()
	{
		if (flag != 1)
		{
			cout << _year << "-" << _month << "-" << _day << endl;
		}
	}

private:
	int _year;
	int _month;
	int _day;
	int flag;
};


int main()
{
	Date d1(2016,12,31);
	Date d2(2015, 9, 19);
	cout << d1-d2 << endl;
	system("pause");
	return 0;
}