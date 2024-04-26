#pragma once
#include "FilesHelper.h"
#include "ClientManager.h"
//#include "EmployeeManager.h"
//#include "AdminManager.h"
using namespace std;

#pragma comment(lib, "winmm.lib")

class Screens
{
public:


	 void static welcomeScreen()
	{
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
		PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC);
		system("pause");
		
	}
	 void static loginScreen()
	 {
		 int prompt = -1;
		 while (prompt != 0)
		 {
		PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_ASYNC);
		 system("CLS");
		 cout << "Welcome, What would you like to login as ?\n"
			 << "\t 1.Client"
			 << "\t 2.Employee"
			 << "\t 3.Admin"
			 << "\t 0.Terminate Program\n";
		 cin >> prompt;
		 switch (prompt)
		 {
		 case 1:
			 loginAsClient();
			 break;
		 case 2:
			 loginAsEmployee();
			 break;
		 case 3:
			 loginAsAdmin();
			 break;
		 case 0:
			 closeScreen();
			 break;
			 return;
		 default:
			 invalid(1);
			 break;
		 }
		 }
	 }
	 void static loginAsClient()
	 {
		 PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_ASYNC);
		 string name, password;

		 cout << "Please Enter your name(or type return to go back): ";
		 getline(cin, name);
		 getline(cin, name);
		 if (name == "return")
		 {
			 loginScreen();
			 return;
		 }
		 cout << "Please Enter your Password: ";
		 getline(cin, password);
		 Client* c = ClientManager::ClientLogin(name);
		
		 if (c == NULL)
		 {
			 invalid(2);
			 return;
		 }
		 else if (c != NULL)
		 {
		 PlaySound(TEXT("login2.wav"), NULL, SND_FILENAME | SND_ASYNC);
			 system("CLS");
			 cout << "Login Successful! \n";
			 system("pause");
			 ClientManager::clientMenu(c);
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
			 system("pause");
			 loginScreen();
			 return;
		 default:
			 break;
		 }
	 }
	 static void closeScreen()
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

