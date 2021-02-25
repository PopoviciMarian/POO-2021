#include "Student.h"

void Student::SetName(std::string str) {
	this->name = str;
}

std::string Student::GetName() {
	return this->name;
}

void Student::SetMathGrade(float x) {
	if (x >= 1 && x <= 10) {
		this->mathGrade = x;
	}
}

float Student::GetMathGrade() {
	return this->mathGrade;
}

void Student::SetEnglishGrade(float x) {
	if (x >= 1 && x <= 10) {
		this->englishGrade = x;
	}
}

float Student::GetEnglishGrade() {
	return this->englishGrade;
}

void Student::SetHistoryGrade(float x) {
	if (x >= 1 && x <= 10) {
		this->historyGrade = x;
	}
}

float Student::GetHistoryGrade() {
	return this->historyGrade;
}

float Student::GetAverageGrade() {
	return (this->mathGrade + this->englishGrade + this->historyGrade) / 3.f;
}

Student::Student() {
	this->mathGrade = 1;
	this->englishGrade = 1;
	this->historyGrade = 1;
}
Student::Student(std::string str) {
	this->name = str;
}
Student::Student(std::string str, float math, float eanglish, float history) {
	this->name = str;
	this->mathGrade = math;
	this->englishGrade = eanglish;
	this->historyGrade = history;
}
