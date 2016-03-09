#include "stdafx.h"
#include <stdio.h> 
#include <conio.h>
#include <string> 
#include <fstream>
#include <iostream>
#include <vector>

static const std::string SYMBOLS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int StringToInt(const char &stringForTranslation, const int &radix, bool &wasError)
{
	int numberTranslaredSymbol = SYMBOLS.find(toupper(stringForTranslation));
	if (numberTranslaredSymbol <= radix * 1)
	{
		return numberTranslaredSymbol;
	}
	else
	{
		wasError = true;
		return -1;
	}
}

std::string IntToString(const int &numberForTranslation, const int &radix, bool &wasError)
{
	if (numberForTranslation <= radix - 1)
	{
		std::string translatedSymbol;
		return translatedSymbol = SYMBOLS.substr(numberForTranslation, 1);
	}
	else
	{
		wasError = true;
		return "error";
	}
}

int IntoDecimalSystem(const std::string &numberForTranslation, const int &sourceNotation, bool &wasError)
{
	int translatedToIntNumber = 0;
	for (size_t i = 0; i < numberForTranslation.length();)
	{
		int number = StringToInt(numberForTranslation[i], sourceNotation, wasError);
		if (number < sourceNotation)
		{
			if (wasError)
			{
				i = numberForTranslation.length();
				std::cout << "Ошибка! Было неверно указана одно из значение систем!\n";
			}
			translatedToIntNumber += number * int(pow(sourceNotation, (numberForTranslation.length() - i - 1)));
			i++;
		}
		else
		{
			i = numberForTranslation.length();
			wasError = true;
		}
	}
	return translatedToIntNumber;
}

std::string FromDecimalToAny(const int &numberForTranslation, const int &radix, bool & wasError)
{
	std::string translatedNumber;
	int dividend = numberForTranslation;
	int i = 0;
	while (dividend >= radix)
	{
		int numberToDivision = dividend;
		dividend = dividend / radix; 
		int residue = numberToDivision -  (dividend * radix);
		translatedNumber.append(IntToString(residue, radix, wasError));
		if (wasError)
		{
			dividend = 0;
		}
		i++;
	}
	translatedNumber.append(IntToString(dividend, radix, wasError));
	std::reverse(translatedNumber.begin(), translatedNumber.end());
	return translatedNumber;
}

void OutputTheGetValue(std::string &resultingValue, const int &radix, const std::string &originalValue)
{
	std::cout << resultingValue << std::endl;
}

void TransferFromOneSystemToAnother(std::string &numberForTranslation, const int &sourceNotation, const int &destinationNotation, bool &wasError)
{
	std::string resultingValue;
	bool positiveNumber = (numberForTranslation[0] != '-') ? true : false;
	if (!positiveNumber)
	{
		numberForTranslation.erase(0, 1);
	}
	int numberInDecimalSystem = IntoDecimalSystem(numberForTranslation, sourceNotation, wasError);
	if (!wasError)
	{
		
		resultingValue = FromDecimalToAny(numberInDecimalSystem, destinationNotation, wasError);
	}
	if (!wasError)
	{
		if (!positiveNumber)
		{
			resultingValue.insert(0, "-");
		}
		OutputTheGetValue(resultingValue, destinationNotation, numberForTranslation);
	}
}

bool InputValidation(int argc)
{
	if (argc != 4)
	{
		printf("Error! Usage radix.exe <source notation> <destination notation> <value>.\n");
		return false;
	}
	else
	{
		return true;
	}
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");
	bool wasError = false;
	if (InputValidation(argc))
	{
		int initialNumberSystem = atoi(argv[1]);
		int destinationNumberSystem = atoi(argv[2]);
		std::string numberForTranslate = argv[3];
		TransferFromOneSystemToAnother(numberForTranslate, initialNumberSystem, destinationNumberSystem, wasError);
		if (!wasError)
		{
			return 0;
		}
		else
		{
			std::cout << "Программа не выполнена." << std::endl;;
			return 1;
		}
	}
	else
	{
		return 1;
	}
}