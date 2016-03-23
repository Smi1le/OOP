#include "stdafx.h"
#include "ProcessMap.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <iterator>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;

static const string EXIT = "...";
static const string EMPTY_STRING = "";
static const char YES = 'Y';

Dictionary ReadDictionaryWithFile(std::string const &nameDictionary)
{
	ifstream inputFile(nameDictionary);
	Dictionary dictionary;
	if (inputFile)
	{
		string fileString;
		while (getline(inputFile, fileString))
		{
			vector<string> stringDict;
			boost::split(stringDict, fileString, boost::is_any_of(":"));
			dictionary.insert(dictionary.end(), pair<string, string>(stringDict[0], stringDict[1]));
		}
	}
	return dictionary;
}

void Output(Dictionary const &dict)
{
	for (auto it = dict.begin(); it != dict.end(); ++it)
	{
		cout << "name = " << it->first << " translate = " << it->second << endl;
	}
}

bool receiptSearchKey(string &keyToFind)
{
	cout << "Пожалуйста, введите ключ для поиска.\n";
	getline(cin, keyToFind);
	return keyToFind == EXIT ? false : true;
}

string ToUpper(string const &toUpperString)
{
	string bufStr;
	for (auto ch : toUpperString)
	{
		bufStr += toupper(ch);
	}
	return bufStr;
}

bool SearchByKeyValues(Dictionary const &dictionary, string const &keyToFind, vector<string> &value)
{
	bool wasFind = false;
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		if (ToUpper(it->first) == ToUpper(keyToFind))
		{
			value.push_back(it->second);
			wasFind = true;
		}
		if (ToUpper(it->second) == ToUpper(keyToFind))
		{
			value.push_back(it->first);
			wasFind = true;
		}
	}
	return wasFind;
}

void AddNewWordInDictionary(Dictionary &dictionary, string const &keyToFind, string const &newValueForNewKey)
{
	dictionary.insert(dictionary.end(), pair<string, string>(keyToFind, newValueForNewKey));
	cout << "Слово " << keyToFind << " сохранено в словаре как " << newValueForNewKey << "." << endl;
}

void FillDictionary(Dictionary const &dictionary, std::string const &nameDictionary)
{
	ofstream outFile(nameDictionary);
	for (auto pair : dictionary)
	{
		outFile << pair.first << ":" << pair.second << endl;
	}
}

void Save(Dictionary &dictionary, std::string const &nameDictionary)
{
	cout << "В словарь были внесены изменения. Если желаете их сохранить то введите Y\n";
	char agreement;
	cin >> agreement;
	if (toupper(agreement) == YES)
	{
		FillDictionary(dictionary, nameDictionary);
		cout << "Изменения были сохранены в словарь. Спасибо за работу. До свидания." << endl;
	}
}

void UserIntaraction(Dictionary &dictionary, std::string const &nameDictionary)
{
	string keyToFind;
	bool wasAdd = false;
	while (receiptSearchKey(keyToFind))
	{
		vector<string> values;
		if (SearchByKeyValues(dictionary, keyToFind, values))
		{
			copy(values.begin(), values.end(), ostream_iterator<string>(cout, "\n"));
		}
		else
		{
			cout << "Неизвесное слово " << keyToFind << ". Введите перевод или пустую строку для отказа." << endl;
			string newValueForNewKey;
			getline(cin, newValueForNewKey);
			if (newValueForNewKey != EMPTY_STRING)
			{
				AddNewWordInDictionary(dictionary, keyToFind, newValueForNewKey);
				wasAdd = true;
			}
			else
			{
				cout << "Слово " << keyToFind << " проигнорированно.\n";
			}
		}
	}
	if (wasAdd)
	{
		Save(dictionary, nameDictionary);
	}
}

void WorkWithDictionary(std::string const &nameDictionary)
{
	Dictionary dictionary = ReadDictionaryWithFile(nameDictionary);
	UserIntaraction(dictionary, nameDictionary);
	//Output(dictionary);
}

void ProcessMap(std::string const &nameDictionary)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	WorkWithDictionary(nameDictionary);
}

