#include <iostream>
using namespace std;

void incrementAll(int* start, int* stop)
{
	int* current = start;
	while (current != stop)
	{
		++(*current);
		++current;
	}
}

void printAll(const int* start, const int* stop)
{
	const int* current = start;
	while (current != stop)
	{
		cout << *current << endl;
		++current;
	}
}

void increase(void* data, int psize)
{
	if (psize == sizeof(char))
	{
		char* pchar;
		pchar = (char*)data;
		++(*pchar);
	}
	else if (psize == sizeof(int))
	{
		int* pint;
		pint = (int*)data;
		++(*pint);
	}
}

int addition(int a, int b)
{
	return (a + b);
}

int subtraction(int a, int b)
{
	return (a - b);
}

int operation(int x, int y, int (*functocall)(int, int))
{
	int g;
	g = (*functocall)(x, y);
	return (g);
}

int main()
{
	int numbers[]{ 10, 20, 30 };
	incrementAll(numbers, numbers + 3);
	printAll(numbers, numbers + 3);

	char a = 'x';
	int b = 1602;
	increase(&a, sizeof(a));
	increase(&b, sizeof(b));
	cout << a << ", " << b << endl;
	int m, n;
	int (*minus)(int, int) = subtraction;
	
	m = operation(7, 5, addition);
	n = operation(20, m, minus);
	cout << n;
	return 0;
}