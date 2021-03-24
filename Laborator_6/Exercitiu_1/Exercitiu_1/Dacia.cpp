#include "Dacia.h"

Dacia::Dacia() {
	fuelCapacity = 60;
	fuelConsumption = 8;
	averageSpeed = 80;
}

unsigned int Dacia::GetFuelCapacity() {
	return fuelCapacity;
}

double Dacia::GetFuelConsumption() {
	return fuelConsumption;
}

double Dacia::GetAverageSpeed(Weather weather) {
	switch (weather){
	case Rain:
		return averageSpeed - 0.1 * averageSpeed;
	case Sunny:
		return averageSpeed;
	case Snow:
		return averageSpeed - 0.4 * averageSpeed;
	default:
		break;
	}
}

