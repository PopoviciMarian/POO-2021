#pragma once
#include "Car.h"
#include "Weather.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

class Circuit
{
private:
	int length;
	std::map<Car*, double> cars; // <car , time needed to finish the circuit>
	Weather weather;
public :
	void AddCar(Car* car);
	void SetLength(int lenght);
	void SetWeather(Weather weather);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinis();
};

