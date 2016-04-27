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
			IFunctionContext ctx(m_functions, m_variables);
			cout << outElem1->first << ":" << outElem1->second.Calculate(&ctx) << endl;
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
		IFunctionContext ctx(m_functions, m_variables);
		cout << elem.first << ":" << elem.second.Calculate(&ctx) << endl;
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
	CFunction pData;
	string firstName = inst[NUMBER_POS_FIRST_NAME];
	pData.SetElement(firstName, 1);
	if (inst.size() > 5)
	{
		string operation = inst[NUMBER_POS_OPER];
		string secondName = inst[NUMBER_POS_SEC_NAME];
		pData.SetOperand(CheckOperand(operation));
		pData.SetElement(secondName, 2);
	}
	m_functions.insert({ nameFunc, pData });
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
		IFunctionContext ctx(m_functions, m_variables);
		return (*element1).second.Calculate(&ctx);
	}
}

bool CCalculator::IsNumber(string const &val) const
{
	for (auto elem : val) {
		if (!isdigit(elem) && elem != '.')
		{
			return false;
		}
	}
	return true;
}