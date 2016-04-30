#pragma once
#include <string>
#include "Config.h"
#include <iostream>
#include <map>

class IFunctionContext;

class CFunction
{
public:
	CFunction() = default;
	CFunction(std::string const &tFirstVal, std::string const &tSecondVal = "", TypeOperand tOperand = TypeOperand::addition)
		: m_firstVar(tFirstVal)
		, m_secondVar(tSecondVal)
		, m_operand(tOperand)
	{}
	~CFunction() = default;
	double Calculate(IFunctionContext *ctx);
	void SetElement(std::string const &value, int numberItem);
	void SetOperand(TypeOperand const &op);
	bool IsTwoOperand() const;
	std::string GetElement(int number)const;
	std::string m_firstVar;
	std::string m_secondVar;
private:
	
	
	TypeOperand m_operand;
	bool m_isTwoOperand = false;
};