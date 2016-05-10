#pragma once
#include <vector>
#include <string>
#include <iostream>

using dataShapes = std::vector<std::vector<std::string>>;

// loadFile
dataShapes DownloadTheFile(std::string const &nameInputFile);

// parseInfo
dataShapes ParseInfo(std::vector<std::string> const &info);