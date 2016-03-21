// Lab4_4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ProcessSet.h"
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Error! Usage GeneratePrimeNumbersSet.exe <upperBound>.\n";
		return EXIT_FAILURE;
	}
	int upperBound = atoi(argv[1]);
	OutputInConsole(GeneratePrimeNumbersSet(upperBound));
	return EXIT_SUCCESS;
}
