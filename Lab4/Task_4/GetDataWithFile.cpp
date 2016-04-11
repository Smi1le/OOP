#include "stdafx.h"
#include "Config.h"
#include "GetDataWithFile.h"
#include <fstream>
#include <iostream>
#include <boost\algorithm\string.hpp>
#include <boost\algorithm\string\split.hpp>

dataShapes GetDataWithFile(std::string const &nameInputFile)
{
	std::ifstream inputFile(nameInputFile);
	std::string command;
	std::vector<std::string> info;
	if (!inputFile.is_open())
	{
		std::cout << "It is impossible to consider that you have entered the file" << std::endl;
	}
	while (std::getline(inputFile, command))
	{
		info.push_back(command);
	}
	dataShapes data = ParsingInfoShapes(info);
	return data;

}

dataShapes ParsingInfoShapes(std::vector<std::string> const &info)
{
	dataShapes data;
	for (auto elem : info)
	{
		std::vector<std::string> inst;
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