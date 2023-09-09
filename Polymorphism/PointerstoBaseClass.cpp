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

	virtual int area() { return 0; }
};

class Rectangle : public Polygon
{
public:
	int area() { return width * height; }
};

class Triangle : public Polygon
{
public:
	int area() { return width * height / 2; }
};

int mainPointersToBaseClass()
{
	Rectangle rect;
	Triangle tri;
	Polygon poly;
	Polygon* ppoly1 = &rect; // 업캐스팅
	Polygon* ppoly2 = &tri;
	Polygon* ppoly3 = &poly;
	ppoly1->setValue(4, 5);
	ppoly2->setValue(4, 5);
	ppoly3->setValue(4, 5);
	cout << ppoly1->area() << endl;
	cout << ppoly2->area() << endl;
	cout << ppoly3->area() << endl;

	return 0;
}