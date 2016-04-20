#include "stdafx.h"
#include "Functions.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

CFunctions::CFunctions(std::shared_ptr<DataProgram> tData)
{
	m_data = tData;
}

bool CFunctions::AddVariable(std::string const & var, double val)
{
	if (!m_data->m_dataVariables.empty() && m_data->m_dataVariables.find(var) != m_data->m_dataVariables.end())
	{
		return false;
	}
	m_data->m_dataVariables.insert(std::pair<std::string, double>(var, (std::round(val * 100) / 100)));
	return true;
}

bool CFunctions::AssValToVar(std::string const & var1, double val)
{
	if (!m_data->m_dataVariables.empty() && m_data->m_dataVariables.find(var1) != m_data->m_dataVariables.end())
	{
		m_data->m_dataVariables.at(var1) = round(val * 100) / 100;
		return true;
	}
	return AddVariable(var1, val);
}

bool CFunctions::AssValToVar(std::string const & var1, std::string const & var2)
{
	
	auto element = m_data->m_dataVariables.find(var2);
	if (element == m_data->m_dataVariables.end())
	{
		return false;
	}
	if (m_data->m_dataVariables.find(var1) != m_data->m_dataVariables.end())
	{
		m_data->m_dataVariables.at(var1) = element->second;
		return true;
	}
	return AddVariable(var1, element->second);
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

bool CFunctions::AddFunction(Vector const &inst)
{
	std::string nameFunc = inst[1];
	if (!m_data->m_dataFunctions.empty() && m_data->m_dataFunctions.find(nameFunc) != m_data->m_dataFunctions.end())
	{
		return false;
	}
	DataFunction pData;
	std::string firstName = inst[NUMBER_POS_FIRST_NAME];
	pData.firstVar = firstName;
//#pragma message inst.size() > 5?
	if (inst.size() > 5)
	{
		std::string operation = inst[NUMBER_POS_OPER];
		std::string secondName = inst[NUMBER_POS_SEC_NAME];
		pData.operand = CheckOperand(operation);
		pData.secondVar = secondName;
		pData.isTwoOperand = true;
	}
	m_data->m_dataFunctions.insert({ nameFunc, pData });
	return true;
}