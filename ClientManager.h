#pragma once
#include "Client.h"
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

class ClientManager
{
public:
	static Client* ClientLogin(string name)
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
	static Client* ClientLogin(string name, string password)
	{
		Client* c = nullptr;

		for (int i = 0; i < Client::allClients.size(); i++)
		{
			if (Client::allClients[i].getName() == name && Client::allClients[i].getPassword() == password) //if client found and password matches name
			{
				c = &Client::allClients[i];
				return c;
			}
		}
		return nullptr;
	}
	static void clientMenu(Client* c)
	{
		int response1 = -1;
		int response2 = -1;
		while (response2 != 0)
		{
		system("CLS");
		PlaySound(TEXT("message.wav"), NULL, SND_FILENAME | SND_ASYNC);
		PlaySound(TEXT("client.wav"), NULL, SND_FILENAME | SND_ASYNC);
		cout << "Hello dear " << c->getName() << ", How can we serve your pocket today ? \n"
			<< "Your Balance is: " << c->getBalance() << endl
			<< "1. Deposit.\n"
			<< "2. Withdraw.\n"
			<< "3. Transfer To.\n";
		cin >> response1;
		switch (response1)
		{
		case 1:
			double amount;
			cout << "How much would you like to give us ?: ";
			cin >> amount;
			c->deposit(amount);
			cout << "Would you like to do anything else ? y/n"; //Need to fix and return to login menu
		}
		}
	}
	static void clientLogout()
	{
		//Screens::loginScreen;
		return;
	}

};

