#pragma once
#include <iostream>
#include "FilesHelper.h"
using namespace std;
class Screens
{
public:
	static void runApp()
	{
		//Load Databases on open.
		FilesHelper::getAllClients();
		FilesHelper::getAllEmployees();
		FilesHelper::getAllAdmins();


		//Update Databases on close.
		FilesHelper::updateClientFile();
		FilesHelper::updateEmployeeFile();
		FilesHelper::updateAdminFile();
	}
};

