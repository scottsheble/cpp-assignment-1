#include "StudentNameGPA.h"

StudentNameGPA::StudentNameGPA(string param_name, double param_gpa)
{
	stName = "-";
	stGPA = 0;
	setStName(param_name);
	setStGPA(param_gpa);
}

void StudentNameGPA::setStName(string param_name)
{
	if (param_name == "")
		cout << "Name cannot be blank\n";
	else
		stName = param_name;
}

void StudentNameGPA::setStGPA(double param_gpa)
{
	if (param_gpa < 0)
		cout << "GPA cannot be less than 0\n";
	else
		stGPA = param_gpa;
}

string StudentNameGPA::getStName() const
{
	return stName;
}

double StudentNameGPA::getStGPA() const
{
	return stGPA;
}

void StudentNameGPA::print() const
{
	cout << fixed << setprecision(3);
	cout << setw(15) << left << stName
		<< setw(6) << right << stGPA << endl;
}
