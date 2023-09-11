#pragma once
#include <iostream>

class Animal
{
private:
	int food;
	int weight;

public:
	void SetAnimal(int food, int weight);
	void IncreaseFood(int inc);
	void ViewStat();
};