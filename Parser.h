#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "FileManager.h"
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



	//static string getEmployeeByID(int id) { //Probably should be private.
	//	string line;
	//	employeeFile.open("Employee_Database.txt", ios::in);
	//	while (getline(employeeFile, line)) { //read every line and assigns it in line string.
	//		int lineId = stoi(line.substr(0, line.find('#'))); //stores the id in a new variable.
	//		if (lineId == id) {
	//			employeeFile.close();
	//			return line;
	//		}
	//	}
	//	employeeFile.close();
	//	return "";
	//}

	//static string getAdminByID(int id) { //Probably should be private.
	//	string line;
	//	adminFile.open("Admin_Database.txt", ios::in);
	//	while (getline(adminFile, line)) { //read every line and assigns it in line string.
	//		int lineId = stoi(line.substr(0, line.find('#'))); //stores the id in a new variable.
	//		if (lineId == id) {
	//			adminFile.close();
	//			return line;
	//		}
	//	}
	//	adminFile.close();
	//	return "";
	//}


public:
};

