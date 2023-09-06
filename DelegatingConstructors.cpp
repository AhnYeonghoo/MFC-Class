#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	int m_id;
	string m_name;

public:
	// ���� ������
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

	// �ʱ�ȭ �ڵ带 �и��ϴ� ��� C++11 ���� ���
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