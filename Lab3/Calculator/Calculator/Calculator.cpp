#include "stdafx.h"
#include "Calculator.h"
#include "Function.h"
#include <map>

using namespace std;

typedef std::map<std::string, double> dataVariables;
using Vector = std::vector<std::string>;

TypeOperand CheckOperand(string const &op)
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

bool CCalculator::Print(string const &name)
{
	auto outElem = m_variables.find(name);
	if (outElem != m_variables.end())
	{
		cout << outElem->second << endl;
		return true;
	}
	else
	{
		auto outElem1 = this->m_functions.find(name);
		if (outElem1 != m_functions.end())
		{
			cout << outElem1->first << ":" << outElem1->second.Calculate(this) << endl;
			return true;
		}
	}
	return false;
}

bool CCalculator::PrintFunctions()
{
	if (m_functions.empty())
	{
		return false;
	}
	for (auto elem : m_functions)
	{
		cout << elem.first << ":" << elem.second.Calculate(this) << endl;
	}
	return true;
}

bool CCalculator::PrintVariables()
{
	if (m_variables.empty())
	{
		return false;
	}
	for (auto elem : m_variables)
	{
		cout << elem.first << ":" << elem.second << endl;
	}
	return true;
}

bool CCalculator::AddFunction(Vector const &inst)
{
	string nameFunc = inst[1];
	if (!this->m_functions.empty() && m_functions.find(nameFunc) != m_functions.end())
	{
		return false;
	}
	string firstName = inst[NUMBER_POS_FIRST_NAME];
	CFunction data = CFunction(firstName);
	if (inst.size() > 5)
	{
		string operation = inst[NUMBER_POS_OPER];
		string secondName = inst[NUMBER_POS_SEC_NAME];
		data = CFunction(firstName, secondName, CheckOperand(operation));
		
	}
	m_functions.insert({ nameFunc, data });
	return true;
	
}

bool CCalculator::AddVariable(string const & var, double val)
{
	if (!m_variables.empty() && m_variables.find(var) != m_variables.end())
	{
		return false;
	}
	m_variables.insert(pair<string, double>(var, val));
	return true;
}

bool CCalculator::AssignValToVar(string const & var1, string const & var2)
{
	auto element = m_variables.find(var2);
	if (element == m_variables.end())
	{
		return false;
	}
	if (m_variables.find(var1) != m_variables.end())
	{
		m_variables.at(var1) = element->second;
		return true;
	}
	return AddVariable(var1, element->second);
}

bool CCalculator::AssignValToVar(string const & var1, double val)
{
	if (!m_variables.empty() && m_variables.find(var1) != m_variables.end())
	{
		m_variables.at(var1) = val;
		return true;
	}
	return AddVariable(var1, val);
}

double CCalculator::GetValue(string const &var)
{

	auto element = m_variables.find(var);
	if (element != m_variables.end())
	{
		return (*element).second;
	}
	auto element1 = m_functions.find(var);
	if (element1 != m_functions.end())
	{
		return (*element1).second.Calculate(this);
	}
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

bool CCalculator::GetValueVariable(std::string const &var, double &number)
{
	if (!m_variables.empty())
	{
		auto element = m_variables.find(var);
		if (element != m_variables.end())
		{
			number += (*element).second;
			return true;
		}
	}
	if (!m_functions.empty())
	{
		auto element = m_functions.find(var);
		if (element != m_functions.end())
		{
			auto number1 = (*element).second;
			GetValueVariable(number1.GetElement(1), number);
			if (number1.IsTwoOperand())
			{
				GetValueVariable(number1.GetElement(2), number);
			}
			return true;
		}
	}
	return false;
}

double CCalculator::Calculate(std::string const &variable)
{
	if (!IsNumber(variable))
	{
		double valFirstVal = 0;
		GetValueVariable(variable, valFirstVal);
		return valFirstVal;
	}
	else
	{
		return atof(variable.c_str());
	}
	return NAN;
}
