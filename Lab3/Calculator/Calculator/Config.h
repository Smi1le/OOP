#pragma once
#include <string>
#include <vector>
#include <map>

static const std::string ADD_VAR = "var";
static const std::string ASSIGN_VALUES_TO_VAR = "let";
static const std::string ADD_FUNCTION = "fn";
static const std::string PRINT = "print";
static const std::string PRINT_VARS = "printvars";
static const std::string PRINT_FNS = "printfns";
static const std::string EXIT = "EXIT";
static const std::string HELP = "Help";

static const int NUMBER_POS_FIRST_NAME = 3;
static const int NUMBER_POS_OPER = 4;
static const int NUMBER_POS_SEC_NAME = 5;

typedef std::map<std::string, double> dataVariables;
using Vector = std::vector<std::string>;

enum TypeOperand
{
	addition,
	substraction,
	multiplication,
	division
};