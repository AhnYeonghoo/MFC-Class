#include <iostream>
#include <string>

using namespace std;

// Destructor

class Simple
{
private:
	int m_id;
	
public:
	Simple(const int& id) : m_id{ id } 
	{
		cout << "Constructor " << m_id <<endl;
	};
	// ¼Ò¸êÀÚ
	~Simple() 
	{
		cout << "Destructor " << m_id << endl;
	}
};

class IntArray
{
private:
	int* m_arr = nullptr;
	int m_length = 0;
	
public:
	IntArray(const int& length)
	{
		m_length = length;
		m_arr = new int[m_length];
	}

	int getLength() { return m_length; }

	~IntArray()
	{
		if (m_arr != nullptr)
		{
			delete[] m_arr;
			m_arr = nullptr;
		}
	}
};
int mainDestructor()
{
	while (true)
	{
		IntArray myIntArr(1000);
	}
	return 0;
}