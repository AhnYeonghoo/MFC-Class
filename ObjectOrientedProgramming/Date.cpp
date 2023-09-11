#include "Date.hpp"
using namespace std;

void Date::SetDate(int year, int month, int date)
{
	this->year = year;
	this->month = month;
	this->day = date;
}

int Date::GetCurrentMonthTotalDays(int year, int month)
{
	static int monthDay[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month != 2)
	{
		return monthDay[month - 1];
	}
	else if (year % 4 == 0 && year % 100 != 0)
	{
		return 29;
	}
	else
	{
		return 28;
	}
}

void Date::AddDay(int inc)
{
	while (true)
	{
		int currentMonthtotalDays = GetCurrentMonthTotalDays(this->year, this->month);
		
		if (this->day + inc <= currentMonthtotalDays)
		{
			this->day += inc;
			return;
		}
		else
		{
			inc -= (currentMonthtotalDays - this->day + 1);
			this->day = 1;
			this->AddMonth(1);
		}
	}
}

void Date::AddMonth(int inc)
{
	this->AddYear((inc + this->month - 1) / 12);
	this->month = this->month + inc % 12;
	this->month = (this->month == 12 ? 12 : this->month % 12);
}

void Date::AddYear(int inc) { this->year += inc; }

void Date::ShowDate()
{
	cout << "오늘은" << this->year << " 년" << this->month
		<< " 월" << this->day << " 일 입니다" << endl;
}

