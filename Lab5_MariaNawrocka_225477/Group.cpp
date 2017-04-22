#include "stdafx.h"
#include "Group.h"
#include <string>
#include <fstream>


Group::Group(int size)
{
	Size = size;
	students = new Student[Size];
}

void Group:: Made(int whichone) const 
{
	string name = "";
	string surname = "";
	string subject;
	int noAlbum = 0;
	int noOfCourses = 0;
	float averageGrade=0;


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
	
	for (int j = 0; j < noOfCourses; j++)
	{
		cin >> subject;
		student.FillSubjects(subject, j);
	}

	this->students[whichone] = student;
}

Group Group:: Add() 
{
	Group tab2(this->Size + 1);
	for(int i=0;i<this->Size;i++)
	{
		tab2.students[i] = this->students[i];		
	}

	tab2.Made(this->Size);
	return tab2;
}

void Group::DisplayStudents()
{
	cout << *this;
}

void Group::SaveDb()
{
	fstream plik;
	plik.open("Zespolone.txt", ios::out);
	if (plik.good() != true)
	{
		cout << "Nie ma takiego pliku/ coœ z istniej¹cym jest nie tak!" << endl;
		system("pause");
		exit(-1);
	}

	plik << this;

	plik.close();
}

void Group::DeleteDb_Finish()
{
	for(int i=0;i<this->Size;i++)
	{
		this->students[i].~Student();
	}
	this->~Group();
}

Group& Group::operator=(Group& right)
{
	if (this == &right)
	{
		return  *this;
	}

	if (students != nullptr)
	{
		delete[] students;
		students = nullptr;
	}

	Size = right.Size;
	students = new Student[Size];
	for (int index = 0; index < Size; ++index)
	{
		students[index] = right.students[index];
	}

	return *this;
}


Group::~Group()
{
	delete[] students;
}
