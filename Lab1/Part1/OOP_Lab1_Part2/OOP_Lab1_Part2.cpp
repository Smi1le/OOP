#include "stdafx.h"
#include <stdio.h> 
#include <conio.h>
#include <string> 
#include <fstream>
#include <iostream>
#include <vector>

const std::string SYMBOLS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int StringToInt(const char &stringForTranslation, const int &radix, bool &wasError)
{
	int numberTranslaredSymbol = SYMBOLS.find(stringForTranslation);
	if (numberTranslaredSymbol <= radix - 1)
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
	for (size_t i = 0; i < numberForTranslation.length(); i++)
	{
		int number = StringToInt(numberForTranslation[i], sourceNotation, wasError);
		if (wasError)
		{
			i = numberForTranslation.length();
			std::cout << "Ошибка! Было неверно указана одно из значение систем!\n";
		}
		translatedToIntNumber += number * pow(sourceNotation, (numberForTranslation.length() - i - 1));
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
	std::cout << "Получившееся значение "<< originalValue <<" в " << radix << " системе счисления: ";
	std::cout << resultingValue << std::endl;
}

void TransferFromOneSystemToAnother(const std::string &numberForTranslation, const int &sourceNotation, const int &destinationNotation, bool &wasError)
{
	std::string resultingValue;
	int numberInDecimalSystem = IntoDecimalSystem(numberForTranslation, sourceNotation, wasError);
	if (!wasError)
	{
		resultingValue = FromDecimalToAny(numberInDecimalSystem, destinationNotation, wasError);
	}
	if (!wasError)
	{
		OutputTheGetValue(resultingValue, destinationNotation, numberForTranslation);
	}
}

bool InputValidation(int argc)
{
	if (argc <= 3)
	{
		printf("Ошибка! Не хватает аргументов для работы программы.\n");
		_getch();
		return false;
	}

	else if (argc > 4)
	{
		printf("Ошибка! Слишком много аргументов для работы программы.\n");
		_getch();
		return false;
	}
	else if (argc == 4)
	{
		return true;
	}
}

void CompletionChecks(bool ifCanWork, bool wasError)
{
	if (ifCanWork && !wasError)
	{
		std::cout << "Выполнение завершено. Программа выполнена успешно." << std::endl;
	}
	else
	{
		std::cout << "Программа не выполнена." << std::endl;;
	}
	_getch();
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");
	bool wasError = false;
	bool ifCanWork = InputValidation(argc);
	if (ifCanWork)
	{
		std::string numberForTranslate = argv[1];
		int initialNumberSystem = atoi(argv[2]);
		int destinationNumberSystem = atoi(argv[3]);
		TransferFromOneSystemToAnother(numberForTranslate, initialNumberSystem, destinationNumberSystem, wasError);
	}
	CompletionChecks(ifCanWork, wasError);
	_getch();
	return 0;
}