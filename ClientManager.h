#pragma once
#include <conio.h>
#include "Client.h"
#include <Windows.h>
#include <mmsystem.h>

#define KEY_Q 113
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_DELETE 127 

#pragma comment(lib, "winmm.lib")


class ClientManager
{
public:
	static Client* clientFind(string name)
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
	static void clientMenu(Client* c)
	{
		double amount = 0;
		string recepient;
		Client* rec;
		
		while (true)
		{
		system("CLS");
		PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_ASYNC);
		//PlaySound(TEXT("client.wav"), NULL, SND_FILENAME | SND_ASYNC);
		cout << "Hello dear " << c->getName() << ", How can we serve your pocket today ? \n"
			<< "Your Balance is: " << c->getBalance() << endl
			<< "1. Deposit.\n"
			<< "2. Withdraw.\n"
			<< "3. Transfer To.\n"
			<< "Q. Logout.\n";
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
		case KEY_3:
			cout << "Who would you like to transfer to ?: \n";
			cin >> recepient;
			rec = clientFind(recepient);
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
		case KEY_Q:
			return;
		}
		}
	}
	static void clientLogout()
	{
		//Screens::loginScreen;
		return;
	}

};

