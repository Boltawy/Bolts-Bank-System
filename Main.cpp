#include <iostream>
#include "Client.h"
#include "Admin.h"
#include "FileManager.h"
#include "Parser.h"
using namespace std;

int main()
{
	//testing readFromDatabase
	//Client x("Micheal", "Ab12345678", 1, 5000);
	//Client x2("Micheal Schwartz", "Ab12345678", 2, 5000);
	//Client x3("Micheal Schwartz", "Ab12345678", 3, 5000);
	//Client x4("Micheal Schwartz", "Ab12345678", 4, 5000);
	//Client x5("Micheal Schwartz", "Ab12345678", 5, 5000);
	//Employee z("Franklin", "87654321", 3, 100000);


	//z.addClient(x);
	//z.addClient(x2);
	//z.addClient(x3);
	//z.addClient(x4);
	//z.addClient(x5);
	// 
	//testing split and reading from client database.
	cout << Parser::split(Parser::getClientByID(1))[3];

	//testing reading from a file
	//string line = "1#Micheal#Ab12345678#5000.000000";
	//cout << stoi(line.substr(0, line.find('#')));
}