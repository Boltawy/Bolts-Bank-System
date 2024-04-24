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
		if (allEmployees.empty())
		{
			return 0;
		}
		else
		{
		vector<Employee>::iterator it = allEmployees.begin();
		while ( it != allEmployees.end() - 1)
		{
			it++;
		}
		
		Employee x = *it;
		return x.getID();
		}
	}
public:
	static vector<Employee> allEmployees;
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
			Client::allClients.push_back(obj);
		}
		else
		{
			cout << "Client has invalid Properties.\n\n";
		}
	}
	Client* searchClient(int id) {

		Client* c = nullptr;

		for (int i = 0; i < Client::allClients.size(); i++) {

			if (Client::allClients[i].getID() == id) {

				c = &Client::allClients[i];
				return c;
			}
			else
			{
				c->setID(-1);
				return c;
			}
		}
	}
	void listClient() {

		for (int i = 0; i < Client::allClients.size(); i++) {

			Client::allClients[i].display();
		}
	}

	void editClient(int id, string name, string password, double balance) {

		Client* c;
		c = searchClient(id);
		if (c->getID() != -1) {

			c->setName(name);
			c->setPassword(password);
			c->setBalance(balance);
		}
		else {

			cout << "Client ID Not Found!" << endl;
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

