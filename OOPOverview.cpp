#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 1단계 진화
struct Friend
{
	string name;
	string address;
	int age;
	double height;
	double weight;

	// 2단계 진화
	void print()
	{
		cout << name << " " << address << " " << age
			<< " " << height << " " << height << endl;
	}
};

// 3단계 진화 클래스!
class FriendClass
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

// Object
// class는 object를 구체화한 것. instance화 하다.
// 난 알지롱

void print(const string& name, const string& address, const int& age,
	const double& height, const double& weight)
{
	cout << name << " " << address << " " << age << " "
		<< height << " " << weight << endl;
}

// 2단계 진화
//void print(const Friend& fr)
//{
//	cout << fr.name << " " << fr.address << " " << fr.age << " "
//		<< fr.height << " " << fr.weight << endl;
//}

int mainOOPOverview()
{
	Friend jj;
	/*jj.name = "Jack Jack";
	jj.age = 2;
	jj.address = "Uptown";
	Friend jj2{ "Jack Jack2",  "Uptown", 3, 180, 73 };
	print(jj2.name, jj2.address, jj2.age, jj2.height, jj2.weight);
	print(jj);*/

	vector<string> nameVec; 
	vector<string> addrVec;
	vector<int> ageVec;
	vector<double> height;
	vector<double> weightVec;

	vector<Friend> myFriend;
	myFriend.resize(2);
	
	// 구조체에는 메서드를 웬만하면 넣지 않는게 관례이다.
	// C에서는 구조체에 메서드를 넣는 것이 불가능.
	// Cpp에서만 허용.
	return 0;
}