#pragma once
#include "DataProgram.h"
#include <map>
#include <vector>
#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>

class CFunctions
{
public:
	CFunctions(std::shared_ptr<DataProgram> tData);
	bool AddVariable(std::string const & var, double val = NAN);
	bool AddFunction(Vector const &inst);
	bool AssValToVar(std::string const & var1, std::string const & var2);
	bool AssValToVar(std::string const & var1, double val);
private:
	std::shared_ptr<DataProgram> m_data;
};