// OOP_Lab1_Part3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

const int MATRIX_SIZE = 3;

struct Vector2i
{
	int x;
	int y;
};

struct AppData
{
	int sourceMatrix[MATRIX_SIZE][MATRIX_SIZE];
	int determinantSourceMatrix;
	int cofactorsMatrix[MATRIX_SIZE][MATRIX_SIZE];
	int transposedMatrix[MATRIX_SIZE][MATRIX_SIZE];
	float inverseMatrix[MATRIX_SIZE][MATRIX_SIZE];
};

void ReadFromFile(AppData &appData, const string &fileName)
{
	ifstream inputFile(fileName);
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			inputFile >> appData.sourceMatrix[i][j];
		}
	}
}

void FindDeterminantMatrix(AppData &appData)
{
	appData.determinantSourceMatrix = ((appData.sourceMatrix[0][0] * pow(-1, 1 + 1) * (appData.sourceMatrix[1][1] * appData.sourceMatrix[2][2] -
			appData.sourceMatrix[2][1] * appData.sourceMatrix[1][2])) + 
		(appData.sourceMatrix[1][0] * pow(-1, 2 + 1) * (appData.sourceMatrix[0][1] * appData.sourceMatrix[2][2] -
			appData.sourceMatrix[2][1] * appData.sourceMatrix[0][2])) + 
		(appData.sourceMatrix[2][0] * pow(-1, 3 + 1) * (appData.sourceMatrix[0][1] * appData.sourceMatrix[1][2] -
			appData.sourceMatrix[1][1] * appData.sourceMatrix[0][2])));
}

void TransposeMatrix(AppData &appData)
{
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			appData.transposedMatrix[j][i] = appData.cofactorsMatrix[i][j];
		}
	}
}

void DeterminingPositionsCellsMatrix(int &firstLine, int &firstColumn, int &secondLine, int &secondColumn, const int &i, const int &j)
{
	if (i == 0)
	{
		firstLine = 1;
	}
	else if (i > 0)
	{
		firstLine = 0;
	}
	if (j == 0)
	{
		firstColumn = 1;
	}
	else if (j > 0)
	{
		firstColumn = 0;
	}
	if (i == 2)
	{
		secondLine = 1;
	}
	else if (i < 2)
	{
		secondLine = 2;
	}
	if (j == 2)
	{
		secondColumn = 1;
	}
	else if (j < 2)
	{
		secondColumn = 2;
	}
}

void BeInverted(AppData &appData)
{
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			appData.inverseMatrix[i][j] = (1.0f / float(appData.determinantSourceMatrix)) * float(appData.transposedMatrix[i][j]);
		}
	}
}

void CalculationMatrixCofactors(AppData &appData)
{
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			Vector2i firstCell;
			Vector2i secondCell;
			int productFirstDiagonal;
			int productSecondDiagonal;
			DeterminingPositionsCellsMatrix(firstCell.x, firstCell.y, secondCell.x, secondCell.y, i, j);
			productFirstDiagonal = appData.sourceMatrix[firstCell.x][firstCell.y] * appData.sourceMatrix[secondCell.x][secondCell.y];
			DeterminingPositionsCellsMatrix(secondCell.x, firstCell.y, firstCell.x, secondCell.y, i, j);
			productSecondDiagonal = appData.sourceMatrix[firstCell.x][firstCell.y] * appData.sourceMatrix[secondCell.x][secondCell.y];
			appData.cofactorsMatrix[i][j] = pow(-1, (i + 1) + (j + 1)) * (productFirstDiagonal - productSecondDiagonal);
		}
	}
}

void OutputInConsole(const AppData &appData)
{
	cout << "Обратная матрица: \n";
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			cout << appData.inverseMatrix[i][j];
			cout << " ";
		}
		cout << "\n";
	}
}

bool InputValidation(int argc)
{
	if (argc <= 1)
	{
		printf("Ошибка! Не хватает аргументов для работы программы.\n");
		_getch();
		return false;
	}

	else if (argc > 2)
	{
		printf("Ошибка! Слишком много аргументов для работы программы.\n");
		_getch();
		return false;
	}
	else if (argc == 2)
	{
		return true;
	}
}

void CompletionChecks(bool ifCanWork)
{
	if (ifCanWork)
	{
		std::cout << "Выполнение завершено. Программа выполнена успешно." << std::endl;
	}
	else
	{
		std::cout << "Программа не выполнена." << std::endl;;
	}
	_getch();
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");
	bool ifCanWork = InputValidation(argc);
	if (ifCanWork)
	{
		AppData appData;
		string inputFileName = argv[1];
		ReadFromFile(appData, inputFileName);
		FindDeterminantMatrix(appData);
		CalculationMatrixCofactors(appData);
		TransposeMatrix(appData);
		BeInverted(appData);
		OutputInConsole(appData);
	}
	CompletionChecks(ifCanWork);
    return 0;
}

