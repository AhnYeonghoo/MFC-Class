#include <iostream>
#include <typeinfo>
#include <exception>
using namespace std;

void print(char* str)
{
	cout << str << '\n';
}

class Base2 { virtual void f() {} };
class Derived2 : public Base2 {};

int main()
{
	const char* c = "sample text";
	// print(c); -> ºÒ°¡´É
	print(const_cast<char*>(c));

	// typeid
	cout << endl << endl;
	
	int* a, b;
	a = 0; b = 0;
	if (typeid(a) != typeid(b))
	{
		cout << "a and b are of different types:\n";
		cout << "a is: " << typeid(a).name() << endl;
		cout << "b is: " << typeid(b).name() << endl;
	}

	{
		try
		{
			Base2* a = new Base2;
			Base2* b = new Derived2;
			cout << "a is : " << typeid(a).name() << endl;
			cout << "b is : " << typeid(b).name() << endl;
			cout << "*a is : " << typeid(*a).name() << endl;
			cout << "*b is : " << typeid(*b).name() << endl;
		}
		catch (exception& e)
		{
			cout << "Exception: " << e.what() << endl;
		}
	}
	
	return 0;
}