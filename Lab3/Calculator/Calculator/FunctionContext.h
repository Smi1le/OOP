#pragma once
#include "Function.h"

class IFunctionContext
{
public:
	virtual ~IFunctionContext() = default;
	virtual double Calculate(std::string const &variable) = 0;
};
