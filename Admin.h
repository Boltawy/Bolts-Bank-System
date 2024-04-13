#pragma once
#include "Employee.h"
#include "Validation.h"
class Admin : public Employee
{
private:
	static int numberOfAdmins;
public:
	Admin(string name, string password, int id, double salary)
		: Employee(Validation::validName(name), Validation::validPassword(password),
			Validation::validSalary(salary))
	{
		numberOfAdmins++;
		this->id = numberOfAdmins;
	}

	void display()
	{
		cout << "Admin Name: " << name << endl
			<< "Admin ID: " << id << endl
			<< "Admin Salary: " << salary << endl;
	}

};
