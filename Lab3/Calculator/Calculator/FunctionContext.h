#pragma once
#include "Function.h"

using dataFunctions = std::map<std::string, CFunction>;
using dataVariables = std::map<std::string, double>;

class IFunctionContext
{
public:
	IFunctionContext(dataFunctions const &functions, dataVariables const &variables)
		: m_functions(functions)
		, m_variables(variables)
	{}
	~IFunctionContext() = default;
	double Calculate(std::string const &leftVar, std::string const &rightVar, TypeOperand const &op, bool twoOp);
private:
	bool IsNumber(std::string const &val) const;
	bool GetValueVariable(std::string const &var, double &number);
	double CalcValTwoVar(TypeOperand operation, double firstVal, double secondVal) const;
	dataFunctions m_functions;
	dataVariables m_variables;
};
