#pragma once
#include <string>
#include "DataProgram.h"
#include "CalculateData.h"

class COutputData
{
public:
	COutputData(std::shared_ptr<DataProgram> tData);
	bool PrintVariables();
	bool PrintFunctions();
	bool Print(std::string const &name);
private:
	std::shared_ptr<DataProgram> m_data;
	std::shared_ptr<CCalculateData> m_calcData;
};