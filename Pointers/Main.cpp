#include <iostream>
using namespace std;

int mainMain()
{
	int firstValue, secondValue;
	int* myPointer;
	int* p1, * p2;
	
	myPointer = &firstValue;
	*myPointer = 10;
	myPointer = &secondValue;
	*myPointer = 20;
	cout << firstValue << endl;
	cout << secondValue << endl;
	cout << *myPointer << endl;

	p1 = &firstValue;
	p2 = &secondValue;
	*p1 = 10;
	*p2 = *p1;
	p1 = p2;
	*p1 = 20;
	cout << firstValue << endl;
	cout << secondValue << endl;
	return 0;
}