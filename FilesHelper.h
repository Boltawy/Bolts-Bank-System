#pragma once
#include <fstream>
#include <string>
#include "Client.h"
#include "Admin.h"
#include "parser.h"
class FilesHelper
{
private:
	static void addClientToDatabase(Client& obj)
	{
			fstream clientFile;
			clientFile.open("Client_Database.txt", ios::app);
			if (clientFile.is_open())
			{
				clientFile << to_string(obj.getID()) + '#' + obj.getName() + '#' + obj.getPassword() + '#' + to_string(obj.getBalance()) << endl;
			}
			clientFile.close();
	}
	static void addEmployeeToDatabase(Employee& obj)
	{
			fstream employeeFile;
			employeeFile.open("Employee_Database.txt", ios::app);
			if (employeeFile.is_open())
			{
				employeeFile << to_string(obj.getID()) + '#' + obj.getName() + '#' + obj.getPassword() + '#' + to_string(obj.getSalary()) << endl;
			}
			employeeFile.close();
	}
	static void addAdminToDatabase(Admin& obj)
	{
			fstream adminFile;
			adminFile.open("Admin_Database.txt", ios::app);
			if (adminFile.is_open())
			{
				adminFile << to_string(obj.getID()) + '#' + obj.getName() + '#' + obj.getPassword() + '#' + to_string(obj.getSalary()) << endl;
			}
			adminFile.close();
	}
public:
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

	//Remove Database
	static void removeAllClients()
	{
		fstream clientFile;
		clientFile.open("Client_Database.txt", ios::out);
		clientFile.close();
	}
	static void removeAllEmployees()
	{
		fstream employeeFile;
		employeeFile.open("Employee_Database.txt", ios::out);
		employeeFile.close();
	}
	static void removeAllAdmins()
	{
		fstream adminFile;
		adminFile.open("Admin_Database.txt", ios::out);
		adminFile.close();
	}

	//Display all Databases
	static void displayAllData()
	{
		cout << "----------------------------------\nClient Data:\n----------------------------------\n \n";
		for (int i = 0; i < Client::allClients.size(); i++) {

			Client::allClients[i].display();
		}
		cout << endl;

		cout << "----------------------------------\nEmployee Data : \n----------------------------------\n \n";
		for (int i = 0; i < Employee::allEmployees.size(); i++) {

			Employee::allEmployees[i].display();
		}
		cout << endl;

		cout << "----------------------------------\nAdmin Data:\n----------------------------------\n \n";
		for (int i = 0; i < Admin::allAdmins.size(); i++) {

			Admin::allAdmins[i].display();
		}
		cout << endl;
	}
};






















//	//Validation
//	static bool isValidClient(Client& obj)
//	{
//		if (
//			Validation::isValidName(obj.getName()) &&
//			Validation::isValidPassword(obj.getPassword()) &&
//			Validation::isValidBalance(obj.getBalance())
//			)
//		{
//			return true;
//		}
//		return false;
//	}
//	static bool isValidEmployee(Employee& obj)
//	{
//		if (
//			Validation::isValidName(obj.getName()) &&
//			Validation::isValidPassword(obj.getPassword()) &&
//			Validation::isValidSalary(obj.getSalary())
//			)
//		{
//			return true;
//		}
//		return false;
//	}
//	static bool isValidAdmin(Admin& obj)
//	{
//		if (
//			isValidEmployee(obj)
//			)
//		{
//			return true;
//		}
//		return false;
//	}

