// Lab2_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "ProcessorMap.h"

using namespace std;

enum STATUS_CODE {ITS_ALL_OK = 0, ERROR = 1};

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Error! Usage replace.exe<search-string><replace-string>/n";
		return STATUS_CODE::ERROR;
	}
	string subject = "I can Fly, maybe. You can?";
	string search = argv[1];
	string replace = argv[2];
	string str = FindAndReplace(subject, search, replace);
	return STATUS_CODE::ITS_ALL_OK;
}

