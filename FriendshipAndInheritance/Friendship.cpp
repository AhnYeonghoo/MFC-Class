#include <iostream>
using namespace std;

class Square;

class Rectangle
{
private:
	int width, height;
	
public:
	Rectangle() {}
	Rectangle(int x, int y) : width{x}, height{y} {}
	int area() { return width * height; }
	friend Rectangle duplicate(const Rectangle&);
	void convert(Square a);
	
};

class Square
{
	friend class Rectangle;
private:
	int side;
public:
	Square(int a) : side(a) {}
};

void Rectangle::convert(Square a)
{
	width = a.side;
	height = a.side;
}

Rectangle duplicate(const Rectangle& param)
{
	Rectangle res;
	res.width = param.width * 2;
	res.height = param.height * 2;
	return res;
}

int mainFriendship()
{
	Rectangle foo;
	Rectangle bar(2, 3);
	foo = duplicate(bar);
	cout << foo.area() << endl;

	return 0;
}