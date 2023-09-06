#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 1�ܰ� ��ȭ
struct Friend
{
	string name;
	string address;
	int age;
	double height;
	double weight;

	// 2�ܰ� ��ȭ
	void print()
	{
		cout << name << " " << address << " " << age
			<< " " << height << " " << height << endl;
	}
};

// 3�ܰ� ��ȭ Ŭ����!
class Friend
{
private:
	string name;
	string address;
	int age;
	double height;
	double weight;

public:
	void print()
	{
		cout << name << " " << address << " " << age << " "
			<< height << " " << weight << endl;
	}
};

void print(const string& name, const string& address, const int& age,
	const double& height, const double& weight)
{
	cout << name << " " << address << " " << age << " "
		<< height << " " << weight << endl;
}

// 2�ܰ� ��ȭ
void print(const Friend& fr)
{
	cout << fr.name << " " << fr.address << " " << fr.age << " "
		<< fr.height << " " << fr.weight << endl;
}

int main()
{
	Friend jj;
	jj.name = "Jack Jack";
	jj.age = 2;
	jj.address = "Uptown";
	Friend jj2{ "Jack Jack2",  "Uptown", 3, 180, 73 };
	print(jj2.name, jj2.address, jj2.age, jj2.height, jj2.weight);
	print(jj);

	vector<string> nameVec; 
	vector<string> addrVec;
	vector<int> ageVec;
	vector<double> height;
	vector<double> weightVec;
	return 0;
}