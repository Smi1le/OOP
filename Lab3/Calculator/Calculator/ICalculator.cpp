#include "stdafx.h"
#include "ICalculator.h"
#include <string>
#include <iostream>
#include <boost\algorithm\string.hpp>
#include <boost/algorithm/string/split.hpp>

using namespace std;

void CICalculator::SetCommand()
{
	string command;
	Help();
	do
	{
		cout << ">> ";
		getline(cin, command);
	} while (ParsingInputCommands(command));
}

bool CICalculator::ParsingInputCommands(std::string const & command)
{
	vector<string> instructions;
	boost::split(instructions, command, boost::is_any_of(" "));
	if (instructions[0] == EXIT)
	{
		return false;
	}
	if (instructions[0] == HELP)
	{
		Help();
	}
	else if (instructions[0] == PRINT_VARS)
	{
		if (!PrintAllVars())
		{
			std::cout << "You not initialized not a one variable" << std::endl;
		}
	}
	else if (instructions[0] == PRINT_FNS)
	{
		if (!PrintFunctions())
		{
			std::cout << "You not initialized not a one function" << std::endl;
		}
	}
	else if (instructions.size() < 2)
	{
		std::cout << "An incorrect number of data" << endl;
	}
	if (instructions[0] == ADD_VAR)
	{
		if (!AddVariable(instructions[1]))
		{
			std::cout << "It is impossible to add a variable" << std::endl;
		}
	}
	else if (instructions[0] == ASS_VALUES_TO_VAR)
	{
		if (IsNumber(instructions[3]))
		{
			if (!AssValToVar(instructions[1], static_cast<float>(atof(instructions[3].c_str()))))
			{
				std::cout << "It failed to pass the value of one variable to another" << std::endl;
			}
		}
		else
		{
			if (!AssValToVar(instructions[1], instructions[3]))
			{
				std::cout << "Failed to pass the value of the variable" << std::endl;
			}
		}
	}
	else if (instructions[0] == ADD_FUNCTION)
	{
		if (!AddFunction(instructions))
		{
			std::cout << "It is impossible to add a function" << std::endl;
		}
	}
	else if (instructions[0] == PRINT)
	{
		if (!Print(instructions[1]))
		{
			std::cout << "You did not create a variable and a function with the same name" << std::endl;
 		}
	}
	return true;
}

void CICalculator::Help()
{
	std::cout << "Use the following input formats:" << std::endl;
	std::cout << "var <id> - to initialize a variable." << std::endl;
	std::cout << "let <id> = <number> - for the transmission of variable values." << std::endl;
	std::cout << "let <id1> = <id2> - for the transmission of variable values." << std::endl;
	std::cout << "fn <id1> = <id2> - initialization function." << std::endl;
	std::cout << "fn <id1> = <id2> <operation> <id3> - initialization function." << std::endl;
	std::cout << "print <id> - to output a predetermined identifier." << std::endl;
	std::cout << "printvars - for output all variables." << std::endl;
	std::cout << "printfns - for output all functions." << std::endl;
	std::cout << "If you need help write Help" << std::endl;
	std::cout << "To write the end of the program ..." << std::endl;

}