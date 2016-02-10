#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include <conio.h>

using namespace std;

const int BUFFER = 256;

void insert(char replaceString[BUFFER], vector<int> labelPosition, string &mainString) 
{
	int k = 0;
	int size = labelPosition.size();
	while (k < size) 
	{
		int index = labelPosition.back();
		mainString.insert(index, replaceString);
		vector<int>::iterator iter = labelPosition.end() - 1;
		iter = labelPosition.erase(iter);
		k++;
	}
}
void workingWithFiles(string nameInputFile, char findString[BUFFER], char replaceString[BUFFER], string nameOutputFile) 
{
	ifstream inputFile(nameInputFile);
	ofstream outputFile(nameOutputFile);
	if (inputFile)
	{
		while (!inputFile.eof()) 
		{
			char currentLine[BUFFER];
			vector<int> labelPosition;
			inputFile.getline(currentLine, BUFFER);
			cout << currentLine << endl;
			string sss = string(currentLine);
			string bufStr = string(findString);
			if (sss.length() >= bufStr.length()) 
			{
				int k = 0;
				while (k != -1)
				{
					k = sss.find(findString);
					if (k != -1) 
					{
						labelPosition.push_back(k);
						sss.erase(k, bufStr.length());
					}
				}
				if (labelPosition.size() > 0) 
				{
					insert(replaceString, labelPosition, sss);
				}
			}
			outputFile.write(sss.c_str(), sss.length());
			outputFile.write("\n", 1);
		}
	}
	else
	{
		printf("Ошибка открытия входного файла.\n");
		_getch();
		exit(1);
	}
	inputFile.close();
	outputFile.close();
}

void inputValidation(int argc)
{
	if (argc <= 4)
	{
		printf("Ошибка! Не хватает аргументов для работы программы.\n");
		_getch();
		exit(0);
	}

	else if (argc > 5)
	{
		printf("Ошибка! Слишком много аргументов для работы программы.\n");
		_getch();
		exit(1);
	}
}

int main(int argc, char *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	inputValidation(argc);
	workingWithFiles(argv[1], argv[3], argv[4], argv[2]);
	return 0;
}	

