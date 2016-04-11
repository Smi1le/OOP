#pragma once
#include "Functions.h"

class CICalculator : public CFunctions
{
public:
	void SetCommand();
private:
	double GetValue(std::string const &var);
	void Help();
	bool CorrectInput(Vector const &instructions);
	bool Print(std::string const &var);
	bool PrintAllVars() const;
	bool IsOperation(std::string const &op) const;
	bool PrintFunctions();
	bool ParsingInputCommands(std::string const & inst);
};