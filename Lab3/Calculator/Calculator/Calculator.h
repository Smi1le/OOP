#pragma once


#include "Function.h"
#include "FunctionContext.h"
#include "Config.h"
#include <iostream>


/*using dataVariables = std::map<std::string, double>;
using dataFunctions = std::map<std::string, CFunction>;
using Vector = std::vector<std::string>;*/

//using dataFunctions = std::map<std::string, CFunction>;

typedef std::map<std::string, CFunction> dataFunctions;

//TODO: имена подобраны не правильно

class CCalculator
{
public:
	CCalculator() = default;
	~CCalculator() = default;
	bool PrintVariables();
	bool PrintFunctions();
	bool Print(std::string const &name);
	bool AddVariable(std::string const & var, double val = NAN);
	bool AddFunction(Vector const &inst);
	bool AssignValToVar(std::string const & var1, std::string const & var2);
	bool AssignValToVar(std::string const & var1, double val);
	double GetValue(std::string const &var);
	bool IsNumber(std::string const &val) const;
private:
	dataVariables m_variables;
	dataFunctions m_functions;
};