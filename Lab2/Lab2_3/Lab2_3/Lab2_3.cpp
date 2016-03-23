// Lab2_3.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "ProcessorString.h"
#include <Windows.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (argc != 3)
	{
		cout << "Error! Usage replace.exe<search-string><replace-string>/n";//TODO вводить искомую строку через ctdin,выводить в stdout
		return EXIT_FAILURE;
	}
	string subject;
	getline(cin, subject);
	string search = argv[1];
	string replace = argv[2];
	string resultingString = FindAndReplace(subject, search, replace);
	cout << resultingString	 << endl;
	return EXIT_SUCCESS;
}

