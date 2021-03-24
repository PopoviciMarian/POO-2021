#pragma once
#include "Car.h"

class Dacia : public Car{
public:
	Dacia();
	unsigned int GetFuelCapacity();
	double GetFuelConsumption();
	double  GetAverageSpeed(Weather weather);
};

