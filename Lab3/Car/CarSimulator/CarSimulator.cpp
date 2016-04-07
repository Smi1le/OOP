// CarSimulator.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CCar.h"
#include <iostream>
#include <iterator>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>


void Help()
{
	std::cout << "Machine control commands: " << std::endl;
	std::cout << "EngineOn - engine starts" << std::endl;
	std::cout << "EngineOff - switch off the engine" << std::endl;
	std::cout << "SetSpeed X - changes speed" << std::endl;
	std::cout << "SetGear X - changes gear" << std::endl;
	std::cout << "Info - displays information about the car" << std::endl;
}

int main()
{
	CCar car;
	Help();
	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << ">> ";
		std::cout << "Please enter command\n";
		std::string command;
		std::vector<std::string> instructions;
		std::getline(std::cin, command);
		boost::split(instructions, command, boost::is_any_of(" "));
		if (instructions[0] == "")
		{
			std::cout << "GoodBay " << std::endl;
			return false;
		}
		if (instructions[0] == "Info")
		{
			car.Info();
		}
		else if (instructions[0] == "EngineOn")
		{
			car.TurnOnEngine();
		}
		else if (instructions[0] == "EngineOff")
		{
			car.TurnOffEngine();
		}
		else if (instructions[0] == "SetGear")
		{
			car.SetGear(atoi(instructions[1].c_str()));
		}
		else if (instructions[0] == "SetSpeed")
		{
			car.SetSpeed(atoi(instructions[1].c_str()));
		}
		else if (instructions[0] == "Help")
		{
			Help();
		}
		else
		{
			std::cout << "Invalid command!" << std::endl;
		}
	}

    return 0;
}

