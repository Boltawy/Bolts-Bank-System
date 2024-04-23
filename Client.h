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
		 vector<Client>::iterator it;
		 for (it = allClients.begin(); it != allClients.end(); it++)
		 {}
		 Client x = *it;
		 return x.getID();
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
	void setBalance(double _balance) 
	{
		if (Validation::isValidBalance(_balance))
		{
			this->balance = _balance;
		}
		else
		{
			cout << "Invalid Balance.\n";
		}
	}

	//Other Methods
	void deposit(double amount)
	{
		if (amount >= 0)
		{
			balance += amount;
		}
		else
		{
			cout << "Can't deposit a negative number\n";
		}
	}
	void withdraw(double amount)
	{
		if (amount < 0)
		{
			cout << "Can't withdraw a negative number\n";
		}
		else if (balance < amount)
		{
			cout << "Not enough balance\n";
		}
		else
		{
			balance -= amount;
		}
	}
	void transferTo(double amount, Client& recipient)
	{
		if (recipient.balance != -1 && this->balance != -1)
		{
			this->withdraw(amount);
			recipient.deposit(amount);
		}
		else
		{
			cout << "Invalid Balance in either account.\n";
		}
	}
	void checkBalance()
	{
		cout << "Balance is: " << balance << endl;
	}
	void display()
	{
		cout << "Client Name: " << name << endl
			<< "Client ID: " << id << endl
			<< "Client Balance: " << balance << endl;
	}
};
