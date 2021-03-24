#include "Ford.h"

Ford::Ford() {
	fuelCapacity = 120;
	fuelConsumption = 5;
	averageSpeed = 180;
}

unsigned int Ford::GetFuelCapacity() {
	return fuelCapacity;
}

double Ford::GetFuelConsumption() {
	return fuelConsumption;
}

double Ford::GetAverageSpeed(Weather weather) {
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
