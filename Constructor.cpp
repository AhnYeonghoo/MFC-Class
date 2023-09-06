#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Fraction
{
private:
	int m_numerator = 0; // default
	int m_denominator = 1; // default
	
public:
	// Constructors
	/*Fraction()
	{
		cout << "Constructors call" << endl;
		m_numerator = 0;
		m_denominator = 1;
	}*/

	Fraction(const int& num = 0, const int& deno = 1)
	{
		cout << "Constructors call" << endl;
		m_numerator = num;
		m_denominator = deno;
	}

	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};


class Second
{
public:
	Second()
	{
		cout << "CLass Second Constructor()" << endl;
	}
};
class First
{
	Second sec;

public:
	First()
	{
		cout << "Class First Constructor()" << endl;
	}
};

int mainConstructor()
{
	Fraction frac;
	Fraction frac2(2, 3);
	frac.print();
	frac2.print();

	First first;
	
	return 0;
}