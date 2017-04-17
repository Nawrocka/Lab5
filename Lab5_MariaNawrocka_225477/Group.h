#pragma once
#include "Student.h"

class Group
{
	Student* students;
public:
	
	/*void Add(Student* tab1, int size);*/
	void Made(int whichone) const;
	
	Group(int size);
	~Group();
};

