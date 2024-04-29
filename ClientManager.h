#pragma once
#include <conio.h>
#include "Client.h"
#include <Windows.h>
#include <mmsystem.h>

#define KEY_Q 113
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_DELETE 127 

#pragma comment(lib, "winmm.lib")


class ClientManager
{
public:
	static Client* clientFindByName(string name)
	{
			Client* c = nullptr;

			for (int i = 0; i < Client::allClients.size(); i++)
			{
				if (Client::allClients[i].getName() == name) //if client found
				{
					c = &Client::allClients[i];
					return c;
				}
			}
			return nullptr;
	}

	static void printClientMenu(Client* c)
	{
		system("CLS");
		system("Color 0E");
		PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_ASYNC);
		//PlaySound(TEXT("client.wav"), NULL, SND_FILENAME | SND_ASYNC);

		cout << "\t\t\t\t\t   _____  _     _____ _____ _   _ _____           \n"
			<< "\t\t\t\t\t  /  __ \\| |   |_   _|  ___| \\ | |_   _|         \n"
			<< "\t\t\t\t\t  | /  \\/| |     | | | |__ |  \\| | | |           \n"
			<< "\t\t\t\t\t  | |    | |     | | |  __|| . ` | | |           \n"
			<< "\t\t\t\t\t  | \\__/\\| |_____| |_| |___| |\\  | | |           \n"
			<< "\t\t\t\t\t   \\____/\\_____/\\___/\\____/\\_| \\_/ \\_/           \n"
			<< "\t\t\t\t\t =======================================\n\n\n";





		cout << "\t\t\t  Hello dear " << c->getName() << ", How can we serve your pocket today ? \n"
			<< "\t\t\t\t\t\t  Balance: " << c->getBalance() << "$\n"
			<< "\t\t\t\t\t\t  ID: " << c->getID() << "\n\n"
			<< "\t\t\t\t1. Deposit.\n"
			<< "\t\t\t\t2. Withdraw.\n"
			<< "\t\t\t\t3. Transfer To.\n"
			<< "\t\t\t\t4. Update Password.\n\n"
			<< "\t\t\t\t Q. Logout.\n\n";
	}

	static void clientScreen(Client* c) // Too bloated, Needs refactoring.
	{

		double amount = 0;
		string recepient;
		Client* rec = NULL;
		string currentPassword;
		string newPassword;
		
		while (true)
		{
		printClientMenu(c);

		char key = _getch();
		switch (key)
		{
		case KEY_1:
			cout << "How much would you like to give us ? :D : ";
			cin >> amount;
			if (c->deposit(amount))
			{
				PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				cout << "Deposit Successful, Thanks for giving us more money.\n";
				system("pause");
			}
			else
			{
				PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				cout << "Deposit Failed,I said give us, Not take from us!! (Enter a Positive Number)\n";
				system("pause");
			}
			break;
		case KEY_2:
			cout << "How much would you like to take from us ? :( : ";
			cin >> amount;
			if (c->withdraw(amount))
			{
				PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				cout << "Withdraw Successful, Please don't do that again!\n";
				system("pause");
			}
			else
			{
				PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				cout << "Withdraw Failed, Phew that was close!\n";
				system("pause");
			}
			break;
		case KEY_3: //_-----------------------------> Not working yet.
			cout << "Who would you like to transfer to ?: \n";
			cin >> recepient;
			rec = clientFindByName(recepient);
			if (rec == nullptr)
			{
				PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				cout << "Client not found, Please try Again.\n";
				system("pause");
				break;
			}
			else
			{
				cout << "How much would you like to transfer ?: \n";
				cin >> amount;
				if (c->transferTo(amount, *rec))
				{
					PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC);
					system("CLS");
					cout << "Transfer Complete, Hooray!\n";
					system("pause");
				}
				else
				{
					PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
					system("CLS");
					cout << "Transfer Failed, Mhmmmm?\n";
					system("pause");
				}
			}
			break;
		case KEY_4:
			cout << "Confirm your password: ";
			cin >> currentPassword;
			if (c->getPassword() == currentPassword)
			{
				cout << "Enter your new password: ";
				cin >> newPassword;
				if (c->setPassword(newPassword))
				{
					PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC);
					system("CLS");
					cout << "Password Change Accepted.\n";
					system("pause");
				}
				else
				{
					PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
					system("CLS");
					cout << "Password Invalid.\n";
					system("pause");
				}
			}
			else
			{
				PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				cout << "Invalid Password.\n";
				system("pause");
			}
			break;
		case KEY_Q:
			return;
		}
		}
	}

};

