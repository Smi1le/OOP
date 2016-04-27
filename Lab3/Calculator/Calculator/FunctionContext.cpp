#include "stdafx.h"
#include "FunctionContext.h"





bool IFunctionContext::GetValueVariable(std::string const &var, double &number)
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

double IFunctionContext::CalcValTwoVar(TypeOperand operation, double firstVal, double secondVal) const
{
	if (operation == TypeOperand::multiplication)
	{
		return firstVal * secondVal;
	}
	if (operation == TypeOperand::substraction)
	{
		return firstVal - secondVal;
	}
	if (operation == TypeOperand::addition)
	{
		return firstVal + secondVal;
	}
	return firstVal / secondVal;
}

bool IsNumber()
{

}

double IFunctionContext::Calculate(std::string const &leftVar, std::string const &rightVar, TypeOperand const &op, bool twoOp)
{
	std::cout << "---------------------" << std::endl;
	if (twoOp)
	{
		double valFirstVar = 0;
		double valSecondVar = 0;
		if (!IsNumber(leftVar))
		{
			GetValueVariable(leftVar, valFirstVar);
		}
		else
		{
			valFirstVar = atof(leftVar.c_str());
		}
		if (!IsNumber(rightVar))
		{
			GetValueVariable(rightVar, valSecondVar);
		}
		else
		{
			valSecondVar = atof(rightVar.c_str());
		}
		return CalcValTwoVar(op, valFirstVar, valSecondVar);
	}
	double result = 0;
	if (GetValueVariable(leftVar, result))
	{
		return result;
	}
	return NAN;
}

bool IFunctionContext::IsNumber(std::string const &val) const
{
	for (auto elem : val) {
		if (!isdigit(elem) && elem != '.')
		{
			return false;
		}
	}
	return true;
}
