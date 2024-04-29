#pragma once
#include <conio.h>
#include "Client.h"
#include "ClientManager.h"
#include "Employee.h"
#include <Windows.h>
#include <mmsystem.h>
#include <sstream>

#define KEY_Q 113
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_DELETE 127 

#pragma comment(lib, "winmm.lib")

class EmployeeManager
{
public:

	static Employee* employeeFindByID(int ID)
	{
		Employee* c = nullptr;

		for (int i = 0; i < Employee::allEmployees.size(); i++)
		{
			if (Employee::allEmployees[i].getID() == ID) //if Employee found
			{
				c = &Employee::allEmployees[i];
				return c;
			}
		}
		return nullptr;
	}

	//Screen & Menu
	static void printEmployeeMenu(Employee* e)
	{
		PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_ASYNC);
		//PlaySound(TEXT("employee.wav"), NULL, SND_FILENAME | SND_ASYNC);
		system("CLS");
		system("Color 03");
		cout << "                                      ________  _________ _     _______   _______ _____ \n"
			<< "                                     |  ___|  \\/  || ___ \\ |   |  _  \\ \\ / /  ___|  ___|\n"
			<< "                                     | |__ | .  . || |_/ / |   | | | |\\ V /| |__ | |__\n"
			<< "                                     |  __|| |\\/| ||  __/| |   | | | | \\ / |  __||  __|\n"
			<< "                                     | |___| |  | || |   | |___\\ \\_/ / | | | |___| |___\n"
			<< "                                     \\____/\\_|  |_/\\_|   \\_____/\\___/  \\_/ \\____/\\____/\n"
			<< "\t\t\t\t\t ========================================\n\n\n";




		cout << "\t\t\t Hello " << e->getName() << ", my worker, How much work will you get done today ? \n"
			<< "\t\t\t\t\t\t Salary: " << e->getSalary() << "$\n"
			<< "\t\t\t\t\t\t ID: " << e->getID() << "\n\n"
			<< "\t\t\t\t 1. Add a Client.\n"
			<< "\t\t\t\t 2. List all Clients.\n"
			<< "\t\t\t\t 3. Edit Client.\n"
			<< "\t\t\t\t 4. Update Password.\n\n"
			<< "\t\t\t\t  Q. Logout.\n\n";
	}
	static void employeeScreen(Employee* e) // Too bloated, Needs refactoring.
	{
		double amount = 0;
		Client* c = NULL;
		while (true)
		{
			printEmployeeMenu(e);
			char key = _getch();
			switch (key)
			{
			case KEY_1:
				addClient();
				break;
			case KEY_2:
				listAllClients();
				break;
			case KEY_3: 
				editClient();
				break;
			case KEY_4:
				updatePassword(e);
				break;
			case KEY_Q:
				return;
			}
		}
	}
	static void addClient()
	{
		string name;
		string password;
		string balanceStr;
		double balance;
		cout << "Enter Client Name: ";
		getline(cin, name);
		cout << "Enter Client Password: ";
		getline(cin, password);
		cout << "Enter Client Balance: ";
		getline(cin, balanceStr);
		stringstream(balanceStr) >> balance;

		if (Employee::addClient(Client::Client(name, password, balance)))
		{
			cout << "\nClient Added Successfully!\n";
		}
		else
		{
			cout << "\nInvalid Properties\n";
		}
			system("Pause");
	}
	static void listAllClients()
	{
		system("CLS");
		cout << "----------------------------------\nClient Data:\n----------------------------------\n \n";
		for (int i = 0; i < Client::allClients.size(); i++) {

			Client::allClients[i].display();
		}
		cout << endl;
		system("pause");
	}
	static void editClient()
	{
		int clientID = 0;
		string idStr;
		string newName;
		string newPassword;
		double newBalance = -1;
		string balanceStr;

		cout << "Enter Client ID: ";
		getline(cin, idStr);
		stringstream(idStr) >> clientID;
		Client* c = Employee::searchClientByID(clientID);
		if (c == NULL)
		{
			PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("CLS");
			system("color 04");
			cout << "Client not found, Please try again.\n";
			Sleep(1000);
		}
		else
		{
			cout << "Enter New Name: ";
			getline(cin, newName);

			if (c->setName(newName))
			{
				cout << "Name Change Successful\n";
			}
			else
			{
				cout << "Invalid Name\n";
			}
			cout << "\nEnter New Password: ";
			getline(cin, newPassword);

		    if (c->setPassword(newPassword))
			{
				cout << "Password Change Successful\n";
			}
			else
			{
				cout << "Invalid Password\n";
			}
			cout << "\nEnter New Balance: ";
			getline(cin, balanceStr);
			stringstream(balanceStr) >> newBalance;
			if (c->setBalance(newBalance))
			{
				cout << "Balance Update Successful\n";
			}
			else
			{
				cout << "Invalid Balance\n";
			}
			system("Pause");
		}
	}
	static void updatePassword(Employee* e)
	{
		string currentPassword;
		string newPassword;
		cout << "Confirm your password: ";
		getline(cin, currentPassword);
		if (e->getPassword() == currentPassword)
		{
			cout << "Enter your new password: ";
			getline(cin, newPassword);
			if (e->setPassword(newPassword))
			{
				PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				cout << "Password Change Accepted.\n";
				Sleep(1000);
			}
			else
			{
				PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				system("color 04");
				cout << "Password Invalid.\n";
				Sleep(1000);
			}

		}
		else
		{
			PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("CLS");
			system("color 04");
			cout << "Invalid Password.\n";
			Sleep(1000);
		}
	}
};


