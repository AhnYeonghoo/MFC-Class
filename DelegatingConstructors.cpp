#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	int m_id;
	string m_name;

public:
	// 위임 생성자
	Student(const string& name)
		: Student(0, name) {};

	Student(const int& id)
		: Student(id, "Default") {};
	
	Student(const int& id, const string& name)
		: m_id{ m_id }, m_name{ name } {};

	void print()
	{
		cout << m_id << " " << m_name << endl;
	}

	// 초기화 코드를 분리하는 방법 C++11 이전 방법
	void init(const int& id, const string& name)
	{
		m_id = id;
		m_name = name;
	}
};

int mainDelegatingConstructors()
{

	return 0;
}