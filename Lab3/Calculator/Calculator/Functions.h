#pragma once
#include "DataProgram.h"
#include <map>
#include <vector>
#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>

class CFunctions
{
public:
	CFunctions();
	bool AddVariable(std::string const & var, DataProgram &data, float val = NAN);
	bool AddFunction(Vector const &inst, DataProgram &data);
	bool AssValToVar(std::string const & var1, std::string const & var2, DataProgram &data);
	bool AssValToVar(std::string const & var1, float val, DataProgram &data);
};