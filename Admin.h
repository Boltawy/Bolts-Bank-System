#pragma once
#include "Employee.h"
#include "Validation.h"
class Admin : public Employee
{
private:
	static int numberOfAdmins;
	int getLastID()
	{
		fstream adminFile;
		adminFile.open("Admin_Database.txt", ios::in);
		if (adminFile.is_open())
		{
			string line;
			string lastLine;
			while (getline(adminFile, line))
			{
				if (line != "")
				{
					lastLine = line;
				}
			}
			if (lastLine != "")
			{
				int lastID = stoi(lastLine.substr(0, lastLine.find('#')));
				adminFile.close();
				return lastID;
			}
		}
		adminFile.close();
		return 0;
	}
public:
	Admin(string name, string password, int id, double salary)
		: Employee(Validation::validName(name), Validation::validPassword(password),
			Validation::validSalary(salary))
	{
		id = getLastID() + 1;
	}

	void display()
	{
		cout << "Admin Name: " << name << endl
			<< "Admin ID: " << id << endl
			<< "Admin Salary: " << salary << endl;
	}

};
