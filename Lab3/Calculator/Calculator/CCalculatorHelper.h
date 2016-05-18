#pragma once
#include "Calculator.h"
#include "Function.h"

class CCalculatorHelper
{
public:
	CCalculatorHelper() = default;
	~CCalculatorHelper() = default;
	void SetCommand();
	void Help() const;
	bool CorrectInput(Vector const &instructions) const;
	bool IsOperation(std::string const &op) const;
	bool CallCommand(std::string const & inst);
private:
	void AssignValueToVariable(vector<string> const & instructions);
	CCalculator m_calculator;
};
