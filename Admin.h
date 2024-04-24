#pragma once
#include "Employee.h"
#include "Validation.h"

class Admin : public Employee
{
private:
	int getLastID()
	{
		if (allAdmins.empty())
		{
			return 0;
		}
		else
		{
			vector<Admin>::iterator it = allAdmins.begin();
			while (it != allAdmins.end() - 1)
			{
				it++;
			}
			Admin x = *it;
			return x.getID();
		}
	}
public:
	static vector<Admin> allAdmins;
	Admin(string name, string password, double salary)
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
