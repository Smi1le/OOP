#pragma once
#include <string>
#include "DataProgram.h"
#include "CalculateData.h"

class COutputData
{
public:
	COutputData();
	bool PrintVariables(DataProgram const &data);
	bool PrintFunctions(DataProgram const &data);
	bool Print(std::string const &name, DataProgram const &data);
private:
	std::shared_ptr<CCalculateData> m_calcData;
};