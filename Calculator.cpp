#include "Calculator.hpp"

using namespace std;


Calculator& Calculator::add(int value)
{
	this->mValue += value;
	return *this;
}

Calculator& Calculator::sub(int value)
{
	this->mValue -= value;
	return *this;
}

Calculator& Calculator::mult(int value)
{
	this->mValue *= value;
	return *this;
}

void Calculator::print()
{
	cout << this->mValue << endl;
}