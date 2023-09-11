#include "Marine.hpp"
using namespace std;

Marine::Marine()
{
	this->hp = 50;
	this->x = this->y = 0;
	this->damage = 5;
	this->isDead = false;
	this->name = NULL;
}

Marine::Marine(int x, int y)
{
	this->hp = 50;
	this->x = x;
	this->y = y;
	this->damage = 5;
	this->isDead = false;
	this->name = NULL;
}

void Marine::Move(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Marine::Attack()
{
	return this->damage;
}

void Marine::BeAttacked(int damageEarn)
{
	this->hp -= damageEarn;
	if (this->hp <= 0) this->isDead = true;
}

void Marine::ShowStatus()
{
	cout << " *** Marine : " << this->name << " ***" << endl;
	cout << " Location: ( " << this->x << " , " << this->y
		<< " ) " << endl;
	cout << " HP: " << this->hp << endl;
}

Marine::Marine(int x, int y, const char* marineName)
{
	this->x = x;
	this->y = y;
	this->name = new char[strlen(marineName) + 1];
	strcpy(this->name, marineName);
	this->hp = 50;
	this->damage = 5;
	this->isDead = false;	
}

Marine::~Marine()
{
	cout << this->name << " 의 소멸자 호출! " << endl;
	if (this->name != NULL)
		delete[] this->name;
}
