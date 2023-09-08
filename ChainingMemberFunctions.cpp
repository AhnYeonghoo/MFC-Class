#include <iostream>
using namespace std;

class Simple2
{
private:
	int m_id;
	
public:
	Simple2(int id)
	{
		this->setId(id);
		cout << this << endl;
	}
	void setId(int id) { m_id = id; }
	int getId() { return m_id; }
};

class Calc
{
private:
	int mValue;

public:
	Calc(int initValue)
		: mValue{ initValue } {}
	Calc& add(int value) { mValue += value; return *this; }
	Calc& sub(int value) { mValue -= value;  return *this; }
	Calc& mult(int value) { mValue *= value; return *this; }
	void print()
	{
		cout << mValue << endl;
	}
};

int mainChainingMemberFunctions()
{
	// this pointer
	// Chaining Member Functions
	Simple2 s1{ 1 }, s2{ 2 };
	s1.setId(2);
	s2.setId(4);
	cout << s1.getId() << endl;
	cout << s2.getId() << endl;

	cout << &s1 << " " << &s2 << endl;

	Calc cal{ 10 };
	cal.add(10);
	cal.sub(1);
	cal.mult(2);
	cal.print();

	Calc cal2{ 10 };
	cal2.add(10).sub(1).mult(2).print(); // Ã¼ÀÌ´× ¸É¹ö ÇÔ¼ö
	
	
	return 0;
}