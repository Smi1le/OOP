// Calculator.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ICalculator.h"
#include <iostream>



int main()
{
	CICalculator calc;
	calc.SetCommand();
    return 0;
}

