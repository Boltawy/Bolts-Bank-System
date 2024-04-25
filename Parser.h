#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "admin.h"
using namespace std;
class Parser
{
private:
	static vector<string> split(string line)
	{
			vector<string> parsedData = {};
		for (int i = 0; i < 4; i++)
		{
			string temp = line.substr(0, line.find('#'));
			parsedData.push_back(temp);
			line.erase(0, (line.find('#') + 1));
		}
			return parsedData;
	}
public:
	static Client parseToClient(string line)
	{
		vector<string> parsedData = split(line);
		Client x = Client(parsedData[1], parsedData[2], stod(parsedData[3]));
		x.setID(stoi(parsedData[0]));
		return x;
	}
	static Employee parseToEmployee(string line)
	{
		vector<string> parsedData = split(line);
		Employee x = Employee(parsedData[1], parsedData[2], stod(parsedData[3]));
		x.setID(stoi(parsedData[0]));
		return x;
	}
	static Admin parseToAdmin(string line)
	{
		vector<string> parsedData = split(line);
		Admin x = Admin(parsedData[1], parsedData[2], stod(parsedData[3]));
		x.setID(stoi(parsedData[0]));
		return x;
	}
};

