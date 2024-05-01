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
#define KEY_5 53
#define KEY_6 54


#pragma comment(lib, "winmm.lib")

class EmployeeManager
{
public:
	//Screen & Menu
	static void printEmployeeMenu(Employee* currentEmployee)
	{
		PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_ASYNC);
		//PlaySound(TEXT("employee.wav"), NULL, SND_FILENAME | SND_ASYNC);
		system("CLS");
		system("Color 0A");
		cout << "                                      ________  _________ _     _______   _______ _____ \n"
			<< "                                     |  ___|  \\/  || ___ \\ |   |  _  \\ \\ / /  ___|  ___|\n"
			<< "                                     | |__ | .  . || |_/ / |   | | | |\\ V /| |__ | |__\n"
			<< "                                     |  __|| |\\/| ||  __/| |   | | | | \\ / |  __||  __|\n"
			<< "                                     | |___| |  | || |   | |___\\ \\_/ / | | | |___| |___\n"
			<< "                                     \\____/\\_|  |_/\\_|   \\_____/\\___/  \\_/ \\____/\\____/\n"
			<< "\t\t\t\t\t ========================================\n\n\n";




		cout << "\t\t\t\tHello " << currentEmployee->getName() << ", my worker, How much work will you get done today ? \n"
			<< "\t\t\t\t\t\t\tSalary: " << currentEmployee->getSalary() << "$\n"
			<< "\t\t\t\t\t\t\tID: " << currentEmployee->getID() << "\n\n"
			<< "\t\t\t\t\t1. Add a Client.\n"
			<< "\t\t\t\t\t2. List all Clients.\n"
			<< "\t\t\t\t\t3. Edit a Client.\n"
			<< "\t\t\t\t\t4. Remove a Client.\n\n"
			<< "\t\t\t\t\t5. Update Password.\n\n"
			<< "\t\t\t\t\t\x1B[31m6. Quit Your Job.\n\n"
			<< "\t\t\t\t\t\t\t\x1B[33mQ. Logout.\n\n";
	}
	static void employeeScreen(Employee* currentEmployee)
	{
		while (true)
		{
			printEmployeeMenu(currentEmployee);
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
				removeClient();
				break;
			case KEY_5:
				updatePassword(currentEmployee);
				break;
			case KEY_6:
				if (employeeDeleteAccount(currentEmployee)) //if deleted
				{
					return;
				}
				break;
			case KEY_Q:
				PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_SYNC);
				return;
			}
		}
	}

	//Menu Option Methods.
	static Employee* employeeFindByID(int ID)
	{
		Employee* currentEmployee = nullptr;

		for (int i = 0; i < Employee::allEmployees.size(); i++)
		{
			if (Employee::allEmployees[i].getID() == ID) //if Employee found
			{
				currentEmployee = &Employee::allEmployees[i];
			}
		}
		return currentEmployee;
	}
	static void addClient()
	{
		string name;
		string password;
		string balanceStr;
		double balance;
		cout << "Enter Client's Name: ";
		getline(cin, name);
		cout << "Enter Client's Password: ";
		getline(cin, password);
		cout << "Enter Client's Balance: ";
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

		cout << "Enter Client's ID: ";
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
	static void removeClient() 
	{
		int clientID = 0;
		string idStr;
		cout << "Enter Client's ID: ";
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
			ClientManager::clientDeleteAccount(c);
		}
	}
	static void updatePassword(Employee* currentEmployee)
	{
		string currentPassword;
		string newPassword;
		cout << "Confirm your password: ";
		getline(cin, currentPassword);
		if (currentEmployee->getPassword() == currentPassword)
		{
			cout << "Enter your new password: ";
			getline(cin, newPassword);
			if (currentEmployee->setPassword(newPassword))
			{
				PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				system("Color 0A");
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
	static bool employeeDeleteAccount(Employee* currentemployee)
	{
		bool isDeleted = false;
		auto it = Employee::allEmployees.begin();
		system("CLS");
		system("color 04");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t======================================\n\n"
			<< "\t\t\t\t        ARE YOU SURE YOU WANT TO QUIT THIS JOB ?\n"
			<< "\t\t\t\t            NO ONE ELSE IS GOING TO HIRE YOU!\n\n"
			<< "\t\t\t\t\t         Press (Y) to confirm.\n\n"
			<< "\t\t\t\t\t======================================\n\n\t\t\t\t";
		PlaySound(TEXT("warning.wav"), NULL, SND_FILENAME | SND_SYNC);
		char key = _getch();
		switch (key)
		{
		case KEY_Y:
			it = remove_if(Employee::allEmployees.begin(), Employee::allEmployees.end(),
				[currentemployee](const Employee& employee) {
					return employee.getID() == currentemployee->getID();
				});
			Employee::allEmployees.erase(it, Employee::allEmployees.end());
			PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("CLS");
			system("Color 0A");
			cout << "Account Deleted Successfully.\n";
			system("pause");
			isDeleted = true;
			break;
		default:
			break;
		}
		return isDeleted;


	}
};


