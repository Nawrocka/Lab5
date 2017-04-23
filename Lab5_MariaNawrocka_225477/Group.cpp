#include "stdafx.h"
#include "Group.h"
#include <string>
#include <fstream>

using namespace std;

Group::Group(int size)
{
	Size = size;
	students = new Student[Size];
}

Group::Group(const Group& right)
{
	Size = right.Size;
	students = new Student[Size];
	for (int index = 0; index < Size; ++index)
	{
		students[index] = right.students[index];
	}
}

float Group::Sprawdzam() const
{
	float doPrzypisania;
	
	while (!(cin >> doPrzypisania))
	{
		cout << "That isn't a number! Write corectly : ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	
	return doPrzypisania;
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
	cout << "Give me a number of album (6 digit): ";
	noAlbum = int(Sprawdzam());

	string Album = to_string(noAlbum);
	while (Album.length()!=6)
	{
		cout << "Give 6 digit ! No more, no less : ";
		Album = to_string(int(Sprawdzam()));
	}
	noAlbum = atoi(Album.c_str());

	cout << "Give me a average Grade : ";
	averageGrade=Sprawdzam();
	cout << "How many courses have student no." << whichone + 1 << " ?" << endl;
	noOfCourses= int(Sprawdzam());
	
	
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

	plik << *this;

	plik.close();
}

void Group::DeleteDb_Finish()
{
	exit(0);
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
