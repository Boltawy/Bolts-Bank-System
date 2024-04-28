#pragma once
#include <conio.h>
#include "Client.h"
#include "ClientManager.h"
#include "Employee.h"
#include <Windows.h>
#include <mmsystem.h>

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

	static Employee* EmployeeFind(string ID)
	{
		Employee* c = nullptr;

		for (int i = 0; i < Employee::allEmployees.size(); i++)
		{
			if (Employee::allEmployees[i].getID() == stoi(ID)) //if Employee found
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
		PlaySound(TEXT("employee.wav"), NULL, SND_FILENAME | SND_ASYNC);
		system("CLS");
		system("Color 0A");
		cout << "Hello " << e->getName() << ", my worker, How much work will you get done today ? \n"
			<< "Salary: " << e->getSalary() << "$\n"
			<< "1. Add a Client.\n"
			<< "2. List all Clients.\n"
			<< "3. Edit Client.\n"
			<< "4. Update Password.\n"
			<< "Q. Logout.\n";
	}
	static void employeeScreen(Employee* e) // Too bloated, Needs refactoring.
	{
		double amount = 0;
		Client* c;
		string clientName;
		string currentPassword;
		string newPassword;

		while (true)
		{
			printEmployeeMenu(e);
			char key = _getch();
			switch (key)
			{
			case KEY_1:
				break;
			case KEY_2:
				system("CLS");
				cout << "----------------------------------\nClient Data:\n----------------------------------\n \n";
				for (int i = 0; i < Client::allClients.size(); i++) {

					Client::allClients[i].display();
				}
				cout << endl;
				system("pause");
				
				break;
			case KEY_3: 
				c = ClientManager::clientFind(clientName);
				if (c == NULL)
				{
					PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
					system("CLS");
					system("color 04");
					cout << "Client not found, Please try again.\n";
					Sleep(1000);
					return;
				}
				else
				{

				}
				break;
			case KEY_4:

				break;
			case KEY_Q:
				return;
			}
		}
	}
};

