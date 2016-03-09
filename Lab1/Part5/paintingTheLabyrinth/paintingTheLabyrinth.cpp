// paintingTheLabyrinth.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>

static const char START_SYMBOL = 'O';
static const char POINT = '.';

struct Vector2i
{
	int x;
	int y;
};

struct AppData
{
	
	
};

bool ReadLabyrinthFromFile(std::vector<std::string> &labyrinth, const std::string &inputFileName)
{
	std::fstream inputFile(inputFileName);
	labyrinth.resize(100);
	int i = 0;
	if (inputFile)
	{
		while (!inputFile.eof())
		{
			std::string readLineFromFile;
			std::getline(inputFile, readLineFromFile);
			labyrinth[i] = readLineFromFile;
			i++;
		}
		return true;
	}
	else
	{
		return false;
	}
}

void ChangeVectorSizes100To100(std::vector<std::string> &labyrinth)
{
	for (size_t i = 0; i < labyrinth.size();)
	{
		std::string lineArray = labyrinth[i];
		if (lineArray.size() == 0)
		{
			while (i < 100)
			{
				std::string stringWithSpaces;
				stringWithSpaces.resize(100, ' ');
				labyrinth[i] = stringWithSpaces;
				i++;
			}
		}
		else if (lineArray.size() < 100)
		{
			while (lineArray.size() < 100)
			{
				lineArray.append(" ");
			}
			labyrinth[i] = lineArray;
			i++;
		}
		
	}
}

void SearchInitialPointsCoordinates(std::vector<Vector2i> &coordinatesInitialPoints, const std::vector<std::string> &labyrinth)
{
	int i = 0;
	for (auto mazeLine : labyrinth)
	{
		
		int numberPositionInitialPoints = std::min(mazeLine.find(START_SYMBOL), mazeLine.find(tolower(START_SYMBOL)));
		do
		{
			if (numberPositionInitialPoints != -1)
			{
				mazeLine.erase(numberPositionInitialPoints, 1);
				coordinatesInitialPoints.push_back({ i, numberPositionInitialPoints + 1 });
				numberPositionInitialPoints = std::min(mazeLine.find(START_SYMBOL), mazeLine.find(tolower(START_SYMBOL)));
			}
		} while (numberPositionInitialPoints != -1);
		i++;
	}
}

/*void OutputInConsole(const std::vector<std::string> &labyrinth)
{
	for (auto mazeLine : labyrinth)
	{
		std::cout << mazeLine << std::endl;
	}
}*/

bool CanFiling(const Vector2i &coord, const std::vector<std::string> &labyrinth)
{
	return ((coord.y <= labyrinth[coord.x].size() - 1) &&
		(toupper(labyrinth[coord.x][coord.y]) == ' '));
}

void CheckTheNeighbouringElements(std::queue<Vector2i> &allForPainting, std::vector<std::string> &labyrinth, const Vector2i &coordinates)
{
	if (coordinates.x >= 0 && coordinates.y > 0 && (coordinates.x < labyrinth.size() - 1))
	{
		
		if (CanFiling({ coordinates.x , coordinates.y + 1 }, labyrinth))
		{
			labyrinth[coordinates.x][coordinates.y + 1] = POINT;
			allForPainting.push({ coordinates.x, coordinates.y + 1 });
		}
		if (CanFiling({ coordinates.x + 1 , coordinates.y }, labyrinth))
		{
			labyrinth[coordinates.x + 1][coordinates.y] = POINT;
			allForPainting.push({ coordinates.x + 1, coordinates.y });
		}
	}
	if (coordinates.x > 0 && coordinates.y >= 0 && (coordinates.x < labyrinth.size() - 1))
	{
		if (CanFiling({ coordinates.x - 1 , coordinates.y }, labyrinth))
		{
			labyrinth[coordinates.x - 1][coordinates.y] = POINT;
			allForPainting.push({ coordinates.x - 1, coordinates.y });
		}
		if (CanFiling({ coordinates.x , coordinates.y - 1 }, labyrinth))
		{
			labyrinth[coordinates.x][coordinates.y - 1] = POINT;
			allForPainting.push({ coordinates.x, coordinates.y - 1 });
		}
		
	}
}

void Filing(const std::string outputFileName, const std::vector<std::string> &labyrinth)
{
	std::ofstream outputFile(outputFileName);
	for (auto readLine : labyrinth)
	{
		outputFile << readLine << "\n";
	}
}

void PaintingTheLabyrinth(std::vector<std::string> &labyrinth)
{
	ChangeVectorSizes100To100(labyrinth);
	std::vector<Vector2i> coordinatesInitialPoints;
	SearchInitialPointsCoordinates(coordinatesInitialPoints, labyrinth);
	while (!coordinatesInitialPoints.empty())
	{
		std::queue<Vector2i> allForPainting;
		auto lastElement = coordinatesInitialPoints.size() - 1;
		allForPainting.push(coordinatesInitialPoints[lastElement]);
		coordinatesInitialPoints.pop_back();
		while (!allForPainting.empty()) 
		{
			Vector2i coordinates = allForPainting.front();
			allForPainting.pop();
			if (coordinates.x >= 0 && coordinates.y >= 0 && (coordinates.x <= labyrinth.size() - 1))
			{
				if (labyrinth[coordinates.x][coordinates.y] == ' ')
				{
					labyrinth[coordinates.x][coordinates.y] = POINT;
				}
			}
			CheckTheNeighbouringElements(allForPainting, labyrinth, coordinates);
		}
	}
}



int main(int argc, char *argv[])
{
	std::vector<std::string> labyrinth;
	if (argc != 3)
	{
		std::cout << "Error! Usage fill.exe <inputfile> <outputfile> " << std::endl;
		return 1;
	}
	std::string inputFileName = argv[1];
	if (ReadLabyrinthFromFile(labyrinth, inputFileName))
	{
		std::string outputFileName = argv[2];
		PaintingTheLabyrinth(labyrinth);
		Filing(outputFileName, labyrinth);
		return 0;
	}
	else
	{
		std::cout << "Unable to open file!" << std::endl;
		return 2;
	}
}

