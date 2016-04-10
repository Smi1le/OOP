#pragma once
#include "Config.h"
#include <map>
#include <vector>

using Vars = std::map<std::string, float>;
using dataFunctions = std::map<std::string, std::vector<std::string>>;
using dataOneFunction = std::pair<std::string, std::vector<std::string>>;
using Vector = std::vector<std::string>;

class CFunctions
{
public:
	float GetValue(std::string const &var);
protected:
	bool AddVariable(std::string const & var, float val = NAN);
	bool AddFunction(Vector const &inst);
	bool AssValToVar(std::string const & var1, std::string const & var2);
	bool AssValToVar(std::string const & var1, float val);
	float GetValFunc(std::string const &name);
	float CalcValTwoVar(std::string const operation, float firstVal, float secondVal);
	bool IsNumber(std::string const &val);
	bool AbilGetVal(std::string const &var, float &number);
	bool Print(std::string const &var);
	bool PrintAllVars();
	bool PrintFunctions();
private:
	bool CheckOperation(std::string const &op);
	Vars m_dictionaryVariables;
	dataFunctions m_dataFunctions;
};