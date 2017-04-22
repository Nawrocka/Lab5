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
	Size = 0;
}
Student::Student(string name, string surname, int noAlbum, float averageGrade, int amountOfSubjects)
{
	Name = name;
	Surname = surname;
	NoAlbum = noAlbum;
	AverageGrade = averageGrade;
	Size = amountOfSubjects;
	Subjects = new string[Size];
}

Student::Student(const Student& right)
{
	NoAlbum = right.NoAlbum;
	AverageGrade = right.AverageGrade;
	Size = right.Size;
	Subjects = new string[Size];
	for (int index = 0; index < Size; ++index)
	{
		Subjects[index] = right.Subjects[index];
	}
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
	
	if(Subjects!=nullptr)
	{
		delete[] Subjects;
		Subjects = nullptr;
	} 
	Size = right.Size;
	Subjects = new string[Size];
	for (int index = 0; index < Size; ++index)
	{
		Subjects[index] = right.Subjects[index];
	}
	 
	return *this;
}

void Student::FillSubjects(string subject,int j) const
{
	Subjects[j]= subject;
}

Student::~Student()
{
	delete[] Subjects;
}