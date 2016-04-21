#include "stdafx.h"
#include "CalculateData.h"

CCalculateData::CCalculateData(std::shared_ptr<DataProgram> tData)
{
	m_data = tData;
}

// TODO:change signature to `double(std::string const &)`
bool CCalculateData::AbilGetVal(std::string const &var, double &number)
{

	if (!m_data->m_dataVariables.empty())
	{
		auto element = m_data->m_dataVariables.find(var);
		if (element != m_data->m_dataVariables.end())
		{
			number += (*element).second;
			return true;
		}
	}
	if (!m_data->m_dataFunctions.empty())
	{
		auto element = m_data->m_dataFunctions.find(var);
		if (element != m_data->m_dataFunctions.end())
		{
			auto number1 = (*element).second;
			AbilGetVal(number1.firstVar, number);
			if (number1.isTwoOperand)
			{
				AbilGetVal(number1.secondVar, number);
			}
			return true;
		}
	}
	return false;
}

boost::optional<double> CCalculateData::GetValFunction(std::string const &name)
{
	auto pair = *m_data->m_dataFunctions.find(name);
	auto data = pair.second;
	double result = 0;
	if (data.isTwoOperand)
	{
		double valFirstVar = 0;
		double valSecondVar = 0;
		AbilGetVal(data.firstVar, valFirstVar);
		AbilGetVal(data.secondVar, valSecondVar);
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
	if (AbilGetVal(data.firstVar, result))
	{
		return result;
	}
	return NAN;
}

double CCalculateData::CalcValTwoVar(TypeOperand operation, double firstVal, double secondVal) const
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