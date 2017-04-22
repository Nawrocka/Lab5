#pragma once
#include "Student.h"

class Group
{
	Student* students;
	int Size;
public:
	Group(int size);
	Group& operator=(Group& right);
	friend ostream& operator << (ostream& c,Group& d);

	Group Add();
	void DisplayStudents();
	void SaveDb();
	void DeleteDb_Finish();
	void Made(int whichone) const;
	
	~Group();
};

