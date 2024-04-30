#pragma once
#include <conio.h>
#include "Client.h"
#include <Windows.h>
#include <sstream>
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
	//Screen & Menu.
	static void printClientMenu(Client* currentClient)
	{
		system("CLS");
		system("Color 0E");
		PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_ASYNC);
		PlaySound(TEXT("client.wav"), NULL, SND_FILENAME | SND_ASYNC);

		cout << "\t\t\t\t\t   _____  _     _____ _____ _   _ _____           \n"
			<< "\t\t\t\t\t  /  __ \\| |   |_   _|  ___| \\ | |_   _|         \n"
			<< "\t\t\t\t\t  | /  \\/| |     | | | |__ |  \\| | | |           \n"
			<< "\t\t\t\t\t  | |    | |     | | |  __|| . ` | | |           \n"
			<< "\t\t\t\t\t  | \\__/\\| |_____| |_| |___| |\\  | | |           \n"
			<< "\t\t\t\t\t   \\____/\\_____/\\___/\\____/\\_| \\_/ \\_/           \n"
			<< "\t\t\t\t\t  =====================================\n\n\n";





		cout << "\t\t\t\tHello dear " << currentClient->getName() << ", How can we serve your pocket today ? \n"
			<< "\t\t\t\t\t\t\tBalance: " << currentClient->getBalance() << "$\n"
			<< "\t\t\t\t\t\t\tID: " << currentClient->getID() << "\n\n"
			<< "\t\t\t\t1. Deposit.\n"
			<< "\t\t\t\t2. Withdraw.\n"
			<< "\t\t\t\t3. Transfer To.\n"
			<< "\t\t\t\t4. Update Password.\n\n"
			<< "\t\t\t\t\t\t\tQ. Logout.\n\n";
	}

	static void clientScreen(Client* currentClient)
	{
		while (true)
		{
		printClientMenu(currentClient);

		char key = _getch();
		switch (key)
		{
		case KEY_1:
			clientDeposit(currentClient);
			break;
		case KEY_2:
			clientWithdraw(currentClient);
			break;
		case KEY_3:
			clientTransferTo(currentClient);
			break;
		case KEY_4:
			clientUpdatePassword(currentClient);
			break;
		case KEY_Q:
			PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_SYNC);
			return;
		}
		}
	}

	//Menu Option Methods.
	static Client* clientFindByName(string name)
	{
			Client* currentClient = nullptr;

			for (int i = 0; i < Client::allClients.size(); i++)
			{
				if (Client::allClients[i].getName() == name) //if client found
				{
					currentClient = &Client::allClients[i];
				}
			}
			return currentClient;
	}
	static void clientDeposit(Client* currentClient)
	{
		double amount = 0;
		string amountStr;
		cout << "How much would you like to give us ? :D : ";
		getline(cin, amountStr);
		stringstream(amountStr) >> amount;
		if (currentClient->deposit(amount))
		{
			PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("CLS");
			system("Color 0A");
			cout << "Deposit Successful, Thanks for giving us more money.\n";
			Sleep(1000);
		}
		else
		{
			PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("CLS");
			system("color 04");
			cout << "Deposit Failed, Ehh.\n";
			Sleep(1000);
		}
	}
	static void clientWithdraw(Client* currentClient)
	{
		double amount = 0;
		string amountStr;
		cout << "How much would you like to take from us ? :( : ";
		getline(cin, amountStr);
		stringstream(amountStr) >> amount;
		if (currentClient->withdraw(amount))
		{
			PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("CLS");
			system("Color 0A");
			cout << "Withdraw Successful, Please don't do that again!\n";
			Sleep(1000);
		}
		else
		{
			PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("CLS");
			system("color 04");
			cout << "Withdraw Failed, Phew that was close!\n";
			Sleep(1000);
		}
	}
	static void clientTransferTo(Client* currentClient)
	{
		double amount = 0;
		string amountStr;
		string recepientName;
		cout << "Who would you like to transfer to ?: \n";
		getline(cin, recepientName);
		Client* recepient = clientFindByName(recepientName);
		if (recepient == nullptr)
		{
			PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("CLS");
			system("color 04");
			cout << "Client not found, Please try Again.\n";
			Sleep(1000);
		}
		else if (currentClient == recepient)
		{
			PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("CLS");
			system("color 04");
			cout << "Can't Transfer to yourself, Buddy.\n";
			system("pause");
		}
		else
		{
			cout << "How much would you like to transfer ?: \n";
			getline(cin, amountStr);
			stringstream(amountStr) >> amount;
			if (currentClient->transferTo(amount, *recepient))
			{
				PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				system("Color 0A");
				cout << "Transfer Complete, Hooray!\n";
				Sleep(1000);
			}
			else
			{
				PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				system("color 04");
				cout << "Transfer Failed, Mhmmmm?\n";
				Sleep(1000);
			}
		}
	}
	static void clientUpdatePassword(Client* currentClient)
	{
		string currentPassword;
		string newPassword;
		cout << "Confirm your password: ";
			cin >> currentPassword;
			if (currentClient->getPassword() == currentPassword)
			{
				cout << "Enter your new password: ";
				cin >> newPassword;
				if (currentClient->setPassword(newPassword))
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
};

