#include "stdafx.h"
#include "Function.h"
#include "FunctionContext.h"



void CFunction::SetElement(std::string const &value, int numberItem)
{
	if (numberItem == 1)
	{
		m_firstVar = value;
	}
	if (numberItem == 2)
	{
		m_isTwoOperand = true;
		m_secondVar = value;
	}
}

bool CFunction::IsTwoOperand() const
{
	return m_isTwoOperand;
}

std::string CFunction::GetElement(int number) const
{
	if (number == 1)
	{
		return m_firstVar;
	}
	return m_secondVar;
}

double CFunction::Calculate(IFunctionContext *ctx)
{
	return ctx->Calculate(m_firstVar, m_secondVar, m_operand, m_isTwoOperand);
}

void CFunction::SetOperand(TypeOperand const &op)
{
	m_operand = op;
	m_isTwoOperand = true;
}

