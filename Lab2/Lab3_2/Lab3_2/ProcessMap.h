#pragma once
#include "stdafx.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <iterator>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>



typedef std::map<std::string, std::string> Dictionary;

void ProcessMap(std::string const &nameDictionary);
std::string LineReception();
Dictionary ReadDictionaryWithFile(std::string const &nameDictionary);
bool InspectionLine(std::string &keyToFind);
bool SearchByKeyValues(Dictionary const &dictionary, std::string const &keyToFind, std::string &value);
void WorkWithDictionary(Dictionary &dictionary, std::string const &nameDictionary);
void Save(Dictionary &dictionary, std::string const &nameDictionary);
void FillDictionary(Dictionary const &dictionary, std::string const &nameDictionary);
