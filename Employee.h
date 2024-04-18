#pragma once
#include <fstream>
#include "Person.h"
#include "Client.h"
#include "Validation.h"


class Employee : public Person
{
protected:
	double salary = 0;

	int getLastID()
	{
		fstream employeeFile;
		employeeFile.open("Employee_Database.txt", ios::in);
		if (employeeFile.is_open())
		{
			string line;
			string lastLine;
			while (getline(employeeFile, line))
			{
				if (line != "")
				{
					lastLine = line;
				}
			}
			if (lastLine != "")
			{
				int lastID = stoi(lastLine.substr(0, lastLine.find('#')));
				employeeFile.close();
				return lastID;
			}
		}
		employeeFile.close();
		return 0;
	}
public:
	//Constructors
	Employee(string name, string password, double salary)
		: Person(Validation::validName(name), Validation::validPassword(password)),
		salary(Validation::validSalary(salary))
	{
		id = getLastID() + 1;
	}

	//Getters
	double getSalary()
	{
		return salary;
	}
	//Setters
	void setSalary(double _salary) 
	{
		if (Validation::isValidSalary(_salary))
		{
			this->salary = _salary;
		}
		else
		{
			cout << "Invalid Salary.";
		}
	}
	
	//Database Access Methods
	void display()
	{
		cout << "Employee Name: " << name << endl
			<< "Employee ID: " << id << endl
			<< "Employee Salary: " << salary << endl;
	}
	void addClient(Client obj)
	{
		if (isValidClient(obj))
		{
			fstream employeeFile;
			employeeFile.open("Client_Database.txt", ios::app);
			if (employeeFile.is_open())
			{
				employeeFile << to_string(obj.getID()) + '#' + obj.getName() + '#' + obj.getPassword() + '#' + to_string(obj.getBalance()) << endl;
			}
			employeeFile.close();
		}
		else
		{
			cout << "Client has invalid Properties.\n";
		}
	}

private:
	//Validation for objects before adding them to database.
	  bool isValidClient(Client& obj)
	{
		if (
			Validation::isValidName(obj.getName()) &&
			Validation::isValidPassword(obj.getPassword()) &&
			Validation::isValidBalance(obj.getBalance())
			)
		{
			return true;
		}
		return false;
	}
};

