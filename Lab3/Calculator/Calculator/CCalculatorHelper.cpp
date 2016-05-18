#include "stdafx.h"
#include "CCalculatorHelper.h"
#include <string>
#include <iostream>
#include <boost\algorithm\string.hpp>
#include <boost\algorithm\string\split.hpp>
#include <algorithm>

using namespace std;

void CCalculatorHelper::SetCommand()
{
	string command;
	Help();
	do
	{
		cout << ">> ";
		getline(cin, command);
	} while (CallCommand(command));
}

static bool IsNumber(string const &val)
{
	for (auto elem : val) {
		if (!isdigit(elem) && elem != '.')
		{
			return false;
		}
	}
	return true;
}

bool CCalculatorHelper::CallCommand(string const & command)
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
			if (!m_calculator.PrintVariables())
			{
				cout << "You not initialized not a one variable" << endl;
			}
		}
		else if (instructions[0] == PRINT_FNS)
		{
			if (!m_calculator.PrintFunctions())
			{
				cout << "You not initialized not a one function" << endl;
			}
		}
		else if (instructions.size() < 2)
		{
			cout << "An incorrect number of data" << endl;
		}
		if (instructions[0] == ADD_VAR)
		{
			if (!m_calculator.AddVariable(instructions[1]))
			{
				cout << "It is impossible to add a variable" << endl;
			}
		}
		else if (instructions[0] == ASSIGN_VALUES_TO_VAR)
		{
			AssignValueToVariable(instructions);
		}
		else if (instructions[0] == ADD_FUNCTION)
		{
			if (!m_calculator.AddFunction(instructions))
			{
				cout << "It is impossible to add a function" << endl;
			}
		}
		else if (instructions[0] == PRINT)
		{
			if (!m_calculator.Print(instructions[1]))
			{
				cout << "You did not create a variable and a function with the same name" << endl;
			}
		}
	}
	return true;
}

void CCalculatorHelper::AssignValueToVariable(vector<string> const & instructions)
{
	if (IsNumber(instructions[3]))
	{
		if (!m_calculator.AssignValToVar(instructions[1], atof(instructions[3].c_str())))
		{
			cout << "It failed to pass the value of one variable to another" << endl;
		}
	}
	else
	{
		if (!m_calculator.AssignValToVar(instructions[1], instructions[3]))
		{
			cout << "Failed to pass the value of the variable" << endl;
		}
	}
}

void CCalculatorHelper::Help()const
{
	cout << "Use the following input formats:" << endl;
	cout << "var <id> - to initialize a variable." << endl;
	cout << "let <id> = <number> - for the transmission of variable values." << endl;
	cout << "let <id1> = <id2> - for the transmission of variable values." << endl;
	cout << "fn <id1> = <id2> - initialization function." << endl;
	cout << "fn <id1> = <id2> <operation> <id3> - initialization function." << endl;
	cout << "print <id> - to output a predetermined identifier." << endl;
	cout << "printvars - for output all variables." << endl;
	cout << "printfns - for output all functions." << endl;
	cout << "If you need help write Help" << endl;
	cout << "To write the end of the program EXIT" << endl;

}

bool CCalculatorHelper::CorrectInput(Vector const &instructions) const 
{
	if (instructions.size() >= 1 && (instructions[0] == EXIT || instructions[0] == PRINT_FNS ||
		instructions[0] == PRINT_VARS || instructions[0] == HELP ||
		(instructions[0] == ADD_VAR && instructions.size() == 2) ||
		(instructions[0] == ASSIGN_VALUES_TO_VAR && (instructions.size() == 4)) ||
		(instructions[0] == ADD_FUNCTION && (instructions.size() == 4 || (instructions.size() == 6 && IsOperation(instructions[4])))) ||
		(instructions[0] == PRINT && instructions.size() == 2)))
	{
		return true;
	}
	return false;
}

bool CCalculatorHelper::IsOperation(string const &op) const
{
	return (op == "*" || op == "+" || op == "-" || op == "/");
}