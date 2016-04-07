#pragma once
#include "Config.h"
#include <map>
#include <vector>

using Vars = std::map<std::string, float>;
using dataFunctions = std::map<std::string, std::vector<std::string>>;
using dataOneFunction = std::pair<std::string, std::vector<std::string>>;
using Vector = std::vector<std::string>;

class CCalculator
{
public:
	void SetCommand();
	void CommandDefinition(Vector const & inst);
	bool AddVariable(std::string const & var, float val = NAN);
	bool AssValToVar(std::string const & var1, std::string const & var2);
	bool AssValToVar(std::string const & var1, float val);
	bool AddFunction(Vector const &inst);
	float GetValue(std::string const &var);
	float GetValFunc(std::string const &name);
	float CalcVal(std::string const operation, float firstVal, float secondVal);
private:
	bool IsNumber(std::string const &val);
	bool GetVal(std::string const &var, float &number);
	void PrintVar(std::string const &var);
	void PrintAllVars();
	void PrintFunctions();
	Vars m_dictionaryVariables;
	dataFunctions m_dataFunctions;
};