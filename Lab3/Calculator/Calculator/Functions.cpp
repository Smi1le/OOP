#include "stdafx.h"
#include "Functions.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

bool CFunctions::IsNumber(std::string const &val)
{
	for (auto elem : val) {
		if (!isdigit(elem) && elem != '.')
		{
			return false;
		}
	}
	return true;
}

bool CFunctions::AddVariable(std::string const & var, double val)
{
	if (!m_dictionaryVariables.empty() && m_dictionaryVariables.find(var) != m_dictionaryVariables.end())
	{
		return false;
	}
	m_dictionaryVariables.insert(std::pair<string, double>(var, (round(val * 100) / 100)));
	return true;
}

bool CFunctions::AssValToVar(std::string const & var1, double val)
{
	if (!m_dictionaryVariables.empty() && m_dictionaryVariables.find(var1) != m_dictionaryVariables.end())
	{
		m_dictionaryVariables.at(var1) = round(val * 100) / 100;
		return true;
	}
	return AddVariable(var1, val);
}

bool CFunctions::AssValToVar(std::string const & var1, std::string const & var2)
{
	auto element = m_dictionaryVariables.find(var2);
	if (element == m_dictionaryVariables.end())
	{
		return false;
	}
	if (m_dictionaryVariables.find(var1) != m_dictionaryVariables.end())
	{
		m_dictionaryVariables.at(var1) = element->second;
		return true;
	}
	return AddVariable(var1, element->second);
}

bool CFunctions::AddFunction(Vector const &inst)
{
	std::string nameFunc = inst[1];
	if (!m_dataFunctions.empty() && m_dataFunctions.find(nameFunc) != m_dataFunctions.end())
	{
		//std::cout << "Function with the same name was announced earlier" << std::endl;
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

bool CFunctions::AbilGetVal(std::string const &var, double &number)
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
			AbilGetVal(number1[0], number);
			if (number1.size() > 1)
			{
				AbilGetVal(number1[2], number);
			}
			return true;
		}
	}
	return false;
}

double CFunctions::CalcValTwoVar(std::string const operation, double firstVal, double secondVal) const
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
	return firstVal / secondVal;
}

double CFunctions::GetValFunc(std::string const &name)
{
	auto pair = *m_dataFunctions.find(name);
	auto data = pair.second;
	std::string firstName = data[NUMBER_POS_FIRST_NAME - 3];
	std::string operation, secondName;
	double result = 0;
	if (data.size() > 1)
	{
		operation = data[NUMBER_POS_OPER - 3];
		secondName = data[NUMBER_POS_SEC_NAME - 3];
		double valFirstVar = 0;
		double valSecondVar = 0;
		AbilGetVal(firstName, valFirstVar);
		AbilGetVal(secondName, valSecondVar);
		return CalcValTwoVar(operation, valFirstVar, valSecondVar);
	}
	if (AbilGetVal(firstName, result))
	{
		return result;
	}
	return NAN;
}