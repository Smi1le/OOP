#include "stdafx.h"
#pragma warning (disable: 4996)
#include "Config.h"
#include "GetDataWithFile.h"
#include <fstream>
#include <iostream>
#include <boost\algorithm\string.hpp>
#include <boost\algorithm\string\split.hpp>

using namespace std;

dataShapes ReadFromFile(std::string const &nameInputFile)
{
	ifstream inputFile(nameInputFile);
	string command;
	vector<string> info;
	if (!inputFile.is_open())
	{
		cout << "It is impossible to consider that you have entered the file" << endl;
	}
	while (std::getline(inputFile, command))
	{
		info.push_back(command);
	}
	return  ParseInfo(info);

}

dataShapes ParseInfo(vector<string> const &info)
{
	dataShapes data;
	for (auto elem : info)
	{
		vector<string> inst;
		boost::split(inst, elem, boost::is_any_of(" "));
		for (auto &elem1 : inst)// Удаление лишних элементов, которые могли остаться после парсинга
		{
			if (elem1[0] == COMMA)
			{
				elem1.erase(0, 1);
			}
			if (elem1[elem1.size() - 1] == COMMA)
			{
				elem1.erase(elem1.size() - 1, elem1.size() - 2);
			}
		}
		data.push_back(inst);
	}
	return data;
}