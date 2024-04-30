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
			<< "Admin Salary: " << salary << endl
			<< "\n ================================== \n\n";
	}


	static bool addEmployee(Employee obj)
	{
		if (isValidEmployee(obj))
		{
			Employee::allEmployees.push_back(obj);
			return true;
		}
		else
		{
			return false;
		}
	}

	static Employee* searchEmployeeByID(int id) { //We return a pointer, not an object, so that we can return NULL if not found.

		Employee* c = nullptr;

		for (int i = 0; i < Employee::allEmployees.size(); i++)
		{
			if (Employee::allEmployees[i].getID() == id)
			{
				c = &Employee::allEmployees[i];
				return c;
			}
		}
		return nullptr;
	}
	void listEmployees() {

		for (int i = 0; i < Employee::allEmployees.size(); i++) {

			Employee::allEmployees[i].display();
		}
	}

	void editEmployee(int id, string name, string password, double salary) {

		Employee* c = searchEmployeeByID(id);
		if (c != nullptr) {

			c->setName(name);
			c->setPassword(password);
			c->setSalary(salary);
		}
		else {

			cout << "Employee ID Not Found!" << endl;
		}
	}

private:
	//Validation for objects before adding them to vector.
	static bool isValidEmployee(Employee& obj)
	{
		if (
			Validation::isValidName(obj.getName()) &&
			Validation::isValidPassword(obj.getPassword()) &&
			Validation::isValidSalary(obj.getSalary())
			)
		{
			return true;
		}
		return false;
	}
};
