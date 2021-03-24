#include "Mercedes.h"

Mercedes::Mercedes() {
	fuelCapacity = 80;
	fuelConsumption = 8.4;
	averageSpeed = 130;
}

unsigned int Mercedes::GetFuelCapacity() {
	return fuelCapacity;
}

double Mercedes::GetFuelConsumption() {
	return fuelConsumption;
}

double Mercedes::GetAverageSpeed(Weather weather) {
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
