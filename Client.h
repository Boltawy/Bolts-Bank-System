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
	bool deposit(double amount)
	{
		bool flag = false;
		if (amount >= 0)
		{
			balance += amount;
			flag = true;
		}
	}
	bool withdraw(double amount)
	{
		bool flag = false;
		if (amount < 0 || balance < amount)
		{
			return;
		}
		else
		{
			balance -= amount;
			flag = true;
		}
	}
	bool transferTo(double amount, Client& recipient)
	{
		bool flag = false;
		if (this->withdraw(amount) && recipient.deposit(amount))
		{
			this->withdraw(amount);
			recipient.deposit(amount);
			flag = true;
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
			<< "Client Balance: " << balance << endl
			<< "\n ================================== \n\n";
	}
};
