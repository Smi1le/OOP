#pragma once
#include <string>
#include "Config.h"
#include <iostream>
#include <map>

class IFunctionContext;

class CFunction
{
public:
	CFunction(std::string const &firstVal)
		: m_firstVar(firstVal)
	{}
	CFunction(std::string const &firstVal, std::string const &secondVal, TypeOperand operand)
		: m_firstVar(firstVal)
		, m_secondVar(secondVal)
		, m_operation(operand)
	{
		m_isTwoOperand = true;
	}
	double Calculate(IFunctionContext *ctx);
	bool IsTwoOperand() const;
	std::string GetElement(int number)const;
private:
	double CalcValTwoVar(TypeOperand operation, double firstVal, double secondVal) const;
	std::string m_firstVar;
	std::string m_secondVar;
	TypeOperand m_operation;
	bool m_isTwoOperand = false;
};