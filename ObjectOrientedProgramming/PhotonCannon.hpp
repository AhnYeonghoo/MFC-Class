#pragma once
#include <string.h>
#include <iostream>

class PhotonCannon
{
	int hp, shield;
	int x, y;
	int damage;
	char* name;
	
public:
	PhotonCannon(int x, int y);
	PhotonCannon(const PhotonCannon& pc);
	PhotonCannon(int x, int y, const char* cannonName);
	~PhotonCannon();
	void ShowStatus();
};