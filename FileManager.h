#pragma once
//#include "DataSourceInterface.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Validation.h"
#include <fstream>
#include <string>

class FileManager
{
public:
	static fstream clientFile;
	static fstream employeeFile;
	static fstream adminFile;

	//Validation for objects before adding them to database.

	//static bool isValidClient(Client& obj)
	//{
	//	if (
	//		Validation::isValidName(obj.getName()) &&
	//		Validation::isValidPassword(obj.getPassword()) &&
	//		Validation::isValidBalance(obj.getBalance())
	//		)
	//	{
	//		return true;
	//	}
	//	return false;
	//}
	//static bool isValidEmployee(Employee& obj)
	//{
	//	if (
	//		Validation::isValidName(obj.getName()) &&
	//		Validation::isValidPassword(obj.getPassword()) &&
	//		Validation::isValidSalary(obj.getSalary())
	//		)
	//	{
	//		return true;
	//	}
	//	return false;
	//}
	//static bool isValidAdmin(Admin& obj)
	//{
	//	if (
	//		isValidEmployee(obj)
	//		)
	//	{
	//		return true;
	//	}
	//	return false;
	//}

	//void addClient(Client obj)
	//{
	//	if (isValidClient(obj))
	//	{
	//		clientFile.open("Client_Database.txt", ios::app);
	//		if (clientFile.is_open())
	//		{
	//			clientFile << to_string(obj.getID()) + '#' + obj.getName() + '#' + obj.getPassword() + '#' + to_string(obj.getBalance()) << endl;
	//		}
	//		clientFile.close();
	//	}
	//	else
	//	{
	//		cout << "Client has invalid Properties.";
	//	}
	//}
	// void addEmployee(Employee& obj)
	// {
	//	 if (isValidEmployee(obj))
	//	 {
	//		 employeeFile.open("Employee_Database.txt", ios::app);
	//		 if (employeeFile.is_open())
	//		 {
	//			 employeeFile << to_string(obj.getID()) + '#' + obj.getName() + '#' + obj.getPassword() + '#' + to_string(obj.getSalary()) << endl;
	//		 }
	//		 employeeFile.close();
	//	 }
	//	 else
	//	 {
	//		 cout << "Employee has invalid Properties.";
	//	 }
	//	 
	 //}
	 //void addAdmin(Admin& obj) 
	 //{
		// if (isValidAdmin(obj))
		// {
		//	 adminFile.open("Admin_Database.txt", ios::app);
		//	 if (adminFile.is_open())
		//	 {
		//		 adminFile << to_string(obj.getID()) + '#' + obj.getName() + '#' + obj.getPassword() + '#' + to_string(obj.getSalary()) << endl;
		//	 }
		//	 adminFile.close();
		// }
		// else
		// {
		//	 cout << "Admin has invalid Properties.";
		// }
	 //}
	 //vector<Client> getAllClients() 
	 //{

	 //}
	 //vector<Employee> getAllEmployees() 
	 //{

	 //}
	 //vector<Admin> getAllAdmins() 
	 //{

	 //}
	 //void removeAllClients() 
	 //{

	 //}
	 //void removeAllEmployees() 
	 //{

	 //}
	 //void removeAllAdmins() 
	 //{

	 //}

};

