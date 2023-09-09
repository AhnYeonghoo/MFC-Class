#include <iostream>
using namespace std;

class Polygon
{
protected:
	int width, height;
	
public:
	void setValue(int a, int b)
	{
		width = a;
		height = b;
	}
};

class Rectangle2 : public Polygon
{
public:
	int area()
	{
		return width * height;
	}
};

class Triangle : public Polygon
{
public:
	int area() { return width * height / 2; }
};

class Mother
{
public:
	Mother()
	{
		cout << "Mother: no parameters\n";
	}
	Mother(int a)
	{
		cout << "Mother: int parameter\n";
	}
};

class Daughter : public Mother
{
public:
	Daughter(int a)
	{
		cout << "Daughter: int parameter\n\n";
	}
};

class Son : public Mother
{
public:
	Son(int a) : Mother(a)
	{
		cout << "Son: int parameter\n\n";
	}
};

int main()
{

	Rectangle2 rect;
	Triangle trgl;
	rect.setValue(4, 5);
	trgl.setValue(4, 5);
	cout << rect.area() << endl;
	cout << trgl.area() << endl;

	Daughter kelly(0);
	Son bud(0);

	return 0;
}