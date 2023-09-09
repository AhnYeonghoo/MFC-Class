#include <iostream>
using namespace std;

class A {};

class B
{
public:
	// conversion from A (constructor)
	B (const A& x) {}
	
	B& operator=(const A& x) { return *this; }
	
	operator A() { return A(); }
};

void fn(B x) {}

int mainMain()
{
	A foo;
	B bar = foo;
	bar = foo;
	foo = bar;
	fn(bar);
	return 0;
}