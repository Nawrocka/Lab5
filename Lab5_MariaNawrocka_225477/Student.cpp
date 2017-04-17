#include "stdafx.h"
#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

Student::Student()  
{
	Name = "";
	Surname = "";
	Subjects=nullptr;
	NoAlbum = 0;
	AverageGrade = 0;
	size = 0;
}
Student::Student(string name, string surname, int noAlbum, float averageGrade, int amountOfSubjects)
{
	Name = name;
	Surname = surname;
	NoAlbum = noAlbum;
	AverageGrade = averageGrade;
	size = amountOfSubjects;
	Subjects = new string[size];
}

Student::Student(const Student& right)
{
	int size = right.size;
	Subjects = new string[size];
	for (int index = 0; index < size; ++index)
	{
		Subjects[index] = right.Subjects[index];
	}
}

Student::~Student()
{
	delete[] Subjects;
}

Student& Student::operator=( Student& right)
{
	if(this==&right)
	{
		return  *this;
	}
	
	Name = right.Name;
	Surname = right.Surname;
	NoAlbum = right.NoAlbum;
	AverageGrade = right.AverageGrade;
	size = right.size;

	if(Subjects!=nullptr)
	{
		delete[] Subjects;
		Subjects = nullptr;
	} 
	int size = right.size;
	Subjects = new string[size];
	for (int index = 0; index < size; ++index)
	{
		Subjects[index] = right.Subjects[index];
	}

	return *this;
}

void Student::FillSubjects(string subject,int j) const
{
	Subjects[j]= subject;
}
