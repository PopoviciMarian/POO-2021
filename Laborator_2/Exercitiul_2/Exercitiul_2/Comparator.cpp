#include "Comparator.h"
#include "Student.h"

int compareByName(Student stud1, Student stud2) {
	if (stud1.GetName().compare(stud2.GetName()) == 0) {
		return 0;
	}
	else if (stud1.GetName().compare(stud2.GetName()) < 0) {
		return -1;
	}
	else if (stud1.GetName().compare(stud2.GetName()) > 0) {
		return 1;
	}
}

int compareByMathGrade(Student stud1, Student stud2) {
	if (stud1.GetMathGrade() == stud2.GetMathGrade()) {
		return 0;
	}else if (stud1.GetMathGrade() < stud2.GetMathGrade()) {
		return -1;
	}else if (stud1.GetMathGrade() > stud2.GetMathGrade()) {
		return 1;
	}
}

int compareByEnglishGrade(Student stud1, Student stud2) {
	if (stud1.GetEnglishGrade() == stud2.GetEnglishGrade()) {
		return 0;
	}
	else if (stud1.GetEnglishGrade() < stud2.GetEnglishGrade()) {
		return -1;
	}
	else if (stud1.GetEnglishGrade() > stud2.GetEnglishGrade()) {
		return 1;
	}
}

int compareByHistoryGrade(Student stud1, Student stud2) {
	if (stud1.GetHistoryGrade() == stud2.GetHistoryGrade()) {
		return 0;
	}
	else if (stud1.GetHistoryGrade() < stud2.GetHistoryGrade()) {
		return -1;
	}
	else if (stud1.GetHistoryGrade() > stud2.GetHistoryGrade()) {
		return 1;
	}
}

int compareByAverageGrade(Student stud1, Student stud2) {
	if (stud1.GetAverageGrade() == stud2.GetAverageGrade()) {
		return 0;
	}
	else if (stud1.GetAverageGrade() < stud2.GetAverageGrade()) {
		return -1;
	}
	else if (stud1.GetAverageGrade() > stud2.GetAverageGrade()) {
		return 1;
	}
}