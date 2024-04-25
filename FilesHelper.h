#pragma once
#include <fstream>
#include <string>
#include "Client.h"
#include "Admin.h"
#include "parser.h"
class FilesHelper
{
public:
	static void addClientToDatabase(Client obj)
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

	static void addEmployeeToDatabase(Employee& obj)
	{
		if (isValidEmployee(obj))
		{
			fstream employeeFile;
			employeeFile.open("Employee_Database.txt", ios::app);
			if (employeeFile.is_open())
			{
				employeeFile << to_string(obj.getID()) + '#' + obj.getName() + '#' + obj.getPassword() + '#' + to_string(obj.getSalary()) << endl;
			}
			employeeFile.close();
		}
		else
		{
			cout << "Employee has invalid Properties.\n";
		}
	}

	static void addAdminToDatabase(Admin& obj)
	{
		if (isValidAdmin(obj))
		{
			fstream adminFile;
			adminFile.open("Admin_Database.txt", ios::app);
			if (adminFile.is_open())
			{
				adminFile << to_string(obj.getID()) + '#' + obj.getName() + '#' + obj.getPassword() + '#' + to_string(obj.getSalary()) << endl;
			}
			adminFile.close();
		}
		else
		{
			cout << "Admin has invalid Properties.\n";
		}
	}
	
	//Load from Database
	static void getAllClients()
	{
		fstream clientFile;
		string line;
		clientFile.open("Client_Database.txt", ios::in);
		while (getline(clientFile, line))
		{
			if (line != "")
			{
			Client::allClients.push_back(Parser::parseToClient(line));
			}
		}
	}
	static void getAllEmployees()
	{
		fstream employeeFile;
		string line;
		employeeFile.open("Employee_Database.txt", ios::in);
		while (getline(employeeFile, line)) 
		{
			if (line != "")
			{
			Employee::allEmployees.push_back(Parser::parseToEmployee(line));
			}
		}
	}
	static void getAllAdmins()
	{
		fstream adminFile;
		string line;
		adminFile.open("Admin_Database.txt", ios::in);
		while (getline(adminFile, line))
		{
			if (line != "")
			{
			Admin::allAdmins.push_back(Parser::parseToAdmin(line));
			}
		}
	}

	//Update Database
	static void updateClientFile()
	{
		fstream clientFile;
		clientFile.open("Client_Database.txt", ios::out); //Empties old database

		for (int i = 0; i < Client::allClients.size(); i++) //Updates Database from Vector
		{
			addClientToDatabase(Client::allClients[i]);
		}
		clientFile.close();
	}
	static void updateEmployeeFile()
	{
		fstream employeeFile;
		employeeFile.open("Employee_Database.txt", ios::out); //Empties old database

		for (int i = 0; i < Employee::allEmployees.size(); i++) //Updates Database from Vector
		{
			addEmployeeToDatabase(Employee::allEmployees[i]);
		}
		employeeFile.close();
	}
	static void updateAdminFile()
	{
		fstream adminFile;
		adminFile.open("Admin_Database.txt", ios::out); //Empties old database

		for (int i = 0; i < Admin::allAdmins.size(); i++) //Updates Database from Vector
		{
			addAdminToDatabase(Admin::allAdmins[i]);
		}
		adminFile.close();
	}
private:
	//Validation
	static bool isValidClient(Client& obj)
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
	static bool isValidAdmin(Admin& obj)
	{
		if (
			isValidEmployee(obj)
			)
		{
			return true;
		}
		return false;
	}
};

