#include "stdafx.h"
#include "ICalculator.h"
#include <string>
#include <iostream>
#include <boost\algorithm\string.hpp>
#include <boost\algorithm\string\split.hpp>
#include <iterator>
#include <algorithm>

using namespace std;

CCalculatorHelper::CCalculatorHelper()
{
	m_data = std::make_shared<DataProgram>();
	m_functions = std::make_shared<CFunctions>(m_data);
	m_outputData = std::make_shared<COutputData>(m_data);
}

void CCalculatorHelper::SetCommand()
{
	string command;
	Help();
	do
	{
		cout << ">> ";
		getline(cin, command);
	} while (ParsingInputCommands(command));
}

bool CCalculatorHelper::ParsingInputCommands(std::string const & command)
{
	vector<string> instructions;
	boost::split(instructions, command, boost::is_any_of(" "));
	if (CorrectInput(instructions))
	{
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
			if (!m_outputData->PrintVariables())
			{
				std::cout << "You not initialized not a one variable" << std::endl;
			}
		}
		else if (instructions[0] == PRINT_FNS)
		{
			if (!m_outputData->PrintFunctions())
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
			if (!m_functions->AddVariable(instructions[1]))
			{
				std::cout << "It is impossible to add a variable" << std::endl;
			}
		}
		else if (instructions[0] == ASS_VALUES_TO_VAR)
		{
			if (IsNumber(instructions[3]))
			{
				if (!m_functions->AssValToVar(instructions[1], atof(instructions[3].c_str())))
				{
					std::cout << "It failed to pass the value of one variable to another" << std::endl;
				}
			}
			else
			{
				if (!m_functions->AssValToVar(instructions[1], instructions[3]))
				{
					std::cout << "Failed to pass the value of the variable" << std::endl;
				}
			}
		}
		else if (instructions[0] == ADD_FUNCTION)
		{
			if (!m_functions->AddFunction(instructions))
			{
				std::cout << "It is impossible to add a function" << std::endl;
			}
		}
		else if (instructions[0] == PRINT)
		{
			if (instructions.size() > 1 && !m_outputData->Print(instructions[1]))
			{
				std::cout << "You did not create a variable and a function with the same name" << std::endl;
			}
		}
	}
	//Update();
	return true;
}

void CCalculatorHelper::Help()const
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
	std::cout << "To write the end of the program EXIT" << std::endl;

}

bool CCalculatorHelper::CorrectInput(Vector const &instructions) const 
{
	if (instructions[0] == EXIT || instructions[0] == PRINT_FNS ||
		instructions[0] == PRINT_VARS || instructions[0] == HELP ||
		(instructions[0] == ADD_VAR && instructions.size() == 2) ||
		(instructions[0] == ASS_VALUES_TO_VAR && (instructions.size() == 4)) ||
		(instructions[0] == ADD_FUNCTION && (instructions.size() == 4 || (instructions.size() == 6 && IsOperation(instructions[4])))) ||
		(instructions[0] == PRINT && instructions.size() == 2))
	{
		return true;
	}
	return false;
}

bool CCalculatorHelper::IsOperation(std::string const &op) const
{
	return (op == "*" || op == "+" || op == "-" || op == "/");
}

double CCalculatorHelper::GetValue(std::string const &var)
{

	auto element = *m_data->m_dataVariables.find(var);
	return element.second;
}

bool CCalculatorHelper::IsNumber(std::string const &val) const
{
	for (auto elem : val) {
		if (!isdigit(elem) && elem != '.')
		{
			return false;
		}
	}
	return true;
}