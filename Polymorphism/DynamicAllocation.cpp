#include <iostream>
using namespace std;

class Polygon2
{
protected:
	int width, height;
public:
	Polygon2(int a, int b) : width {a}, height {b} {}
	virtual int area(void) = 0;
	void printArea()
	{
		cout << this->area() << endl;
	}
};

class Rectangle2 : public Polygon2
{
public:
	Rectangle2(int a, int b) : Polygon2(a, b) {}
	int area()
	{
		return width * height;
	}
};

class Triangle2 : public Polygon2
{
public:
	Triangle2(int a, int b) : Polygon2(a, b) {}
	int area()
	{
		return width * height / 2;
	}
};

int main()
{
	Polygon2* ppoly1 = new Rectangle2(4, 5);
	Polygon2* ppoly2 = new Triangle2(4, 5);
	ppoly1->printArea();
	ppoly2->printArea();
	delete ppoly1;
	delete ppoly2;
	return 0;

}