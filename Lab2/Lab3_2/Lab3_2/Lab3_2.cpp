// Lab3_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ProcessMap.h"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error! Usage dictionary.exe <dictionary.txt>.\n";
		return EXIT_FAILURE;
	}
	std::string nameDictionary = argv[1];
	ProcessMap(nameDictionary);
    return EXIT_SUCCESS;
}

