#include <iostream>
#include "Client.h"
#include "Admin.h"
#include "FilesHelper.h"
#include "Parser.h"
using namespace std;

int main()
{
	//Load Databases on open.
	FilesHelper::getAllClients();
	FilesHelper::getAllEmployees();
	FilesHelper::getAllAdmins();
	//FilesHelper::displayAllData();

	Admin bigBoss = Admin::allAdmins[0];
	
	//bigBoss.addEmployee(Employee("Kratos", "Employee123", 10000));

	//Employee::allEmployees[0].addClient(Client("Micheal De Santa", "Ab123456", 5000));
	//Employee::allEmployees[0].addClient(Client("Franklin Clinton", "Ab12345678", 5000));
	//Employee::allEmployees[0].addClient(Client( "Trevor Philips", "Ab12345678", 5000));
	//Employee::allEmployees[0].addClient(Client("Carl Johnson", "Ab12345678", 5000));
	//Employee::allEmployees[0].addClient(Client("Tommy Vercetti", "Ab12345678", 5000));
	//Employee::allEmployees[0].listClients();

	


	//Update Databases on close.
	FilesHelper::updateClientFile();
	FilesHelper::updateEmployeeFile();
	FilesHelper::updateAdminFile();
}