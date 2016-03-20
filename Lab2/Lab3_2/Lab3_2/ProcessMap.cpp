#include "stdafx.h"
#include "ProcessMap.h"

using namespace std;

static const string DICTIONARY = "dictionary.txt";
static const string EXIT = "...";
static const string EMPTY_STRING = "";
static const char YES = 'Y';

Dictionary ReadDictionaryWithFile()
{
	ifstream inputFile(DICTIONARY);
	string fileString;
	Dictionary dictionary;
	while (getline(inputFile, fileString))
	{
		vector<string> stringDict;
		boost::split(stringDict, fileString, boost::is_any_of(":"));
		dictionary.insert(pair<string, string>(stringDict[0], stringDict[1]));
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

string LineReception()
{
	cout << "Пожалуйста, введите ключ для поиска.\n";
	string inString;
	getline(cin, inString);
	return inString;
}

bool InspectionLine(string &keyToFind)
{
	keyToFind = LineReception();
	if (keyToFind == EXIT)
	{
		return false;
	}
	return true;
}

bool SearchByKeyValues(Dictionary const &dictionary, string const &keyToFind, string &value)
{
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		if (it->first == keyToFind)
		{
			value = it->second;
			return true;
		}
	}
	return false;
}

void AddNewWordInDictionary(Dictionary &dictionary, string const &keyToFind, string const &newValueForNewKey)
{
	dictionary.insert(pair<string, string>(keyToFind, newValueForNewKey));
	cout << "Слово " << keyToFind << " сохранено в словаре как " << newValueForNewKey << "." << endl;
}

void FillDictionary(Dictionary const &dictionary)
{
	ofstream outFile(DICTIONARY);
	for (auto pair : dictionary)
	{
		outFile << pair.first << ":" << pair.second << endl;
	}
}

void Save(Dictionary &dictionary)
{
	cout << "В словарь были внесены изменения. Если желаете их сохранить то введите Y\n";
	char agreement;
	cin >> agreement;
	if (toupper(agreement) == YES)
	{
		FillDictionary(dictionary);
		cout << "Изменения были сохранены в словарь. Спасибо за работу. До свидания." << endl;
	}
}

void WorkWithDictionary(Dictionary &dictionary)
{
	string keyToFind;
	bool wasAdd = false;
	while (InspectionLine(keyToFind))
	{
		string value;
		if (SearchByKeyValues(dictionary, keyToFind, value))
		{
			cout << value << endl;
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
		Save(dictionary);
	}
}

void UserInteraction()
{
	Dictionary dictionary = ReadDictionaryWithFile();
	WorkWithDictionary(dictionary);
	Output(dictionary);
}

void ProcessMap()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	UserInteraction();
}

