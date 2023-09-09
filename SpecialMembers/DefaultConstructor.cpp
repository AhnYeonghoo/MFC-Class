#include <iostream>
#include <string>
using namespace std;

class Example3
{
private:
	string data;
public:
	Example3(const string& str) 
		: data{str} {}
	Example3() {}
	const string& content() const { return data; }
};

class Example4
{
private:
	string* ptr;
	
public:
	// constructors:
	Example4() : ptr{new string} {}
	Example4(const string& str)
		: ptr {new string(str)} {}
	//destructor:
	~Example4() { delete ptr; }
	const string& content() const { return *ptr; }
};

class Example5
{
private:
	string* ptr;
public:
	Example5(const string& str) : ptr{new string(str)} {}
	~Example5() { delete ptr; }
	// copy constructor
	Example5 (const Example5& x) : ptr{new string(x.content())} {}
	const string& content() const { return *ptr; }
	Example5& operator=(const Example5& x);
};

// copy assignment
Example5& Example5::operator= (const Example5& x)
{
	delete ptr;
	ptr = new string(x.content());
	return *this;
}


// move constructor
class Example6
{
private:
	string* ptr;
public:
	Example6(const string& str) 
		: ptr {new string(str)} {}
	
	Example6(Example6&& x) 
		: ptr{ x.ptr } 
	{
		x.ptr = nullptr;
	}

	Example6& operator= (Example6&& x)
	{
		delete ptr;
		ptr = x.ptr;
		x.ptr = nullptr;
		return *this;
	}

	// access contents
	const string& content() const { return *ptr; }
	Example6 operator+(const Example6& rhs)
	{
		return Example6(content() + rhs.content());
	}
};


class Rectangle
{
private:
	int width, height;
public:
	Rectangle(int x, int y) 
		: width{x}, height{y} {}
	Rectangle() = default;
	Rectangle(const Rectangle& other) = delete;
	int area() { return width * height; }
};

int main()
{
	Example3 foo;
	Example3 bar{ "Example" };

	cout << "bar`s content: " << bar.content() << endl;

	Example4 foo2;
	Example4 bar2{ "Example" };
	cout << "bar2`s content: " << bar2.content() << endl;

	Example5 foo3{ "example" };
	Example5 bar3 = foo3;
	cout << "foo3`s content: " << bar3.content() << endl;

	Example6 foo4{ "Exam" };
	Example6 bar4 = Example6("ple");
	foo4 = foo4 + bar4;
	cout << foo4.content() << endl;


	return 0;
}
