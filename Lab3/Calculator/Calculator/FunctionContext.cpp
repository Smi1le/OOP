#include "stdafx.h"
#include "FunctionContext.h"







/*double IFunctionContext::Calculate(std::string const &leftVar, std::string const &rightVar, TypeOperand const &op, bool twoOp)
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
}*/
