#include "stdafx.h"
#include "Function.h"
#include "FunctionContext.h"

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
	if (m_isTwoOperand)
	{
		return CalcValTwoVar(m_operation, ctx->Calculate(m_firstVar), ctx->Calculate(m_secondVar));
	}
	return ctx->Calculate(m_firstVar);
}



double CFunction::CalcValTwoVar(TypeOperand operation, double firstVal, double secondVal) const
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