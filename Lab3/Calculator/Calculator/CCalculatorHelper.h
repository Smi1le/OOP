#pragma once
#include "Functions.h"
#include "OutputData.h"
#include "CalculateData.h"
#include <memory>

class CCalculatorHelper
{
public:
	CCalculatorHelper();
	void SetCommand();
	double GetValue(std::string const &var);
	void Help() const;
	bool CorrectInput(Vector const &instructions) const;
	bool IsNumber(std::string const &val) const;
	bool IsOperation(std::string const &op) const;
	bool ParsingInputCommands(std::string const & inst);
private:
	std::shared_ptr<CFunctions> m_functions;
	std::shared_ptr<COutputData> m_outputData;
	std::shared_ptr<DataProgram> m_data;
};
