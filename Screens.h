#pragma once
#include <iostream>
#include "FilesHelper.h"
using namespace std;
class Screens
{
public:


	static void welcomeScreen()
	{
		cout << "\n    #=========================================================================================================#\n"
			<< "    |  Bolt Proudly Presents........                                                                          |\n"
			<< "    |         ________                                                                           ________     |\n"
			<< "    |        /       /       BBBBBBBBBBBBBBBBB   BBBBBBBBBBBBBBBBB      SSSSSSSSSSSSSSS         /       /     |\n"
			<< "    |       /       /        B::::::::::::::::B  B::::::::::::::::B   SS:::::::::::::::S       /       /      |\n"
			<< "    |      /__     /__       B::::::BBBBBB:::::B B::::::BBBBBB:::::B S:::::SSSSSS::::::S      /__     /__     |\n"
			<< "    |        /       /       BB:::::B     B:::::B B:::::B     B:::::BS:::::S     SSSSSSS        /       /     |\n"
			<< "    |        /      /          B::::B     B:::::B  B::::B     B:::::BS:::::S                    /      /      |\n"
			<< "    |        /     /           B::::B     B:::::B  B::::B     B:::::BS:::::S                    /     /       |\n"
			<< "    |        /    /            B::::BBBBBB:::::B   B::::BBBBBB:::::B  S::::SSSS                 /    /        |\n"
			<< "    |        /   /             B:::::::::::::BB    B:::::::::::::BB    SS::::::SSSSS            /   /         |\n"
			<< "    |        /  /              B::::BBBBBB:::::B   B::::BBBBBB:::::B     SSS::::::::SS          /  /          |\n"
			<< "    |        / /               B::::B     B:::::B  B::::B     B:::::B       SSSSSS::::S         / /           |\n"
			<< "    |        //                B::::B     B:::::B  B::::B     B:::::B       SSSSSS::::S         //            |\n"
			<< "    |        /                 B::::B     B:::::B  B::::B     B:::::B       SSSSSS::::S         /             |\n"
			<< "    |                       BB:::::BBBBBB::::::B B:::::BBBBBB::::::BSSSSSSS     S:::::S                       |\n"
			<< "    |                       B:::::::::::::::::B B:::::::::::::::::B S::::::SSSSSS:::::S                       |\n"
			<< "    |                       B::::::::::::::::B  B::::::::::::::::B  S:::::::::::::::SS                        |\n"
			<< "    |                       BBBBBBBBBBBBBBBBB   BBBBBBBBBBBBBBBBB    SSSSSSSSSSSSSSS                          |\n"
			<< "    |                                                                                                         |\n"
			<< "    |                                                                             ........Bolt's Bank System  |\n"
			<< "    *=========================================================================================================*\n"
			<< "                             || Our MOTTO: Give us your money, And Never see it again. ||                      \n"
			<< "                               ========================================================                        \n";
	}


	static void runApp()
	{
		//Load Databases on open.
		FilesHelper::getAllClients();
		FilesHelper::getAllEmployees();
		FilesHelper::getAllAdmins();

		welcomeScreen();

		//Update Databases on close.
		FilesHelper::updateClientFile();
		FilesHelper::updateEmployeeFile();
		FilesHelper::updateAdminFile();
	}
};

