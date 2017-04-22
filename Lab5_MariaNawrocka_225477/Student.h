#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>

class Group;
using namespace std;

class Student
{
protected:
	string Name;
	string Surname;
	int NoAlbum;
	float AverageGrade;
	int Size;
	string* Subjects;
	
public:
	Student();
	Student(string name,string surname, int noAlbum, float averageGrade,int amountOfSubjects );
	Student(const Student& right);
	friend ostream& operator << (ostream& c, Group& d);
	Student& operator=(Student& right);
	void FillSubjects(string subject,int j) const;

	friend class Group;
	~Student();
};

