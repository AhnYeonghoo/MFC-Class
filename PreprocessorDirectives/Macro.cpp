#include <iostream>
using namespace std;

#define getMax(a, b) ((a) > (b) ? (a) : (b))

int main()
{

	int x = 5, y;
	y = getMax(x, 2);
	cout << y << endl;
	cout << getMax(7, x) << endl;
	return 0;
}