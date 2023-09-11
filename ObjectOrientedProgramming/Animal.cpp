#include "Animal.hpp"
using namespace std;

void Animal::IncreaseFood(int inc)
{
	this->food += inc;
	this->weight += (inc / 3);
}

void Animal::SetAnimal(int food, int weight)
{
	this->food = food;
	this->weight = weight;
}

void Animal::ViewStat()
{
	cout << "�� ������ food : " << this->food << endl;
	cout << "�� ������ weight: " << this->weight << endl;
}