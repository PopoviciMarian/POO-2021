#include "Student.h"
#include "Comparator.h"
#include <iostream>

int main()
{
    Student student1("Marian", 4.5f, 5.3f, 7.1f);
    Student student2("Nicu", 7.8, 5.3f, 1.9);
    Student student3;
    student3.SetName("Amalia");
    student3.SetMathGrade(9);
    student3.SetEnglishGrade(8);
    student3.SetHistoryGrade (10);
    
    std::cout << student1.GetName() << "  " << student2.GetName() << " " << compareByName(student1, student2) <<std::endl;
    std::cout << student1.GetMathGrade() << " " << student2.GetMathGrade() << " "<< compareByMathGrade(student1, student2) << std::endl;
    std::cout << student1.GetEnglishGrade() << " " << student2.GetEnglishGrade() << " " << compareByEnglishGrade(student1, student2) << std::endl;
    std::cout << student1.GetHistoryGrade() << " " << student2.GetHistoryGrade() << " " << compareByHistoryGrade(student1, student2) << std::endl;
    std::cout << student1.GetAverageGrade() << " " << student2.GetAverageGrade() << " " << compareByAverageGrade(student1, student2) << std::endl;
}
