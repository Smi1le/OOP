// CarSimulator.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "CCar.h"
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
	CCar car;
	while (car.SetCommand()) { }
    return 0;
}

