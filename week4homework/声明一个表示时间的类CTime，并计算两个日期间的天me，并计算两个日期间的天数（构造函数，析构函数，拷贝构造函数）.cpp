// 声明一个表示时间的类CTime，并计算两个日期间的天数（构造函数，析构函数，拷贝构造函数）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

//5、设计一个成员函数  int dayDiff(CTime t) ，用于计算当前对象与形参t之间的相隔的天数，注意相隔天数为大于等于0的正整数。注意闰年的问题。


#include<iostream>
#include<time.h>
#include<math.h>
using namespace std;

time_t convert(int year, int month, int day,int hour ,int minute,int second )
{
	tm info = { 0 };
	info.tm_year = year - 1900;
	info.tm_mon = month - 1;
	info.tm_mday = day;
	info.tm_hour = hour;
	info.tm_min = minute;
	info.tm_sec = second;
	return mktime(&info);
}

class CTime
{
private:
	int year, month, day, hour, minute, second;
public:
	int isvalid();
	int dvalid();
	int tvalid();
	void showTime();
	int dayDiff(CTime p);
	int isleap();
	CTime(int a, int b, int c, int d=0, int e=0, int f=0);
	
	CTime(CTime& p);
	~CTime();
};
int CTime::isleap()
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}
int CTime::tvalid()
{
	if (hour < 0 || hour>23 || minute < 0 || minute>59 || second < 0 || second>59)
		return 0;
	else
		return 1;

}
int CTime::dvalid()
{
	if (year < 0 || month <= 0 || month > 12 || day <= 0 || day > 31)
	{
		return 0;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day == 31)
			return 0;
		else
			return 1;
	}
	else if (month == 2)
	{
		if (isleap())
		{
			if (day > 29)
				return 0;
			else
				return 1;
		}
		else
		{
			if (day > 28)
				return 0;
			else
				return 1;
		}
	}
	else
		return 1;
}

int CTime::isvalid()
{
	if (dvalid() == 0 || tvalid() == 0)
		return 0;
	else
		return 1;
}
CTime::CTime(int a, int b, int c, int d, int e, int f)
{
	year = a;
	month = b;
	day = c;
	hour = d;
	minute = e;
	second = f;
	if (dvalid() == 0 && tvalid() == 0)
	{
		cout << "date and time error!" << endl;
		year = 0;
		month = 0;
		day = 0;
		hour = 0;
		minute = 0;
		second = 0;
	}
	else if (dvalid() == 0)
	{
		cout << "date error!" << endl;
		year = 0;
		month = 0;
		day = 0;
		hour = 0;
		minute = 0;
		second = 0;
	}
	else if (tvalid() == 0)
	{
		cout << "time error!" << endl;
		year = 0;
		month = 0;
		day = 0;
		hour = 0;
		minute = 0;
		second = 0;
	}
	cout << "构造函数被调用" << endl;
}
CTime::CTime(CTime& p)
{
	year = p.year;
	month = p.month;
	day = p.day;
	hour = p.hour;
	minute = p.minute;
	second = p.second;
	cout << "拷贝构造函数被调用" << endl;
}
CTime::~CTime()
{
	cout << "析构函数被调用" << endl;
}
void CTime::showTime()
{
	cout << year << "/" << month << "/" << day << " " << hour << ":" << minute << ":" << second << endl;
}
int CTime::dayDiff(CTime p)
{
	long sec1 = convert(year, month, day,hour ,minute,second);
	long sec2 = convert(p.year,p.month, p.day,p.hour,p.minute,p.second);
	return (int)((abs)(sec1 - sec2) / 3600 / 24);
}




int  main()
{
	int  year, month, day, hour, minute, second;
	cin >> year >> month >> day >> hour >> minute >> second;
	CTime  t1(year, month, day, hour, minute, second);
	t1.showTime();
	CTime  t2(2000, 1, 1);  //利用默认形参将时间初始化为00:00:00
	if (t1.isvalid())          //如果日期和时间合法，则计算天数
	{
		int  days = 0;
		days = t1.dayDiff(t2);
		cout << "这两天之间相隔了" << days << "天" << endl;
		days = t2.dayDiff(t1);
		cout << "这两天之间相隔了" << days << "天" << endl;
	}
}
