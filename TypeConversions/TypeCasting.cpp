#include <iostream>
using namespace std;


class Dummy
{
private:
	double i, j;
};

class Addition
{
private:
	int x, y;
public:
	Addition(int a, int b) { x = a; y = b; }
	int result() { return x + y; }
};

int mainTypeCasting()
{
	Dummy d;
	Addition* padd;
	padd = (Addition*)&d;
	cout << padd->result() << endl;
	return 0;
}