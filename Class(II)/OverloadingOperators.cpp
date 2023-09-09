#include <iostream>
#include <string>
using namespace std;

class CVector
{
public:
	int x, y;
	CVector() {};
	CVector(int a, int b) : x(a), y(b) {}
	CVector operator+ (const CVector&);
	CVector& operator= (const CVector&);
};

CVector CVector::operator+ (const CVector& param)
{
	CVector temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	return temp;
}

CVector operator+(const CVector& lhs, const CVector& rhs)
{
	CVector temp;
	temp.x = lhs.x + rhs.x;
	temp.y = lhs.y + rhs.y;
	return temp;
}

class Dummy
{
public:
	bool isitme(Dummy& param);
};

bool Dummy::isitme(Dummy& param)
{
	if (&param == this) return true;
	else return false;
}

CVector& CVector::operator= (const CVector& param)
{
	x = param.x;
	y = param.y;
	return *this;
}

class Dummy2
{
public:
	static int n;
	Dummy2() { n++; }
};

int Dummy2::n = 0;


/*
ddd
*/

class MyClass
{
public:
	int x;
	MyClass(int val) : x{val} {}
	const int& get() const { return x; }
};

void print(const MyClass& arg)
{
	cout << arg.get() << endl;
}

int mainOverloadingOperators()
{
	CVector foo{ 3, 1 };
	CVector bar{ 1, 2 };
	CVector result;
	result = foo + bar;
	cout << result.x << " , " << result.y << endl;

	cout << "----------- " << endl;

	Dummy a;
	Dummy* b = &a;
	if (b->isitme(a)) 
	{
		cout << "yes &a is b\n";
	}

	Dummy2 a2;
	Dummy2 b2[5];
	cout << a2.n << endl; // 6
	Dummy2* c = new Dummy2;
	cout << Dummy2::n << endl; // 7
	delete c;

	const MyClass my{ 10 };
	cout << my.x << endl;
	print(my);

	return 0;
}