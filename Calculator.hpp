#pragma once
#include <iostream>


class Calculator
{
private:
	int mValue;
	
public:
	Calculator(int value)
		: mValue{ value } {}

	Calculator& add(int value);
	Calculator& sub(int value);
	Calculator& mult(int value);
	void print();
};