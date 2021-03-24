#pragma once
#include "Car.h"

class Mercedes : public Car{
public:
	Mercedes();
	unsigned int GetFuelCapacity();
	double GetFuelConsumption();
	double  GetAverageSpeed(Weather weather);
};

