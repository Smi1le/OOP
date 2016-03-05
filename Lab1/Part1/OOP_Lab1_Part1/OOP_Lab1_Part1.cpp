#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

string SearchAndReplaceSubstring(string &readLine, const string &findString, const string &replaceString, bool &isReplace) {
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
			isReplace = true;
			bufStr.append(readLine.substr(0, indexSubstringOccurrences));
			bufStr.append(replaceString);
			readLine.erase(0, indexSubstringOccurrences + findString.length());
		}
	}
	return bufStr;
}

bool ReplaceStringInFile(const string &inputFileName, const string &findString, const string &replaceString, const string &outputFileName, bool &isReplace) 
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
			if (readLine.length() >= bufStr.length())
			{
				bufStr = SearchAndReplaceSubstring(readLine, findString, replaceString, isReplace);
			}
			
			outputFile.write(bufStr.c_str(), bufStr.length());
			outputFile.write("\n", 1);
		}
		return true;
	}
	else
	{
		printf("Ошибка открытия входного файла.\n");
		return false;
	}
}

bool InputValidation(int argc)
{
	if (argc != 4)
	{
		printf("Неверное количество параметров. Используйте программу так: replace.exe <input file><output file><search string><replace string>");
		return false;
	}
	else
	{
		return true;
	}
}

int main(int argc, char *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool isReplace = false;
	if (InputValidation(argc))
	{
		string inputFileName = argv[1];
		string outputFileName = argv[2];
		string findString = argv[3];
		string replaceString = argv[4];
		if (!ReplaceStringInFile(inputFileName, findString, replaceString, outputFileName, isReplace))
		{
			return 2;
		}
	}
	if (isReplace)
	{
		cout << "Выполнение завершено. Программа выполнена успешно." << endl;
		return 0;
	}
	else
	{
		cout << "Программа не выполнена." << endl;;
		return 1;
	}
}	

