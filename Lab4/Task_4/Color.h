#pragma once

#include <string>
#include <iostream>
#include <boost/utility/string_ref.hpp>



static int StringToInt(const char &stringForTranslation, const int &radix, bool &wasError)
{
	int numberTranslaredSymbol = static_cast<int>(SYMBOLS.find(toupper(stringForTranslation)));
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

static int IntoDecimalSystem(const boost::string_ref &numberForTranslation, const int &sourceNotation, bool &wasError)
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
				std::cout << "Error!";
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


struct Color
{
	int red;
	int green;
	int blue;
};

//Colors STANDART_COLORS = { 0, 0, 0 };