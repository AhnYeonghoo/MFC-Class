#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 캡슐화
// 접근 지정자
// 접근 함수
// 복잡한 것을 간단하게!

class Date
{
private:
	int m_month;
	int m_day;
	int m_year;
	
public:
	Date(int month, int day, int year)
		: m_month{ month }, m_day{ day }, m_year{ year } {};

	Date()
	{
		m_month = m_day = m_year = 0;
	}

	void setDate(const int& month, const int& day, const int& year)
	{
		m_month = month;
		m_day = day;
		m_year = year;
	}

	void setMonth(const int& month) { m_month = month; }
	void setDay(const int& day) { m_day = day; }
	void setYear(const int& year) { m_year = year; }
	const int getMonth() const { return m_month; }
	const int getDay() const { return m_day; }
	const int getYear() const { return m_year; }

	void copyFrom(const Date& original)
	{
		m_month = original.m_month;
		m_day = original.m_day;
		m_year = original.m_year;
	}
	
};


int mainEncapsulation()
{
	Date today{ 8, 4, 2025 };
	Date today2;
	/*today2.m_day = 8;
	today2.m_month = 8;
	today2.m_year = 2025;*/
	today2.setDate(8, 8, 2025);

	cout << today.getDay() << " " << today.getMonth() << " " << today.getYear() << endl;
	cout << today2.getDay() << " " << today2.getMonth() << " " << today2.getYear() << endl;

	Date copy;
	copy.copyFrom(today);
	
	
	return 0;
}