#include "stdafx.h"
#include "Group.h"
#include <string>


Group::Group(int size)
{
	students = new Student[size];
}

void Group:: Made(int whichone)
{
	string name, surname;
	int noAlbum, noOfCourses;
	float averageGrade;

	cout << "Give me a name : ";
	cin >> name;
	cout << endl << "Give me a surname : ";
	cin >> surname;
	cout << "Give me a number of album : ";
	cin >> noAlbum;
	cout << "Give me a average Grade : ";
	cin >> averageGrade;
	cout << "How many courses have student no." << whichone + 1 << " ?" << endl;
	cin >> noOfCourses;
	
	Student student(name, surname, noAlbum, averageGrade, noOfCourses);

	cout << "Write these courses: " << endl;
	string subject;
	for (int j = 0; j < noOfCourses; j++)
	{
		cin >> subject;
		student.FillSubjects(subject, j);
	}

	this->students[whichone] = student;
}

void Add(Student* tab1, int size)
{
	/*int n;
	Student* tabB = new Student[size + 1];
	for (int i = 0; i<size; i++)
	{
		tabB[i] = tab1[i];
	}

	cout << "How many courses have student no." << size + 2 << " ?" << endl;
	cin >> n;
	tabB[size + 1] = new Student(name, surname, NoAlbum, averageGrade, n);

	cout << "Write these courses: " << endl;
	string subject;
	for (int j = 0; j < n; j++)
	{
		cin >> subject;
		tabB[size + 1].FillSubjects(subject, j);
	}
	return tabB;*/

}

Group::~Group()
{
}
