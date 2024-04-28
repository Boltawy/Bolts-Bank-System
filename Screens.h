#pragma once
#include "FilesHelper.h"
#include "EmployeeManager.h"
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
		system("Color 0E");
		//PlaySound(TEXT("main2.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
			//Sleep(4500);
		}
		while (!_kbhit())
		{
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
				<< "    |                                                                             ........Bolt's Bank System  |\n"
				<< "    *=========================================================================================================*\n"
				<< "                            $$|| Our MOTTO: Give us your money, And Never see it again.||$$                   \n"
				<< "                              -========================================================-                       \n";
			Sleep(350);
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
			Sleep(550);
		}
		}

		system("pause");

	}


	//login
	void static printLoginMenu()
	{
		PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_ASYNC);
		system("CLS");
		system("Color 0E");
		cout << "\n      ========================================================================================================= \n"
			<< "     |                                   _    _      _                                                         |\n"
			<< "     |                                  | |  | |    | |                                                        |\n"
			<< "     |                                  | |  | | ___| | ___ ___  _ __ ___   ___                                |\n"
			<< "     |                                  | |/\\| |/ _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\                               |\n"
			<< "     |                                  \\  /\\  /  __/ | (_| (_) | | | | | |  __/                               |\n"
			<< "     |                                   \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|                               |\n"
			<< "     |                                                                                                         |\n"
			<< "     |                                                                                                         |\n"
			<< "     |                                      What would you like to login as ?                                  |\n"
			<< "     |                                                                                                         |\n"
			<< "     |                                      1.Client.                                                          |\n"
			<< "     |                                      2.Employee.                                                        |\n"
			<< "     |                                      3.Admin.                                                           |\n"
			<< "     |                                                                                                         |\n"
			<< "     |                                      Q.Terminate Program.                                               |\n"
			<< "     |                                                                                                         |\n"
			<< "     |                                                                                                         |\n"
			<< "     |                                                                                                         |\n"
			<< "     |                                                                                                         |\n"
			<< "     |                                                                                                         |\n"
			<< "     *=========================================================================================================*\n"
			<< "                                                                                                               \n"
			<< "                                                                                                               \n";
	}

	void static loginScreen()
	{
		while (true)
		{
			

			printLoginMenu();


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
			PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("CLS");
			system("color 04");
			cout << "Invalid Name, Please try again.\n";
			Sleep(1000);
			return;
		}
		else if (c != NULL) //if found.
		{
			if (c->getName() == name && c->getPassword() == password)//if correct name & password.
			{
				PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				system("Color 0A");
				cout << "Login Successful! \n";
				Sleep(1000);
				ClientManager::clientMenu(c);
			}
			else
			{
				PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				system("color 04");
				cout << "Invalid Password, Please try again.\n";
				Sleep(1000);
				return;
			}
		}

	}
	void static loginAsEmployee()
	{
		PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_ASYNC);
		string ID;
		string password;

		cout << "Please Enter your ID: ";
		getline(cin, ID);
		cout << "Please Enter your Password: ";
		getline(cin, password);
		Employee* e = EmployeeManager::EmployeeFind(ID);

		if (e == NULL) //if not found.
		{
			PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("CLS");
			system("color 04");
			cout << "ID not found, Please try again.";
			Sleep(1000);
			return;
		}
		else if (e != NULL) //if found.
		{
			if (e->getID() == stoi(ID) && e->getPassword() == password)//if correct ID & password.
			{
				PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				system("Color 0A");
				cout << "Login Successful! \n";
				Sleep(1000);
				EmployeeManager::employeeScreen(e);
			}
			else
			{
				PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				system("color 04");
				cout << "Invalid Password, Please try again.\n";
				Sleep(1000);
				return;
			}
		}
	}
	void static loginAsAdmin()
	{
		PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_ASYNC);

		cout << "Please Enter your name;";
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

