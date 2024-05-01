#pragma once
#include "Admin.h"
#include "EmployeeManager.h"

#define KEY_5 53
#define KEY_6 54
#define KEY_7 55
#define KEY_8 56
#define KEY_9 57
#define KEY_0 48

class AdminManager :
    public EmployeeManager
{
public:
	//Screen & Menu.
    static void printAdminMenu(Admin* currentAdmin)
    {
        PlaySound(TEXT("admin.wav"), NULL, SND_FILENAME | SND_ASYNC);
        system("CLS");
        system("Color 1F");

		
		cout << "\n\t\t\t\t    /$$$$$$        /$$               /$$          \n"
			<< "\t\t\t\t   /$$__  $$      | $$              |__/          \n"
			<< "\t\t\t\t  | $$  \\ $$  /$$$$$$$ /$$$$$$/$$$$  /$$ /$$$$$$$ \n"
			<< "\t\t\t\t  | $$$$$$$$ /$$__  $$| $$_  $$_  $$| $$| $$__  $$\n"
			<< "\t\t\t\t  | $$__  $$| $$  | $$| $$ \\ $$ \\ $$| $$| $$  \\ $$\n"
			<< "\t\t\t\t  | $$  | $$| $$  | $$| $$ | $$ | $$| $$| $$  | $$\n"
			<< "\t\t\t\t  | $$  | $$|  $$$$$$$| $$ | $$ | $$| $$| $$  | $$\n"
			<< "\t\t\t\t  |__/  |__/ \\_______/|__/ |__/ |__/|__/|__/  |__/\n"
            << "\t\t\t\t   ==============================================\n\n";
                                                
                                                





		cout << "\t\t\t Hello Boss " << currentAdmin->getName() << ", How many employees are you willing to fire today ? \n"
			<< "\t\t\t\t\t\t Salary: " << currentAdmin->getSalary() << "$\n\n"
			<< "\t\t\t\t 1. Add a Client.\t\t5. Add an Employee.\n"
			<< "\t\t\t\t 2. List all Clients.\t\t6. List all Employees.\n"
			<< "\t\t\t\t 3. Edit a Client.\t\t7. Edit an Employee.\n"
			<< "\t\t\t\t 4. Remove a Client.\t\t8. Fire an Employee. \n\n"
			<< "\t\t\t\t\t\t 9. List all Admins.\n"
			<< "\t\t\t\t\t\t 0. Update Password.\n\n"
			<< "\t\t\t\t\t\t      Q. Logout.\n\n";
    }
	static void adminScreen(Admin* currentAdmin)
	{
		while (true)
		{
		printAdminMenu(currentAdmin);
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
			EmployeeManager::removeClient();
			break;
		case KEY_5:
			addEmployee();
			break;
		case KEY_6:
			listAllEmployees();
			break;
		case KEY_7:
			editEmployee();
			break;
		case KEY_8:
			fireEmployee();
			break;
		case KEY_9:
			listAllAdmins();
			break;
		case KEY_0:
			updatePassword(currentAdmin);
			break;
		case KEY_Q:
			PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_SYNC);
			return;
		default:
			PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_SYNC);
			break;
		}
		}
	}
	
	//Menu Option Methods.
	static Admin* adminFindByID(int ID)
	{
		Admin* currentAdmin = nullptr;

		for (int i = 0; i < Admin::allAdmins.size(); i++)
		{
			if (Admin::allAdmins[i].getID() == ID) //if Admin found
			{
				currentAdmin = &Admin::allAdmins[i];
			}
		}
		return currentAdmin;
	}
	static void addEmployee()
	{
		string name;
		string password;
		string salaryStr;
		double salary;
		cout << "Enter Admin's Name: ";
		getline(cin, name);
		cout << "Enter Admin's Password: ";
		getline(cin, password);
		cout << "Enter Admin's Salary: ";
		getline(cin, salaryStr);
		stringstream(salaryStr) >> salary;

		if (Admin::addEmployee(Admin::Admin(name, password, salary)))
		{
			cout << "\nEmployee Added Successfully!\n";
		}
		else
		{
			cout << "\nInvalid Properties\n";
		}
		system("Pause");
	}
	static void listAllEmployees()
	{
		system("CLS");
		cout << "----------------------------------\nEmployee Data:\n----------------------------------\n \n";
		for (int i = 0; i < Admin::allEmployees.size(); i++) {

			Admin::allEmployees[i].display();
		}
		cout << endl;
		system("pause");
	}
	static void editEmployee()
	{
		int employeeID = 0;
		string idStr;
		string newName;
		string newPassword;
		double newSalary = 0;
		string salaryStr;

		cout << "Enter Employee's ID: ";
		getline(cin, idStr);
		stringstream(idStr) >> employeeID;
		Employee* e = Admin::searchEmployeeByID(employeeID);
		if (e == NULL)
		{
			PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("CLS");
			system("color 04");
			cout << "Employee not found, Please try again.\n";
			Sleep(1000);
		}
		else
		{
			cout << "Enter New Name: ";
			getline(cin, newName);

			if (e->setName(newName))
			{
				cout << "Name Change Successful\n";
			}
			else
			{
				cout << "Invalid Name\n";
			}
			cout << "\nEnter New Password: ";
			getline(cin, newPassword);

			if (e->setPassword(newPassword))
			{
				cout << "Password Change Successful\n";
			}
			else
			{
				cout << "Invalid Password\n";
			}
			cout << "\nEnter New Salary: ";
			getline(cin, salaryStr);
			stringstream(salaryStr) >> newSalary;
			if (e->setSalary(newSalary))
			{
				cout << "Salary Update Successful\n";
			}
			else
			{
				cout << "Invalid Salary\n";
			}
			system("Pause");
		}
	}
	static void listAllAdmins()
	{
		system("CLS");
		cout << "----------------------------------\nAdmin Data:\n----------------------------------\n \n";
		for (int i = 0; i < Admin::allAdmins.size(); i++) {

			Admin::allAdmins[i].display();
		}
		cout << endl;
		system("pause");
	}
	static void fireEmployee()
	{
		int employeeID = 0;
		string idStr;
		cout << "Enter Employee's ID: ";
		getline(cin, idStr);
		stringstream(idStr) >> employeeID;
		Employee* currentEmployee = Admin::searchEmployeeByID(employeeID);
		if (currentEmployee == NULL)
		{
			PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("CLS");
			system("color 04");
			cout << "Employee not found, Please try again.\n";
			Sleep(1000);
		}
		else
		{
			auto it = Employee::allEmployees.begin();
			system("CLS");
			system("color 04");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t======================================\n\n"
				<< "\t\t\t\t      ARE YOU SURE YOU WANT TO FIRE THIS EMPLOYEE ?\n"
				<< "\t\t\t\t          HE WON'T BE ABLE TO FEED HIS FAMILY!\n\n"
				<< "\t\t\t\t\t         Press (Y) to confirm.\n\n"
				<< "\t\t\t\t\t======================================\n\n\t\t\t\t";
			PlaySound(TEXT("warning.wav"), NULL, SND_FILENAME | SND_SYNC);
			char key = _getch();
			switch (key)
			{
			case KEY_Y:
				it = remove_if(Employee::allEmployees.begin(), Employee::allEmployees.end(),
					[currentEmployee](const Employee& employee) {
						return employee.getID() == currentEmployee->getID();
					});
				Employee::allEmployees.erase(it, Employee::allEmployees.end());
				PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				system("Color 0A");
				cout << "Employee Fired Successfully.\n";
				system("pause");
				break;
			default:
				break;
			}
		}
	}
};

