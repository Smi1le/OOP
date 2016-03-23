#pragma once
#include <string>
#include <map>
#include <vector>


typedef std::multimap<std::string, std::string> Dictionary;

void ProcessMap(std::string const &nameDictionary);
std::string LineReception();
Dictionary ReadDictionaryWithFile(std::string const &nameDictionary);
bool receiptSearchKey(std::string &keyToFind);
bool SearchByKeyValues(Dictionary const &dictionary, std::string const &keyToFind, std::vector<std::string> &value);
void UserIntaraction(Dictionary &dictionary, std::string const &nameDictionary);
void Save(Dictionary &dictionary, std::string const &nameDictionary);
void FillDictionary(Dictionary const &dictionary, std::string const &nameDictionary);
