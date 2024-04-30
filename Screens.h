#pragma once
#include "FilesHelper.h"
#include "AdminManager.h"
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
		PlaySound(TEXT("main2.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
			Sleep(4500);
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
				<< "                          $$|| Special Thanks to: Eng.Mostafa Madian & Eng.Mohammed Adel ||$$                   \n"
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
				<< "                          $$|| Special Thanks to: Eng.Mostafa Madian & Eng.Mohammed Adel ||$$                   \n"
				<< "                              -========================================================-                       \n";
			Sleep(550);
		}
		}

		system("pause");

	}


	//login
	void static printLoginMenu()
	{
		PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_SYNC);
		PlaySound(TEXT("welcome.wav"), NULL, SND_FILENAME | SND_ASYNC);
		system("CLS");
		system("Color 0E");
		cout << "\n      ========================================================================================================= \n"
			<< "     |>                                  _    _      _                                                        <|\n"
			<< "     |>                                 | |  | |    | |                                                       <|\n"
			<< "     |>                                 | |  | | ___| | ___ ___  _ __ ___   ___                               <|\n"
			<< "     |>                                 | |/\\| |/ _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\                              <|\n"
			<< "     |>                                 \\  /\\  /  __/ | (_| (_) | | | | | |  __/                              <|\n"
			<< "     |>                                  \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|                              <|\n"
			<< "     |>                                                                                                       <|\n"
			<< "     |>                                                                                                       <|\n"
			<< "     |>                                     What would you like to login as ?                                 <|\n"
			<< "     |>                                                                                                       <|\n"
			<< "     |>                                     1.Client.                                                         <|\n"
			<< "     |>                                     2.Employee.                                                       <|\n"
			<< "     |>                                     3.Admin.                                                          <|\n"
			<< "     |>                                                                                                       <|\n"
			<< "     |>                                            Q.Terminate Program.                                       <|\n"
			<< "     |>                                                                                                       <|\n"
			<< "     |>                                                                                                       <|\n"
			<< "     |>                                                                                                       <|\n"
			<< "     |>                                                                                                       <|\n"
			<< "     |>.......................................................................................................<|\n"
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
		//PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_ASYNC);
		string name, password;

		cout << "Please Enter your name: ";
		getline(cin, name);
		cout << "Please Enter your Password: ";
		getline(cin, password);
		Client* currentClient = ClientManager::clientFindByName(name);

		if (currentClient == NULL) //if not found.
		{
			PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("CLS");
			system("color 04");
			cout << "Invalid Name, Please try again.\n";
			Sleep(1000);
			return;
		}
		else if (currentClient != NULL) //if found.
		{
			if (currentClient->getName() == name && currentClient->getPassword() == password)//if correct name & password.
			{
				PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				system("Color 0A");
				cout << "Login Successful! \n";
				Sleep(1000);
				ClientManager::clientScreen(currentClient);
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
		//PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_ASYNC);
		int ID;
		string idStr;
		string password;

		cout << "Please Enter your ID: ";
		getline(cin, idStr);
		stringstream(idStr) >> ID;
		cout << "Please Enter your Password: ";
		getline(cin, password);
		Employee* e = EmployeeManager::employeeFindByID(ID);

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
			if (e->getID() == ID && e->getPassword() == password)//if correct ID & password.
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
		//PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_ASYNC);
		int ID;
		string idStr;
		string password;

		cout << "Please Enter your ID: ";
		getline(cin, idStr);
		stringstream(idStr) >> ID;
		cout << "Please Enter your Password: ";
		getline(cin, password);
		Admin* a = AdminManager::adminFindByID(ID);

		if (a == NULL) //if not found.
		{
			PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("CLS");
			system("color 04");
			cout << "ID not found, Please try again.";
			Sleep(1000);
			return;
		}
		else if (a != NULL) //if found.
		{
			if (a->getID() == ID && a->getPassword() == password)//if correct ID & password.
			{
				PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				system("Color 0A");
				cout << "Login Successful! \n";
				Sleep(1000);
				AdminManager::adminScreen(a);
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


	static void exitScreen()
	{
		system("CLS");

		cout
			<< "\n\n\n\t\t\t   ____      U  ___ u    U  ___ u   ____       ____     __   __ U _____ u\n"
			<< "\t\t\tU / ___|u     \\/ _ \\/     \\/ _ \\/  |  _ \\   U | __ )u   \\ \\ / / \\| ___ |/ \n"
			<< "\t\t\t\\| |  _ /     | | | |     | | | | /| | | |   \\|  _ \\/    \\ V /   |  _|    \n"
			<< "\t\t\t | |_| |  .-,_| |_| | .-,_| |_| | U| |_| |\\   | |_) |   U_| |_u  | |___   \n"
			<< "\t\t\t  \\____|   \\_)-\\___/   \\_)-\\___/   |____/ u   |____/      |_|    |_____|  \n"
			<< "\t\t\t  _)(|_         \\\\          \\\\      |||_     _|| \\\\_   __//||_   <<   >>  \n"
			<< "\t\t\t (__)__)       (__)        (__)    (__)_)   (__) (__) (__) (__) (__) (__) \n\n\n";
			
                                                                                                                                      
                                                                                                                                      

		cout << "\t\t\t\t\t  Thanks for Choosing Bolt's Bank System.\n\n"
			 << "\t\t\t\t\t  I Hope you Liked my Project!!\n\n\n";
		PlaySound(TEXT("exit.wav"), NULL, SND_FILENAME | SND_SYNC);
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

