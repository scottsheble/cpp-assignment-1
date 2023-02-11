/*
Chapter 9 assignment. Create a class, StudentNameGPA, to hold
- student name
- student gpa

In the class tester, create an array of StudentNameGPA 
objects. 
Sort and search through this array
*/
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;
#include "StudentNameGPA.h"
void shuffle_array(StudentNameGPA[], int);
void print_array(StudentNameGPA[], int);
void sort_array_by_gpa(StudentNameGPA[], int);
void sort_array_by_name(StudentNameGPA[], int);
double getAverageGPA(StudentNameGPA [], int );
int main()
{
	srand(time(NULL));
	const int SIZE = 7;
	StudentNameGPA arr_stu[SIZE] = {
		StudentNameGPA("Aname", (rand() % 201 + 200) / 100.0),
		StudentNameGPA("Bname", (rand() % 201 + 200) / 100.0),
		StudentNameGPA("Cname", (rand() % 201 + 200) / 100.0),
		StudentNameGPA("Dname", (rand() % 201 + 200) / 100.0),
		StudentNameGPA("Ename", (rand() % 201 + 200) / 100.0),
		StudentNameGPA("Fname", (rand() % 201 + 200) / 100.0),
		StudentNameGPA("Gname", (rand() % 201 + 200) / 100.0)
	};
	shuffle_array(arr_stu, SIZE);

	cout << "--- after shuffle -----\n";
	print_array(arr_stu, SIZE);

	sort_array_by_name(arr_stu, SIZE);
	cout << "--- sorted by name -----\n";
	print_array(arr_stu, SIZE);

	sort_array_by_gpa(arr_stu, SIZE);
	cout << "-- sorted by gpa --- \n";
	print_array(arr_stu, SIZE);

	cout << setprecision(2) << fixed
		<< "\nAverage GPA = "
		<< getAverageGPA(arr_stu, SIZE)
		<< endl;
	return 0;
}
void shuffle_array(StudentNameGPA arr_param[], int size)
{
	for (int i = 0; i < size * 10; i++)
	{
		int sub1 = rand() % size,
			sub2 = rand() % size;
		swap(arr_param[sub1], arr_param[sub2]);
	}
}
double getAverageGPA(StudentNameGPA arr_param[], int size)
{
	double totalGpa = 0;
      int i,j;
	  for(i=0;i<size;i++)
       totalGpa+=arr_param[i].getStGPA();
	return totalGpa / size;
}
void sort_array_by_gpa(StudentNameGPA arr_param[], int size)
{
		 int i,j;
   for(i=0;i<size;i++)
   {      
       StudentNameGPA temp;
       for(j=i+1;j<size;j++)
       {
           if(arr_param[i].getStGPA()<arr_param[j].getStGPA())
           {
               temp =arr_param[i];
               arr_param[i]=arr_param[j];
               arr_param[j]=temp;
           }
       }
   }

}
void sort_array_by_name(StudentNameGPA arr_param[], int size)
{
      int i,j;
    for(i=0;i<size-1;i++)
    {
        StudentNameGPA temp;
        for(j=i+1;j<size;j++)
        {
          if(arr_param[i].getStName()>arr_param[j].getStName())
          {
              temp =arr_param[j];
              arr_param[j]=arr_param[i];
              arr_param[i]=temp;
          }
        }
    }

}
void print_array(StudentNameGPA arr_param[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(2) << right << (i + 1) << ". ";
		arr_param[i].print();
	}
}