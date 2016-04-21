#pragma once
#include "Expression.h"
#include <string>
#include <map>
#include <vector>


using dataVariables = std::map<std::string, double>;
using dataFunctions = std::map<std::string, DataFunction>;
using Vector = std::vector<std::string>;

struct DataProgram
{
	dataVariables m_dataVariables;
	dataFunctions m_dataFunctions;
};