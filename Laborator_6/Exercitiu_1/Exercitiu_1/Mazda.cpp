#include "Mazda.h"

Mazda::Mazda() {
	fuelCapacity = 112;
	fuelConsumption = 5.6;
	averageSpeed = 132;
}

unsigned int Mazda::GetFuelCapacity() {
	return fuelCapacity;
}

double Mazda::GetFuelConsumption() {
	return fuelConsumption;
}

double Mazda::GetAverageSpeed(Weather weather) {
	switch (weather) {
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
