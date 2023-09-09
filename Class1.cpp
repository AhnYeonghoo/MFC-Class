#include <iostream>
using namespace std;

class Rectangle
{
private:
	int width, height;
public:
	Rectangle(int, int);
	Rectangle();

	void setValue(int, int);
	int area(void) { return width * height; }
};

void Rectangle::setValue(int x, int y)
{
	width = x;
	height = y;
}

Rectangle::Rectangle(int a, int b)
{
	width = a;
	height = b;
}

Rectangle::Rectangle()
{
	width = 5;
	height = 5;
}

class Circle
{
private:
	double radius;
public:
	Circle(double r) { radius = r; }
	double circum() { return 2 * radius * 3.14159265; }
};

class Cylinder
{
	Circle base;
	double height;
	
public:
	Cylinder(double r, double h)
		: base{r}, height{h} {}
	double volume() { return base.circum() * height; }
};

int main()
{
	Rectangle rect(3, 4), rectb(5,6);
	rectb.setValue(5, 6);
	rect.setValue(3, 4);
	cout << "Area: " << rect.area() << endl;
	cout << "rectb Area: " << rectb.area() << endl;
	cout << "_--------------" << endl;
	
	Circle foo(10.0); // functional form
	Circle bar = 20.0; // assignment init
	Circle baz{ 30.0 }; // uniform init
	Circle qux = { 40.0 }; // POD-like
	
	cout << "foo`s circumference: " << foo.circum() << "\n";

	Cylinder doo{ 10, 20 };
	cout << "doo`s volume: " << doo.volume() << endl;

	cout << "----Pointer-----" << endl << endl;

	Rectangle obj{ 3, 4 };
	Rectangle* pObj1, * pObj2, * pObj3;
	pObj1 = &obj;
	pObj2 = new Rectangle{ 5, 6 };
	pObj3 = new Rectangle[2]{ {2,5}, {3, 6} };

	cout << "obj`s area: " << obj.area() << endl;
	cout << "*pObj1`s area: " << pObj1->area() << endl;
	cout << "*pObj2`s area: " << pObj2->area() << endl;
	cout << "pObj3[0]`s area: " << pObj3[0].area() << endl;
	cout << "pObj3[1]`s area: " << pObj3[1].area() << endl;

	delete pObj2;

	delete[] pObj3;
	return 0;
}