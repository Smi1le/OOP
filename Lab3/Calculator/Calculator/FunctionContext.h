#pragma once
#include "Function.h"

class IFunctionContext
{
public:
	virtual ~IFunctionContext() = default;
	virtual double Calculate(std::string const &leftVar, std::string const &rightVar, TypeOperand const &op, bool twoOp) = 0;
};
