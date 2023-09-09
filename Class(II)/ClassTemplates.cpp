#include <iostream>
using namespace std;

template<class T>
class MyContainer
{
private:
	T element;

public:
	MyContainer(T arg) { element = arg; }
	T increase() { return ++element; }
	
};

// class template specialization
template<>
class MyContainer<char>
{
private:
	char element;
public:
	MyContainer(char arg) { element = arg; }
	char uppercase()
	{
		if ((element >= 'a') && (element <= 'z'))
		{
			element += 'A' - 'a';
		}
		return element;
	}
};

template<class T>
class myPair
{
private:
	T values[2];
	T a, b;
	
public:
	myPair(T first, T second)
	{
		values[0] = first;
		values[1] = second;
		a = first;
		b = second;
	}

	T getMax();
};

template<class T>
T myPair<T>::getMax()
{
	T retval;
	retval = a > b ? a : b;
	return retval;
}

int main()
{
	myPair<int> myobject{ 100, 75 };
	cout << myobject.getMax() << endl;
	cout << "---------------" << endl;
	MyContainer<int> myInt{ 7 };
	MyContainer<char> myChar{ 'j' };
	cout << myInt.increase() << endl;
	cout << myChar.uppercase() << endl;
	return 0;
}