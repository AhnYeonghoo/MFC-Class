#include <iostream>
#include <vector>

using namespace std;

class Something
{
private:
	int m_i;
	double m_d;
	char m_c;
	int m_arr[5];

public:
	Something()
		: m_i{ 1 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{ 1,2,3,4,5 } {};

	void print()
	{
		cout << m_i << " " << m_d << " " << m_c << endl;
		for (const auto& ele : m_arr)
		{
			cout << ele << " ";
		}
		cout << endl;
	}
};

int main()
{
	Something some;
	some.print();

	return 0;
}