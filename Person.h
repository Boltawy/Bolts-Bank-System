#pragma once
#include <iostream>
#include "Validation.h"
using namespace std;


class Person
{
protected:
	string name, password;
	int id = 0;
public:
	//Constructor
	Person(string name, string password)
		: name(Validation::validName(name)), password(Validation::validPassword(password))
	{}
	//Getters
	 string getName()
	{
		return name;
	}
	 string getPassword()
	{
		return password;
	}
	 int getID()
	{
		return id;
	}

	//Setters 
	bool setName(string _name)
	{
		if (Validation::isValidName(_name))
		{
			this->name = _name;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool setPassword(string _password)
	{
		if (Validation::isValidPassword(_password))
		{
			this->password = _password;
			return true;
		}
		else
		{
			return false;
		}
	}
	void setID(int id)
	{
		this->id = id;
	}


	virtual void display() = 0;
};