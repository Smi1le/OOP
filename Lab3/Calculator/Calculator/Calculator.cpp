// Calculator.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Functions.h"
#include <iostream>

void Help()
{
	std::cout << "Use the following input formats:" << std::endl;
	std::cout << "var <id> - to initialize a variable." << std::endl;
	std::cout << "let <id> = <number> - for the transmission of variable values." << std::endl;
	std::cout << "let <id1> = <id2> - for the transmission of variable values." << std::endl;
	std::cout << "fn <id1> = <id2> - initialization function." << std::endl;
	std::cout << "fn <id1> = <id2> <operation> <id3> - initialization function." << std::endl;
	std::cout << "print <id> - to output a predetermined identifier." << std::endl;
	std::cout << "printvars - for output all variables." << std::endl;
	std::cout << "printfns - for output all functions." << std::endl;

}

int main()
{
	CCalculator calc;
	Help();
	calc.SetCommand();
    return 0;
}

