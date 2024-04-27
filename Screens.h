#pragma once
#include "FilesHelper.h"
#include "ClientManager.h"
//#include "EmployeeManager.h"
//#include "AdminManager.h"
using namespace std;

#define KEY_Q 113
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_DELETE 127 

#pragma comment(lib, "winmm.lib")

class Screens
{
public:


	void static welcomeScreen()
	{
		PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC);
		void frame1();
		{
			system("CLS");
			cout << "\n     ========================================================================================================= \n"
				<< "    |  Bolt Proudly Presents........                                                                          |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    *=========================================================================================================*\n"
				<< "                                                                                                               \n"
				<< "                                                                                                               \n";
			Sleep(1000);
		}
		void frame2();
		{
			system("CLS");
			cout << "\n     ========================================================================================================= \n"
				<< "    |  Bolt Proudly Presents........                                                                          |\n"
				<< "    |         ________                                                                           ________     |\n"
				<< "    |        /       /                                                                          /       /     |\n"
				<< "    |       /       /                                                                          /       /      |\n"
				<< "    |      /__     /__                                                                        /__     /__     |\n"
				<< "    |         /       /                                                                          /       /    |\n"
				<< "    |         /      /                                                                           /      /     |\n"
				<< "    |         /     /                                                                            /     /      |\n"
				<< "    |         /    /                                                                             /    /       |\n"
				<< "    |         /   /                                                                              /   /        |\n"
				<< "    |         /  /                                                                               /  /         |\n"
				<< "    |         / /                                                                                / /          |\n"
				<< "    |         //                                                                                 //           |\n"
				<< "    |         /                                                                                  /            |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                                                         |\n"
				<< "    *=========================================================================================================*\n"
				<< "                                                                                                               \n"
				<< "                                                                                                               \n";
			Sleep(1000);
		}
		void frame3();
		{
			system("CLS");
			cout << "\n     ========================================================================================================= \n"
				<< "    |  Bolt Proudly Presents........                                                                          |\n"
				<< "    |         ________                                                                           ________     |\n"
				<< "    |        /       /       BBBBBBBBBBBBBBBBB   BBBBBBBBBBBBBBBBB      SSSSSSSSSSSSSSS         /       /     |\n"
				<< "    |       /       /        B::::::::::::::::B  B::::::::::::::::B   SS:::::::::::::::S       /       /      |\n"
				<< "    |      /__     /__       B::::::BBBBBB:::::B B::::::BBBBBB:::::B S:::::SSSSSS::::::S      /__     /__     |\n"
				<< "    |         /       /       BB:::::B     B:::::B B:::::B     B:::::BS:::::S     SSSSSSS        /       /    |\n"
				<< "    |         /      /          B::::B     B:::::B  B::::B     B:::::BS:::::S                    /      /     |\n"
				<< "    |         /     /           B::::B     B:::::B  B::::B     B:::::BS:::::S                    /     /      |\n"
				<< "    |         /    /            B::::BBBBBB:::::B   B::::BBBBBB:::::B  S::::SSSS                 /    /       |\n"
				<< "    |         /   /             B:::::::::::::BB    B:::::::::::::BB    SS::::::SSSSS            /   /        |\n"
				<< "    |         /  /              B::::BBBBBB:::::B   B::::BBBBBB:::::B     SSS::::::::SS          /  /         |\n"
				<< "    |         / /               B::::B     B:::::B  B::::B     B:::::B       SSSSSS::::S         / /          |\n"
				<< "    |         //                B::::B     B:::::B  B::::B     B:::::B       SSSSSS::::S         //           |\n"
				<< "    |         /                 B::::B     B:::::B  B::::B     B:::::B       SSSSSS::::S         /            |\n"
				<< "    |                       BB:::::BBBBBB::::::B B:::::BBBBBB::::::BSSSSSSS     S:::::S                       |\n"
				<< "    |                       B:::::::::::::::::B B:::::::::::::::::B S::::::SSSSSS:::::S                       |\n"
				<< "    |                       B::::::::::::::::B  B::::::::::::::::B  S:::::::::::::::SS                        |\n"
				<< "    |                       BBBBBBBBBBBBBBBBB   BBBBBBBBBBBBBBBBB    SSSSSSSSSSSSSSS                          |\n"
				<< "    |                                                                                                         |\n"
				<< "    |                                                                             ........Bolt's Bank System  |\n"
				<< "    *=========================================================================================================*\n"
				<< "                            $$|| Our MOTTO: Give us your money, And Never see it again.||$$                   \n"
				<< "                              -========================================================-                       \n";
			Sleep(1000);
		}

		system("pause");

	}
	void static loginScreen()
	{
		while (true)
		{
			PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("CLS");
			cout << "Welcome, What would you like to login as ?\n"
				<< "\t 1.Client"
				<< "\t 2.Employee"
				<< "\t 3.Admin"
				<< "\t Q.Terminate Program\n";
			char key = _getch();
			switch (key)
			{
			case KEY_Q:
				exitScreen();
				return;
			case KEY_1:
				loginAsClient();
				break;
			case KEY_2:
				loginAsEmployee();
				break;
			case KEY_3:
				loginAsAdmin();
				break;
			default:
				break;
			}
		}
	}
	void static loginAsClient()
	{
		PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_ASYNC);
		string name, password;

		cout << "Please Enter your name: ";
		getline(cin, name);
		cout << "Please Enter your Password: ";
		getline(cin, password);
		Client* c = ClientManager::clientFind(name);

		if (c == NULL) //if not found.
		{
			invalid(2);
			return;
		}
		else if (c != NULL) //if found.
		{
			if (c->getName() == name && c->getPassword() == password)//if correct name & password.
			{
				PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				cout << "Login Successful! \n";
				Sleep(1000);
				ClientManager::clientMenu(c);
			}
			else
			{
				invalid(2);
				return;
			}
		}

	}
	void static loginAsEmployee()
	{
		PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_ASYNC);

		cout << "Please Enter your name;";
	}
	void static loginAsAdmin()
	{
		PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_ASYNC);

		cout << "Please Enter your name;";
	}
	static void invalid(int cause)
	{
		PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
		system("CLS");
		switch (cause)
		{
		case 1:
			cout << "Invalid Input, Please try again.\n";
			system("pause");
			loginScreen();
			return;
		case 2:
			cout << "Invalid Name or Password, Please try again.\n";
			Sleep(1000);
			return;
		default:
			break;
		}
	}
	static void exitScreen()
	{
		PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_ASYNC);
		system("CLS");
		cout << "Thanks for Choosing Bolt's Bank System.\n"
			<< "Come with more money next time!\n";
		system("pause");
		return;
	}
	static void runApp()
	{
		//Load Databases on open.
		FilesHelper::getAllClients();
		FilesHelper::getAllEmployees();
		FilesHelper::getAllAdmins();

		welcomeScreen();
		loginScreen();

		//Update Databases on close.
		FilesHelper::updateClientFile();
		FilesHelper::updateEmployeeFile();
		FilesHelper::updateAdminFile();
	}
};

