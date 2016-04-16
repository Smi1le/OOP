// Calculator.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ICalculator.h"
#include <iostream>



int main()
{
	CCalculatorHelper calc;
	calc.SetCommand();
    return 0;
}

