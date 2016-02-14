#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

string SearchAndReplaceSubstring(string &readLine, const string &findString, const string &replaceString) {
	string bufStr;
	int indexSubstringOccurrences = 0;
	while (indexSubstringOccurrences != -1)
	{
		indexSubstringOccurrences = readLine.find(findString);
		if (indexSubstringOccurrences == -1) 
		{
			bufStr.append(readLine);
		}
		else
		{
			bufStr.append(readLine.substr(0, indexSubstringOccurrences));
			bufStr.append(replaceString);
			readLine.erase(0, indexSubstringOccurrences + findString.length());
		}
	}
	return bufStr;
}

bool ReplaceStringInFile(const string &inputFileName, const string &findString, const string &replaceString, const string &outputFileName) 
{
	ifstream inputFile(inputFileName);
	ofstream outputFile(outputFileName);
	if (inputFile)
	{
		while (!inputFile.eof()) 
		{
			string readLine;
			string bufStr;
			getline(inputFile, readLine);
			bufStr = string(findString);
			if (readLine.length() >= bufStr.length())
			{
				bufStr = SearchAndReplaceSubstring(readLine, findString, replaceString);
			}
			
			outputFile.write(bufStr.c_str(), bufStr.length());
			outputFile.write("\n", 1);
		}
	}
	else
	{
		printf("Ошибка открытия входного файла.\n");
		_getch();
		return false;
	}
}

bool InputValidation(int argc)
{
	if (argc <= 4)
	{
		printf("Ошибка! Не хватает аргументов для работы программы.\n");
		_getch();
		return false;
	}

	else if (argc > 5)
	{
		printf("Ошибка! Слишком много аргументов для работы программы.\n");
		_getch();
		return false;
	}
	else if (argc == 5)
	{
		return true;
	}
}

void CompletionChecks(bool ifCarriedOut)
{
	if (ifCarriedOut)
	{
		cout << "Выполнение завершено. Программа выполнена успешно." << endl;
	}
	else
	{
		cout << "Программа не выполнена." << endl;;
	}
	_getch();
}

int main(int argc, char *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool ifCanWork = InputValidation(argc);
	if (ifCanWork) 
	{
		string inputFileName = argv[1];
		string outputFileName = argv[2];
		string findString = argv[3];
		string replaceString = argv[4];
		bool ifCarriedOut = ReplaceStringInFile(inputFileName, findString, replaceString, outputFileName);
		CompletionChecks(ifCarriedOut);
	}
	return 0;
}	

