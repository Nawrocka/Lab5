// Lab5_MariaNawrocka_225477.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Student.h"
#include "Group.h"
using namespace std;

void DisplayMenu()
{
	cout << "What do you want to do?" << endl << "Pick one option, by writing a number" << endl;
	cout << "1. Add and describe new Student," << endl;
	cout << "2. Display all students," << endl;
	cout << "3. Save content of base to Student.txt," << endl;
	cout << "4. Delete content of base, and finish programme." << endl;
}

void DisplayStudents()
{

}

void SaveDb()
{

}

void DeleteDb_Finish()
{

}

int main()
{
	int k, number;
	cout << "Give me a number of students";
	cin >> k;
	Group tab1(k);

	for (int i = 0; i < k; i++)
	{
		tab1.Made(i);
	}

	for (;;)
	{
		DisplayMenu();
		cin >> number;
		switch (number)
		{
		case 1:
		{
			break;;
		}
		case 2: DisplayStudents();
			break;
		case 3: SaveDb();
			break;
		case 4: DeleteDb_Finish();
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

