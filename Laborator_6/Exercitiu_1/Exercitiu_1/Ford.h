#pragma once
#include "Car.h"

class Ford : public Car{
public:
	Ford();
	unsigned int GetFuelCapacity();
	double GetFuelConsumption();
	double  GetAverageSpeed(Weather weather);
};

