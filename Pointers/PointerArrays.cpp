#include <iostream>
using namespace std;

int mainPointerArray()
{
	int numbers[5];
	int* p;
	p = numbers;
	*p = 10;
	cout << numbers[0] << endl;
	cout << *p << endl;

	p++;
	*p = 20;
	cout << numbers[1] << endl;
	cout << *p << endl;
	p = &numbers[2];
	*p = 30;
	p = numbers + 3;
	*p = 40;
	p = numbers;
	*(p + 4) = 50;
	for (const auto& v : numbers)
	{
		cout << v << " ";
	}
	cout << endl;
	return 0;
}