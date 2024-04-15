#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "FileManager.h"
using namespace std;
class Parser
{
public: //should be private
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


	static string getClientByID(int id) { //Probably should be private.
		string line;
		FileManager::clientFile.open("Client_Database.txt", ios::in);
		while (getline(FileManager::clientFile, line)) {
			int lineId = stoi(line.substr(0, line.find('#')));
			if (lineId == id) {
				FileManager::clientFile.close();
				return line;
			}
		}
		FileManager::clientFile.close();
		return "";
	}
};

