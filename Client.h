#pragma once
#include <fstream>
#include<vector>
#include "string"
#include "Person.h"
#include "Validation.h"

class Client : public Person
{
private:
	double balance = 0;
	
	 int getLastID()
	{
		 if (allClients.empty())
		 {
			 return 0;
		 }
		 else
		 {

		 vector<Client>::iterator it = allClients.begin();
		 while (it != allClients.end() - 1)
		 {
			 it++;
		 }
		 Client x = *it;
		 return x.getID();
		 }
	}
public:
	static vector<Client> allClients;

	//Constructors
	Client(string name, string password, double balance)
		: Person(Validation::validName(name),
			Validation::validPassword(password)),
		balance(Validation::validBalance(balance))
	{
		id = getLastID() + 1;
	}

	//Getters
	double getBalance()
	{
		return balance;
	}
	//Setters
	bool setBalance(double _balance) 
	{
		if (Validation::isValidBalance(_balance))
		{
			this->balance = _balance;
			return true;
		}
		else
		{
			return false;
		}
	}

	//Other Methods
	bool deposit(double amount)
	{
		if (amount >= 0)
		{
			balance += amount;
			return true;
		}
		return false;

	}
	bool withdraw(double amount)
	{
		bool flag = false;
		if (amount < 0 || balance < amount)
		{
			return false;
		}
		else
		{
			balance -= amount;
			return true;
		}
	}
	bool transferTo(double amount, Client& recipient)
	{
		if (this->withdraw(amount) && recipient.deposit(amount))
		{
			return true;
		}
		return false;
	}
	void checkBalance()
	{
		cout << "Balance is: " << balance << endl;
	}
	void display()
	{
		cout << "Client Name: " << name << endl
			<< "Client ID: " << id << endl
			<< "Client Balance: " << balance << endl
			<< "\n ================================== \n\n";
	}
};
