#include "stdafx.h"
#include "Functions.h"
#include <string>
#include <iostream>
#include <boost\algorithm\string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <cmath>

using namespace std;

void CCalculator::SetCommand()
{
	string command;
	do
	{
		cout << ">> ";
		getline(cin, command);
		vector<string> instructions;
		boost::split(instructions, command, boost::is_any_of(" "));
		CommandDefinition(instructions);
	} while (!std::cin.eof() && !std::cin.fail());


}

float CCalculator::GetValue(std::string const &var)
{
	auto element = *m_dictionaryVariables.find(var);
	return element.second;
}

bool CCalculator::IsNumber(std::string const &val)
{
	for (auto elem : val)
	{
		int number = static_cast<int>(elem) - 48;
		if (elem == '.') {}
		else if (number >= 0 && number <= 9) {}
		else
		{
			return false;
		}
	}
	return true;
}

void CCalculator::CommandDefinition(Vector const & inst)
{
	if (inst[0] == PRINT_VARS)
	{
		PrintAllVars();
	}
	else if (inst[0] == PRINT_FNS)
	{
		PrintFunctions();
	}
	else if (inst.size() < 2)
	{
		std::cout << "An incorrect number of data" << endl;
	}
	if (inst[0] == ADD_VAR)
	{
		std::cout << "ADD_VAR" << std::endl;
		AddVariable(inst[1]);
	}
	else if (inst[0] == ASS_VALUES_TO_VAR)
	{
		std::cout << "ASS_VALUES_TO_VAR" << std::endl;

		if (IsNumber(inst[3]))
		{
			AssValToVar(inst[1], atof(inst[3].c_str()));
		}
		else 
		{
			AssValToVar(inst[1], inst[3]);
		}
	}
	else if (inst[0] == ADD_FUNCTION)
	{
		AddFunction(inst);
	}
	else if (inst[0] == PRINT)
	{
		std::cout << "Print var" << std::endl;
		PrintVar(inst[1]);
	}
}

bool CCalculator::AddVariable(std::string const & var, float val)
{
	if (!m_dictionaryVariables.empty() && m_dictionaryVariables.find(var) != m_dictionaryVariables.end())
	{
		std::cout << "Such a variable already exists.\n";
		return false;
	}
	m_dictionaryVariables.insert(std::pair<string, float>(var, (round(val * 100) / 100)));
	return true;
}

bool CCalculator::AssValToVar(std::string const & var1, float val)
{
	if (!m_dictionaryVariables.empty() && m_dictionaryVariables.find(var1) != m_dictionaryVariables.end())
	{
		m_dictionaryVariables.at(var1) = round(val * 100) / 100;
		return true;
	}
	return AddVariable(var1, val);
}

bool CCalculator::AssValToVar(std::string const & var1, std::string const & var2)
{
	auto element = m_dictionaryVariables.find(var2);
	if (element == m_dictionaryVariables.end())
	{
		std::cout << "Error! The second variable is not declared!" << std::endl;
		return false;
	}
	if (m_dictionaryVariables.find(var1) != m_dictionaryVariables.end())
	{
		m_dictionaryVariables.at(var1) = element->second;
		return true;
	}
	return AddVariable(var1, element->second);
}

void CCalculator::PrintVar(std::string const &var)
{
	auto outElem = m_dictionaryVariables.find(var);
	if (outElem != m_dictionaryVariables.end())
	{
		std::cout << outElem->second << endl;
	}
	else
	{
		auto outElem1 = m_dataFunctions.find(var);
		if (outElem1 != m_dataFunctions.end())
		{
			std::cout << (*outElem1).first << ":" << GetValFunc((*outElem1).first) << std::endl;
		}
	}
}

void CCalculator::PrintAllVars()
{
	for (auto elem : m_dictionaryVariables)
	{
		cout << elem.first << ":" << elem.second << endl;
	}
}

bool CCalculator::AddFunction(Vector const &inst)
{
	std::string nameFunc = inst[1];
	if (!m_dataFunctions.empty() && m_dataFunctions.find(nameFunc) != m_dataFunctions.end())
	{
		std::cout << "Function with the same name was announced earlier" << std::endl;
		return false;
	}
	vector<string> data;
	std::string firstName = inst[NUMBER_POS_FIRST_NAME];
	data.push_back(firstName);
	if (inst.size() > 4)
	{
		std::string operation = inst[NUMBER_POS_OPER];
		std::string secondName = inst[NUMBER_POS_SEC_NAME];
		data.push_back(operation);
		data.push_back(secondName);
	}
	m_dataFunctions.insert(dataOneFunction(nameFunc, data));
	return true;
}

bool CCalculator::GetVal(std::string const &var, float &number)
{
	if (!m_dictionaryVariables.empty())
	{
		auto element = m_dictionaryVariables.find(var);
		if (element != m_dictionaryVariables.end())
		{
			number += (*element).second;
			return true;
		}
	}
	if (!m_dataFunctions.empty())
	{
		auto element = m_dataFunctions.find(var);
		if (element != m_dataFunctions.end())
		{
			auto number1 = (*element).second;
			GetVal(number1[0], number);
			if (number1.size() > 1)
			{
				GetVal(number1[2], number);
			}
			return true;
		}
	}
	return false;
}

float CCalculator::CalcVal(std::string const operation, float firstVal, float secondVal)
{
	if (operation == "*")
	{
		return firstVal * secondVal;
	}
	if (operation == "-")
	{
		return firstVal - secondVal;
	}
	if (operation == "+")
	{
		return firstVal + secondVal;
	}
	if (operation == "/")
	{
		return firstVal / secondVal;
	}
}

float CCalculator::GetValFunc(std::string const &name)
{
	auto pair = *m_dataFunctions.find(name);
	auto data = pair.second;
	std::string firstName = data[NUMBER_POS_FIRST_NAME - 3];
	std::string operation, secondName;
	float result = 0;
	if (data.size() > 1)
	{
		operation = data[NUMBER_POS_OPER - 3];
		secondName = data[NUMBER_POS_SEC_NAME - 3];
		float valFirstVar = 0;
		float valSecondVar = 0;
		GetVal(firstName, valFirstVar);
		GetVal(secondName, valSecondVar);
		return CalcVal(operation, valFirstVar, valSecondVar);
	}
	if (GetVal(firstName, result))
	{
		return result;
	}
}


void CCalculator::PrintFunctions()
{
	if (m_dataFunctions.empty())
	{
		std::cout << "You not initialized not a one function" << std::endl;//TODO: криво написал, переписать на нормальный англ язык
	}
	for (auto elem : m_dataFunctions)
	{
		std::cout << elem.first << ":" << GetValFunc(elem.first) << std::endl;
	}
}