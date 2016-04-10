#include "stdafx.h"
#include "Functions.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

float CFunctions::GetValue(std::string const &var)
{
	auto element = *m_dictionaryVariables.find(var);
	return element.second;
}

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

bool CFunctions::AddVariable(std::string const & var, float val)
{
	if (!m_dictionaryVariables.empty() && m_dictionaryVariables.find(var) != m_dictionaryVariables.end())
	{
		return false;
	}
	m_dictionaryVariables.insert(std::pair<string, float>(var, (round(val * 100) / 100)));
	return true;
}

bool CFunctions::AssValToVar(std::string const & var1, float val)
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

bool CFunctions::Print(std::string const &var)
{
	auto outElem = m_dictionaryVariables.find(var);
	if (outElem != m_dictionaryVariables.end())
	{
		std::cout << outElem->second << endl;
		return true;
	}
	else
	{
		auto outElem1 = m_dataFunctions.find(var);
		if (outElem1 != m_dataFunctions.end())
		{
			std::cout << (*outElem1).first << ":" << GetValFunc((*outElem1).first) << std::endl;
			return true;
		}
	}
	return false;
}

bool CFunctions::PrintAllVars() const
{
	if (m_dictionaryVariables.empty())
	{
		return false;
	}
	for (auto elem : m_dictionaryVariables)
	{
		cout << elem.first << ":" << elem.second << endl;
	}
	return true;
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

bool CFunctions::AbilGetVal(std::string const &var, float &number)
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

float CFunctions::CalcValTwoVar(std::string const operation, float firstVal, float secondVal) const
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

float CFunctions::GetValFunc(std::string const &name)
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

bool CFunctions::PrintFunctions()
{
	if (m_dataFunctions.empty())
	{
		return false;
	}
	for (auto elem : m_dataFunctions)
	{
		std::cout << elem.first << ":" << GetValFunc(elem.first) << std::endl;
	}
	return true;
}