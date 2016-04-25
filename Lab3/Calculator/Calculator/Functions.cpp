#include "stdafx.h"
#include "Functions.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

CFunctions::CFunctions()
{
}

bool CFunctions::AddVariable(std::string const & var, DataProgram &data, float val)
{
	if (!data.m_dataVariables.empty() && data.m_dataVariables.find(var) != data.m_dataVariables.end())
	{
		return false;
	}
	data.m_dataVariables.insert(std::pair<std::string, float>(var, (std::round(val * 100) / 100)));
	return true;
}

bool CFunctions::AssValToVar(std::string const & var1, float val, DataProgram &data)
{
	if (!data.m_dataVariables.empty() && data.m_dataVariables.find(var1) != data.m_dataVariables.end())
	{
		data.m_dataVariables.at(var1) = round(val * 100) / 100;
		return true;
	}
	return AddVariable(var1, data, val);
}

bool CFunctions::AssValToVar(std::string const & var1, std::string const & var2, DataProgram &data)
{
	
	auto element = data.m_dataVariables.find(var2);
	if (element == data.m_dataVariables.end())
	{
		return false;
	}
	if (data.m_dataVariables.find(var1) != data.m_dataVariables.end())
	{
		data.m_dataVariables.at(var1) = element->second;
		return true;
	}
	return AddVariable(var1, data, element->second);
}

TypeOperand CheckOperand(std::string const &op)
{
	if (op == "+")
	{
		return TypeOperand::addition;
	}
	else if (op == "/")
	{
		return TypeOperand::division;
	}
	else if (op == "*")
	{
		return TypeOperand::multiplication;
	}
	return TypeOperand::substraction;
}

bool CFunctions::AddFunction(Vector const &inst, DataProgram &data)
{
	std::string nameFunc = inst[1];
	if (!data.m_dataFunctions.empty() && data.m_dataFunctions.find(nameFunc) != data.m_dataFunctions.end())
	{
		return false;
	}
	DataFunction pData;
	std::string firstName = inst[NUMBER_POS_FIRST_NAME];
	pData.firstVar = firstName;
	if (inst.size() > 5)
	{
		std::string operation = inst[NUMBER_POS_OPER];
		std::string secondName = inst[NUMBER_POS_SEC_NAME];
		pData.operand = CheckOperand(operation);
		pData.secondVar = secondName;
		pData.isTwoOperand = true;
	}
	data.m_dataFunctions.insert({ nameFunc, pData });
	return true;
}