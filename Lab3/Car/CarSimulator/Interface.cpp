#include "stdafx.h"
#include "Interface.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>


using namespace std;

bool CInterface::SetCommand()
{

	cout << ">> Please enter command\n";
	cout << ">> ";
	string command;
	vector<string> instructions;
	getline(cin, command);
	boost::split(instructions, command, boost::is_any_of(" "));
	string nameCommand = instructions[0];
	if (nameCommand == "EXIT")
	{
		return false;
	}
	if (nameCommand == "Help")
	{
		Help();
	}
	if (nameCommand == "Info")
	{
		Info();
	}
	else if (nameCommand == "EngineOn")
	{
		if (!m_car->TurnOnEngine())
		{
			std::cout << "It is impossible to start the engine" << std::endl;
		}
	}
	else if (nameCommand == "EngineOff")
	{
		if (!m_car->TurnOffEngine())
		{
			std::cout << "It is impossible to turn off the engine" << std::endl;
		}
	}
	else if (nameCommand == "SetGear")
	{
		if (!m_car->SetGear(atoi(instructions[1].c_str())))
		{
			std::cout << "It is impossible to shift gears" << std::endl;
		}
	}
	else if (nameCommand == "SetSpeed")
	{
		if (!m_car->SetSpeed(atoi(instructions[1].c_str())))
		{
			std::cout << "It is impossible to change the speed" << std::endl;
		}
	}
	else
	{
		std::cout << "Entered an incorrect command" << std::endl;
	}
	return true;
}

void CInterface::Info() const
{
	if (m_car->IsTurnedOn())
	{
		cout << "Engine is turn on.\n";
	}
	else
	{
		cout << "Engine is turn off.\n";
	}
	cout << "Car has the " << m_car->GetSpeed() << " speed\n";
	cout << "Car has the " << m_car->GetGear() << " gear\n";
	int ValStatus = m_car->GetStatus();
	if (ValStatus == -1)
	{
		cout << "Car moves backwards.\n";
	}
	else if (ValStatus == 0)
	{
		cout << "The car is stationary.\n";
	}
	else if (ValStatus == 1)
	{
		cout << "Car moves forward.\n";
	}
}

void CInterface::Help() const
{
	std::cout << "Machine control commands: " << std::endl;
	std::cout << "EngineOn - engine starts" << std::endl;
	std::cout << "EngineOff - switch off the engine" << std::endl;
	std::cout << "SetSpeed X - changes speed" << std::endl;
	std::cout << "SetGear X - changes gear" << std::endl;
	std::cout << "Info - displays information about the car" << std::endl;
	std::cout << "If you need help write Help" << std::endl;
	std::cout << "To complete the program, type the word EXIT" << std::endl;
}