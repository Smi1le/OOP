#pragma once


#include "Function.h"
#include "FunctionContext.h"
#include "Config.h"
#include <iostream>

typedef std::map<std::string, CFunction> dataFunctions;

//TODO: имена подобраны не правильно

class CCalculator : public IFunctionContext
{
public:
	CCalculator() = default;
	bool PrintVariables();
	bool PrintFunctions();
	bool Print(std::string const &name);
	bool AddVariable(std::string const & var, double val = NAN);
	bool AddFunction(Vector const &inst);
	bool AssignValToVar(std::string const & var1, std::string const & var2);
	bool AssignValToVar(std::string const & var1, double val);
	double GetValue(std::string const &var);
	bool IsNumber(std::string const &val) const;
	double Calculate(std::string const &leftVar, std::string const &rightVar, TypeOperand const &op, bool twoOp) override;
	bool GetValueVariable(std::string const &var, double &number);
	double CalcValTwoVar(TypeOperand operation, double firstVal, double secondVal) const;
private:
	
	dataVariables m_variables;
	dataFunctions m_functions;
};