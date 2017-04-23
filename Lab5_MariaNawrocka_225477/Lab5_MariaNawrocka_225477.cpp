// Lab5_MariaNawrocka_225477.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Student.h"
#include "Group.h"
using namespace std;

ostream& operator << (ostream& c, Group& d)
{
	for (int i = 0; i < d.Size; i++)
	{
		c << "Student no" << i + 1 << endl;
		c << d.students[i].Name << endl;
		c << d.students[i].Surname << endl;
		c.setf(ios::hex, ios::basefield);
		c << d.students[i].NoAlbum << endl;
		c.unsetf(ios::hex);
		c.unsetf(ios::basefield);

		c.setf(std::ios_base::fixed);
		c.precision(2);
		c.setf(std::ios_base::showpoint);
		c << d.students[i].AverageGrade << endl;
		c.unsetf(ios::showpoint);

		for (int j = 0; j < d.students[i].Size; j++)
		{
			c << d.students[i].Subjects[j] << endl;
		}
		c << endl;
	}
	return c;
}

void DisplayMenu()
{
	cout << "What do you want to do?" << endl << "Pick one option, by writing a number" << endl;
	cout << "1. Add and describe new Student," << endl;
	cout << "2. Display all students," << endl;
	cout << "3. Save content of base to Student.txt," << endl;
	cout << "4. Delete content of base, and finish programme." << endl;
}

int main()
{
	int k, number;
	cout << "Give me a number of students ";
	cin >> k;
	Group tab1(k);

	for (int i = 0; i < k; i++)
	{
		tab1.Made(i);
	}

	bool g = true;
	while (g)
	{
		DisplayMenu();
		cin >> number;
		switch (number)
		{
		case 1:
		{
			tab1 = tab1.Add();
			break;
		}
		case 2: tab1.DisplayStudents();
			break;
		case 3: tab1.SaveDb();
			break;
		case 4: tab1.DeleteDb_Finish();
			g = false;
			break;
		default:
		{
			cout << "You wrote incorrect number! Pick one more time.";
			DisplayMenu();
			break;
		}
		}
	}

	return 0;
}

