#pragma once
#include "Node.h"
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
	bool CallCommand(std::string const & inst);
private:
	std::shared_ptr<CNode> m_node;
};
