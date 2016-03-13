// Lab2_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

string FindAndReplace(string subject, string const &search, string const &replace)
{
	if (subject.length() != 0)
	{
		string bufStr;
		int indexSubstringOccurrences = 0;
		while (indexSubstringOccurrences != -1)
		{
			indexSubstringOccurrences = subject.find(search);
			if (indexSubstringOccurrences == -1)
			{
				bufStr.append(subject);
			}
			else
			{
				bufStr.append(subject.substr(0, indexSubstringOccurrences));
				bufStr.append(replace);
				subject.erase(0, indexSubstringOccurrences + search.length());
			}
		}
		return bufStr;
	}
	else
	{
		return subject;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Error! Usage replace.exe<search-string><replace-string>" << endl;
		return 1;
	}
	else
	{
		string subject = "I can Fly, maybe. You can?";
		string search = argv[1];
		string replace = argv[2];
		string str = FindAndReplace(subject, search, replace);
		cout << str << endl;
		return 0;
	}
}

