#include <iostream>
using namespace std;

class Something2
{
private:
	int mValue = 0;

public:
	Something2(int value = 0)
		: mValue{ value } {}

	Something2(const Something2& st)
	{
		mValue = st.mValue;
	}

	void setValue(int value) { mValue = value; }
	int getValue() const
	{
		return mValue; 
	}
};



int mainClassAndConst()
{
	const int i = 0;
	Something2 something;
	something.setValue(5);
	const Something2 something2;
	cout << something2.getValue() << endl;
	
	return 0;
}