#include "PhotonCannon.hpp"
using namespace std;

PhotonCannon::PhotonCannon(int x, int y)
{
	cout << "생성자 호출!" << endl;
	this->x = x;
	this->y = y;
	this->hp = this->shield = 100;
	this->damage = 20;
	this->name = NULL;
}

PhotonCannon::PhotonCannon(int x, int y, const char* cannonName)
{
	this->hp = this->shield = 100;
	this->x = x;
	this->y = y;
	this->damage = 20;
	this->name = new char[strlen(cannonName) + 1];
	strcpy(this->name, cannonName);
}

PhotonCannon::PhotonCannon(const PhotonCannon& pc)
{
	cout << "복사 생성자 호출! " << endl;
	this->hp = pc.hp;
	this->shield = pc.shield;
	this->x = pc.x;
	this->y = pc.y;
	this->damage = pc.damage;
	this->name = new char[strlen(pc.name) + 1];
	strcpy(this->name, pc.name);

}

void PhotonCannon::ShowStatus()
{
	cout << "Photon Cannon :: " << this->name << endl;
	cout << " Location : ( " << this->x << " , " << this->y
		<< " ) " << endl;
	cout << " HP : " << this->hp << endl;
} 

PhotonCannon::~PhotonCannon()
{
	if (this->name) delete[] name;
}