#include "Circuit.h"


void Circuit::SetLength(int length) {
	this->length = length;
}

void Circuit::SetWeather(Weather weather) {
	this->weather = weather;
}

void Circuit::AddCar(Car* car) {
	cars.insert(std::pair<Car*, double>(car, 0));
}

void Circuit::Race() {
	std::map<Car*, double>::iterator car;
	
	for (car = cars.begin(); car != cars.end(); ++car) {
		car->second = this->length / car->first->GetAverageSpeed(this->weather);
	}
}

bool cmp(std::pair<Car*, double>& a, std::pair<Car*, double>& b){
	return b.second > a.second;
}

void transformTime(double h_hours) {
	int hours = h_hours;
	double m_minutes = (h_hours - hours) * 60;
	int minutes = m_minutes;
	int seconds = (m_minutes - minutes)*60;
	std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
}

void Circuit::ShowFinalRanks() {
	std::vector<std::pair<Car*, double> > sort_car;
	for (auto& it : cars) {
		sort_car.push_back(it);
	}
	std::sort(sort_car.begin(), sort_car.end(), cmp);
	for (auto& car : sort_car) {
		std::cout <<"Car : " << std::setw(10) << std::left<<typeid(*car.first).name() + 6 <<"  Time -- ";
		transformTime(car.second);
	}
}

void Circuit::ShowWhoDidNotFinis() {
	std::cout << std::endl;
	for (auto& car : cars) {
		if (length > car.first->GetFuelCapacity() * 100 / car.first->GetFuelConsumption()) {
			std::cout << typeid(*car.first).name() + 6 << std::endl;
		}
	}
}