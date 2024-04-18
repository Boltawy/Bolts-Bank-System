#pragma once
#include <fstream>
#include "Person.h"
#include "Client.h"
//#include "Parser.h" //Circular dependancy.
#include "Validation.h"


class Employee : public Person
{
protected:
	double salary = 0;

	int getLastID()
	{
		fstream clientFile;
		clientFile.open("client_Database.txt", ios::in);
		if (clientFile.is_open())
		{
			string line;
			string lastLine;
			while (getline(clientFile, line))
			{
				if (line != "")
				{
					lastLine = line;
				}
			}
			if (lastLine != "")
			{
				int lastID = stoi(lastLine.substr(0, lastLine.find('#')));
				clientFile.close();
				return lastID;
			}
		}
		clientFile.close();
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
		cout << "client Name: " << name << endl
			<< "client ID: " << id << endl
			<< "client Salary: " << salary << endl;
	}
	void addClient(Client obj)
	{
		if (isValidClient(obj))
		{
			fstream clientFile;
			clientFile.open("Client_Database.txt", ios::app);
			if (clientFile.is_open())
			{
				clientFile << to_string(obj.getID()) + '#' + obj.getName() + '#' + obj.getPassword() + '#' + to_string(obj.getBalance()) << endl;
			}
			clientFile.close();
		}
		else
		{
			cout << "Client has invalid Properties.\n";
		}
	}

	//Client getClientByID(int id) { //Needs work to fix circular dependancies.
	//	fstream clientFile;
	//	string line;
	//	clientFile.open("Client_Database.txt", ios::in);
	//	while (getline(clientFile, line)) { //read every line and assigns it in line string.
	//		int lineId = stoi(line.substr(0, line.find('#'))); //stores the id in a new variable.
	//		if (lineId == id) { //if found.
	//			clientFile.close();
	//			Parser::parseToClient(Parser::split(line));
	//		}
	//	}
	//	clientFile.close();
	//	return; //what should I return if id i am looking for is not found ? throw exception ?
	//}

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

