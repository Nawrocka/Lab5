#include "stdafx.h"
#include "Student.h"
#include <iostream>
#include <random>
#include <string_view>
#include <uchar.h>
using namespace std;

Student::Student():Subjects(nullptr)
{}
Student::Student(string name, string surname, int noAlbum, float averageGrade, int amountOfSubjects)
{
	Name = name;
	Surname = surname;
	NoAlbum = noAlbum;
	AverageGrade = averageGrade;
	Subjects = new string[amountOfSubjects];
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
	
	if(Subjects!=nullptr)
	{
		delete[] Subjects;
		Subjects = nullptr;
	} 
	int size = (sizeof(right.Subjects) / sizeof(*right.Subjects));
	Subjects = new string[size];
	for (int index = 0; index < size; ++index)
	{
		Subjects[index] = right.Subjects[index];
	}

	return *this;
}

void Student::FillSubjects(string subject,int j) const
{
	Subjects[j] = subject;
}
