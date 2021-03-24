#pragma once
#include "Car.h"

class Mazda : public Car{
public:
	Mazda();
	unsigned int GetFuelCapacity();
	double GetFuelConsumption();
	double  GetAverageSpeed(Weather weather);
};

