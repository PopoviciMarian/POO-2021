#pragma once
#include <string>

class Student{
private:
	std::string name;
	float mathGrade;
	float englishGrade;
	float historyGrade;
	
public:
	void SetName(std::string str);
	std::string GetName();

	void SetMathGrade(float x);
	float GetMathGrade();


	void SetEnglishGrade(float x);
	float GetEnglishGrade();


	void SetHistoryGrade(float x);
	float GetHistoryGrade();

	float GetAverageGrade();

	Student();
	Student(std::string str);
	Student(std::string str, float math, float eanglish, float history);

};

