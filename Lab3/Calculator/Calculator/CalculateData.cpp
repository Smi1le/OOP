#include "stdafx.h"
#include "CalculateData.h"

CCalculateData::CCalculateData()
{
}

// TODO:change signature to `double(std::string const &)`
bool CCalculateData::Calculate(std::string const &var, float &number, DataProgram const &pData)
{

	if (!pData.m_dataVariables.empty())
	{
		auto element = pData.m_dataVariables.find(var);
		if (element != pData.m_dataVariables.end())
		{
			number += (*element).second;
			return true;
		}
	}
	if (!pData.m_dataFunctions.empty())
	{
		auto element = pData.m_dataFunctions.find(var);
		if (element != pData.m_dataFunctions.end())
		{
			auto number1 = (*element).second;
			Calculate(number1.firstVar, number, pData);
			if (number1.isTwoOperand)
			{
				Calculate(number1.secondVar, number, pData);
			}
			return true;
		}
	}
	return false;
}

boost::optional<float> CCalculateData::GetValFunction(std::string const &name, DataProgram const &pData)
{
	auto pair = *pData.m_dataFunctions.find(name);
	auto data = pair.second;
	float result = 0;
	if (data.isTwoOperand)
	{
		float valFirstVar = 0;
		float valSecondVar = 0;
		Calculate(data.firstVar, valFirstVar, pData);
		Calculate(data.secondVar, valSecondVar, pData);
		// TODO: make IsNaN function which checks
		// bool IsNaN(double value) { return value != value; }
		if (valFirstVar != valFirstVar)
		{
			valFirstVar = 0.f;
		}
		if (valSecondVar != valSecondVar)
		{
			valSecondVar = 0.f;
		}
		return CalcValTwoVar(data.operand, valFirstVar, valSecondVar);
	}
	if (Calculate(data.firstVar, result, pData))
	{
		return result;
	}
	return NAN;
}

float CCalculateData::CalcValTwoVar(TypeOperand operation, float firstVal, float secondVal) const
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