#include <iostream>
using namespace std;

class B;

class A
{
private:
	int mValue = 1;

	friend void doSomething(A& a);
	friend void doSomething(A& a, B& b);
	friend class B;

};

void doSomething(A& a)
{
	cout << a.mValue << endl;
}

class B
{
private:
	int mValue = 2;
	friend void doSomething(A& a, B& b);

public:
	void doSomething(A& a)
	{
		cout << a.mValue << endl;
	}
};

void doSomething(A& a, B& b)
{
	cout << a.mValue << endl;
	cout << b.mValue << endl;
}

int mainFriendFunctions()
{
	A a;
	doSomething(a);

	return 0;
}