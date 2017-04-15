#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;

class Student
{
protected:
	string Name;
	string Surname;
	int NoAlbum;
	float AverageGrade;
	string* Subjects;
public:
	Student();
	Student(string name,string surname, int noAlbum, float averageGrade,int amountOfSubjects );
	Student& operator=(Student& right);
	void FillSubjects(string subject,int j) const;

	friend class Group;
	~Student();
};

