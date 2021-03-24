#pragma once
#include "Car.h"

class Toyota : public Car{
public:
	Toyota();
	unsigned int GetFuelCapacity();
	double GetFuelConsumption();
	double  GetAverageSpeed(Weather weather);
};

