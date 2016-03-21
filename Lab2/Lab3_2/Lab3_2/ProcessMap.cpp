#include "stdafx.h"
#include "ProcessMap.h"

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
			dictionary.insert(pair<string, string>(stringDict[0], stringDict[1]));
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

string LineReception()
{
	cout << "����������, ������� ���� ��� ������.\n";
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
	cout << "����� " << keyToFind << " ��������� � ������� ��� " << newValueForNewKey << "." << endl;
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
	cout << "� ������� ���� ������� ���������. ���� ������� �� ��������� �� ������� Y\n";
	char agreement;
	cin >> agreement;
	if (toupper(agreement) == YES)
	{
		FillDictionary(dictionary, nameDictionary);
		cout << "��������� ���� ��������� � �������. ������� �� ������. �� ��������." << endl;
	}
}

void WorkWithDictionary(Dictionary &dictionary, std::string const &nameDictionary)
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
			cout << "���������� ����� " << keyToFind << ". ������� ������� ��� ������ ������ ��� ������." << endl;
			string newValueForNewKey;
			getline(cin, newValueForNewKey);
			if (newValueForNewKey != EMPTY_STRING)
			{
				AddNewWordInDictionary(dictionary, keyToFind, newValueForNewKey);
				wasAdd = true;
			}
			else
			{
				cout << "����� " << keyToFind << " ����������������.\n";
			}
		}
	}
	if (wasAdd)
	{
		Save(dictionary, nameDictionary);
	}
}

void UserInteraction(std::string const &nameDictionary)
{
	Dictionary dictionary = ReadDictionaryWithFile(nameDictionary);
	WorkWithDictionary(dictionary, nameDictionary);
	//Output(dictionary);
}

void ProcessMap(std::string const &nameDictionary)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	UserInteraction(nameDictionary);
}

