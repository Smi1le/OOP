#pragma once
#include <string>
#include "Config.h"
#include <memory>
#include <iostream>

enum TypeOperand
{
	addition,
	substraction,
	multiplication,
	division
};

struct DataFunction
{
	DataFunction() = default;
	DataFunction(std::string const &tFirstVal, std::string const &tSecondVal = "", TypeOperand tOperand = TypeOperand::addition)
		: firstVar(tFirstVal)
		, secondVar(tSecondVal)
		, operand(tOperand)
	{}

	std::string firstVar;
	std::string secondVar;
	TypeOperand operand;
	bool isTwoOperand = false;
};