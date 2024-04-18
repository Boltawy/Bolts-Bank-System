#include <iostream>
#include "Client.h"
#include "Admin.h"
#include "FileManager.h"
#include "Parser.h"
using namespace std;

int main()
{
	//testing client ID generation
	Employee z("Franklin", "87654321", 100000);
	Client x("Micheal", "Ab12345678", 5000);
	z.addClient(x);
	Client x2("Micheal Schwartz", "Ab12345678", 5000);
	z.addClient(x2);
	Client x3("Micheal Schwartz", "Ab12345678", 5000);
	z.addClient(x3);
	Client x4("Micheal Schwartz", "Ab12345678", 5000);
	z.addClient(x4);
	Client x5("Micheal Schwartz", "Ab12345678", 5000);
	z.addClient(x5);


	// 
	//testing split and reading from client database.
	//cout << Parser::split(Parser::getClientByID(1))[3];

	//testing reading from a file
	//string line = "1#Micheal#Ab12345678#5000.000000";
	//cout << stoi(line.substr(0, line.find('#')));


	//testing getLastID from Client
	//cout << Client::getLastID();
}