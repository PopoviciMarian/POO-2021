#include "Toyota.h"

Toyota::Toyota() {
	fuelCapacity = 90;
	fuelConsumption = 6.5;
	averageSpeed = 99;
}

unsigned int Toyota::GetFuelCapacity() {
	return fuelCapacity;
}

double Toyota::GetFuelConsumption() {
	return fuelConsumption;
}

double Toyota::GetAverageSpeed(Weather weather) {
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
