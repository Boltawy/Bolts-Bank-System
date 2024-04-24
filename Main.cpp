#include <iostream>
#include "Client.h"
#include "Admin.h"
#include "FilesHelper.h"
#include "FileManager.h"
#include "Parser.h"
using namespace std;

int main()
{
	//Load Databases on open.
	FilesHelper::getAllClients();
	FilesHelper::getAllEmployees();
	FilesHelper::getAllAdmins();

	Employee z("Franklin", "87654321", 100000);
	z.addClient(Client("Micheal De Santa", "s", 5000));
	z.addClient(Client("Franklin Clinton", "Ab12345678", 5000));
	z.addClient(Client( "Trevor Philips", "Ab12345678", 5000));
	z.addClient(Client("Carl Johnson", "Ab12345678", 5000));
	z.addClient(Client("Tommy Vercetti", "Ab12345678", 5000));
	z.listClient();
	

	//Update Databases on close.
	//FilesHelper::updateClientFile();
	//FilesHelper::updateEmployeeFile();
	//FilesHelper::updateAdminFile();
}