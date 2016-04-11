#pragma once
#include <vector>
#include <string>
#include <iostream>

using dataShapes = std::vector<std::vector<std::string>>;

dataShapes GetDataWithFile(std::string const &nameInputFile);
dataShapes ParsingInfoShapes(std::vector<std::string> const &info);