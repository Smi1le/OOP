#pragma once
#include "Config.h"
#include <map>
#include <vector>

using Vars = std::map<std::string, double>;
using dataFunctions = std::map<std::string, std::vector<std::string>>;
using dataOneFunction = std::pair<std::string, std::vector<std::string>>;
using Vector = std::vector<std::string>;

class CFunctions
{
public:
	bool AddVariable(std::string const & var, double val = NAN);
	bool AddFunction(Vector const &inst);
	bool AssValToVar(std::string const & var1, std::string const & var2);
	bool AssValToVar(std::string const & var1, double val);
	double GetValFunc(std::string const &name);
	double CalcValTwoVar(std::string const operation, double firstVal, double secondVal) const;
	bool IsNumber(std::string const &val);
	bool AbilGetVal(std::string const &var, double &number);
protected:
	Vars m_dictionaryVariables;
	dataFunctions m_dataFunctions;
};