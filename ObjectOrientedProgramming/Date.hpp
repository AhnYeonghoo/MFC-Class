#pragma once
#include <iostream>

class Date
{
private:
	int year;
	int month;
	int day;

public:
	void SetDate(int year, int month, int date);
	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc);

	int GetCurrentMonthTotalDays(int year, int month);
	void ShowDate();

	Date(int year, int month, int day)
	{
		std::cout << "인자3 개인 생성자 호출!" << std::endl;
		this->year = year;
		this->month = month;
		this->day = day;
	}

	Date()
	{
		std::cout << "Default Constructor Call" << std::endl;
		this->year = 2023;
		this->month = 9;
		this->day = 10;
	}
};