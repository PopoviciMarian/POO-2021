#pragma once
#include "Weather.h"
class Car{
protected:
	unsigned int fuelCapacity;
	double fuelConsumption;
	double averageSpeed;
public:
	virtual unsigned int GetFuelCapacity() = 0;
	virtual double GetFuelConsumption() = 0;
	virtual double  GetAverageSpeed(Weather weather) = 0;
};

