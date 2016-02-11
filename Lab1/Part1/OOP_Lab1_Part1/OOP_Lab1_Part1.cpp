#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

void LineCreation(string &text,const string addedLine) 
{
	text += addedLine;
}

string SearchSubstring(string &currentLine, const string findString, const string replaceString) {
	string bufStr;
	for (int k = 0; k < currentLine.length() - findString.length(); k++)
	{
		string substring = currentLine.substr(k, findString.length());
		if (substring == findString) 
		{
			LineCreation(bufStr, replaceString);
		}
		else
		{
			LineCreation(bufStr, currentLine.substr(k, 1));
		}
	}
	return bufStr;
}

bool ProgramExecution(const string inputFileName,const string findString,const string replaceString,const string outputFileName) 
{
	ifstream inputFile(inputFileName);
	ofstream outputFile(outputFileName);
	if (inputFile)
	{
		while (!inputFile.eof()) 
		{
			string currentLine;
			string bufStr;
			getline(inputFile, currentLine);
			bufStr = string(findString);
			if (currentLine.length() >= bufStr.length())
			{
				bufStr = SearchSubstring(currentLine, findString, replaceString);
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
	string inputFileName = argv[1];
	string outputFileName = argv[2];
	string findString = argv[3];
	string replaceString = argv[4];
	if (ifCanWork) 
	{
		bool ifCarriedOut = ProgramExecution(inputFileName, findString, replaceString, outputFileName);
		CompletionChecks(ifCarriedOut);
	}
	return 0;
}	

