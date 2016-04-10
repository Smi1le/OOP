// CarSimulator.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Interface.h"
#include <iostream>


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
	Help();
	CInterface inter;
	while (inter.SetCommand()) { }
    return 0;
}

