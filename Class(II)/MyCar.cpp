#include <iostream>

class MyCar
{
private:
	int fuel = 0;
	bool power = false;

public:
	void go()
	{
		this->fuel--;
	}

	void oiling(int n)
	{
		this->fuel += n;
	}

	void fuelCheck()
	{
		std::cout << "¿¬·á: " << this->fuel << std::endl;
	}
};

int main()
{
	MyCar car = MyCar();
	
	car.oiling(100);
	car.fuelCheck();
	for (int i = 0; i < 10; i++) car.go();
	car.fuelCheck();
	car.oiling(100);
	for (int i = 0; i < 10; i++) car.go();
	car.fuelCheck();
	return 0;
}