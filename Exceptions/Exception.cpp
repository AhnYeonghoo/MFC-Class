#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception
{
	virtual const char* what() const throw()
	{
		return "My Exception Happened";
	}
} myex;

// using standard exceptions
int main()
{
	try
	{
		throw 20;
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << e << endl;
	 }

	try
	{
		throw myex;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	{
		try
		{
			int* myArray = new int[1000];
		} 
		catch (exception& e)
		{
			cout << "Standard exception: " << e.what() << endl;
		}
	}
	return 0;
}