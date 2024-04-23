#pragma once
#include "Employee.h"
#include "Validation.h"
class Admin : public Employee
{
private:
	int getLastID()
	{
		vector<Admin>::iterator it;
		for (it = allAdmins.begin(); it != allAdmins.end(); it++)
		{
		}
		Admin x = *it;
		return x.getID();
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
