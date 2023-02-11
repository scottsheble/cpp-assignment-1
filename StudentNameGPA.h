#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class StudentNameGPA
{
private:
	string stName;
	double stGPA;
public:
	StudentNameGPA(string = "-", double = 0.0);
	//-- mutators
	void setStName(string);
	void setStGPA(double);
	//-- accessors
	string getStName() const;
	double getStGPA() const;
	//-- other functions
	void print() const;
};