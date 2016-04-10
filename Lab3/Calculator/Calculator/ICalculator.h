#pragma once
#include "Functions.h"

class CICalculator : public CFunctions
{
public:
	void SetCommand();
private:
	void Help();
	bool ParsingInputCommands(std::string const & inst);
};