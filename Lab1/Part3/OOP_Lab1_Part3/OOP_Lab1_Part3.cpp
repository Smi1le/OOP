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

bool ReadMatrixFromFile(double (&sourceMatrix)[MATRIX_SIZE][MATRIX_SIZE], const string &fileName)
{
	ifstream inputFile(fileName);
	if (inputFile)
	{
		for (size_t i = 0; i < MATRIX_SIZE; i++)
		{
			for (size_t j = 0; j < MATRIX_SIZE; j++)
			{
				inputFile >> sourceMatrix[i][j];
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

double FindDeterminantMatrix(double(&sourceMatrix)[MATRIX_SIZE][MATRIX_SIZE], bool &matrixDegenerate)
{
	double determinantSourceMatrix = ((sourceMatrix[0][0] * pow(-1, 1 + 1) * (sourceMatrix[1][1] * sourceMatrix[2][2] -
			sourceMatrix[2][1] * sourceMatrix[1][2])) + 
		(sourceMatrix[1][0] * pow(-1, 2 + 1) * (sourceMatrix[0][1] * sourceMatrix[2][2] -
			sourceMatrix[2][1] * sourceMatrix[0][2])) + 
		(sourceMatrix[2][0] * pow(-1, 3 + 1) * (sourceMatrix[0][1] * sourceMatrix[1][2] -
			sourceMatrix[1][1] * sourceMatrix[0][2])));
	if (determinantSourceMatrix == 0)
	{
		matrixDegenerate = true;
	}
	return determinantSourceMatrix;
}

void TransposeMatrix(double(&sourceMatrix)[MATRIX_SIZE][MATRIX_SIZE], double(&cofactorsMatrix)[MATRIX_SIZE][MATRIX_SIZE])
{
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			sourceMatrix[j][i] = cofactorsMatrix[i][j];
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

void CalculationMatrixCofactors(const double (&sourceMatrix)[MATRIX_SIZE][MATRIX_SIZE], double (&cofactorsMatrix)[MATRIX_SIZE][MATRIX_SIZE])
{
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			Vector2i firstCell;
			Vector2i secondCell;
			double productFirstDiagonal;
			double productSecondDiagonal;
			DeterminingPositionsCellsMatrix(firstCell.x, firstCell.y, secondCell.x, secondCell.y, i, j);
			productFirstDiagonal = sourceMatrix[firstCell.x][firstCell.y] * sourceMatrix[secondCell.x][secondCell.y];
			DeterminingPositionsCellsMatrix(secondCell.x, firstCell.y, firstCell.x, secondCell.y, i, j);
			productSecondDiagonal = sourceMatrix[firstCell.x][firstCell.y] * sourceMatrix[secondCell.x][secondCell.y];
			cofactorsMatrix[i][j] = pow(-1, (i + 1) + (j + 1)) * (productFirstDiagonal - productSecondDiagonal);
		}
	}
}

void BeInverted(double(&sourceMatrix)[MATRIX_SIZE][MATRIX_SIZE], const double determinantSourceMatrix)
{
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			sourceMatrix[i][j] = (1.0 / determinantSourceMatrix) * sourceMatrix[i][j];
		}
	}
}

void FindingInverseMatrix(double (&sourceMatrix)[MATRIX_SIZE][MATRIX_SIZE], bool &matrixDegenerate)
{
	double determinateSourceMatrix = FindDeterminantMatrix(sourceMatrix, matrixDegenerate);
	if (!matrixDegenerate)
	{
		double cofactorsMatrix[MATRIX_SIZE][MATRIX_SIZE];
		CalculationMatrixCofactors(sourceMatrix, cofactorsMatrix);
		TransposeMatrix(sourceMatrix, cofactorsMatrix);
		BeInverted(sourceMatrix, determinateSourceMatrix);
	}
}



void OutputInConsole(const double (&sourceMatrix)[MATRIX_SIZE][MATRIX_SIZE], const bool &matrixDegenerate)
{
	if (!matrixDegenerate)
	{
		cout << "Обратная матрица: \n";
		for (size_t i = 0; i < MATRIX_SIZE; i++)
		{
			for (size_t j = 0; j < MATRIX_SIZE; j++)
			{
				cout << sourceMatrix[i][j];
				cout << " ";
			}
			cout << "\n";
		}
	}
	else
	{
		cout << "Матрица является вырожденной\n";
	}
}

bool InputValidation(int argc)
{
	if (argc <= 1)
	{
		printf("Ошибка! Не хватает аргументов для работы программы. Программе нужно передавать 1 параметр.\n");
		return false;
	}

	else if (argc > 2)
	{
		printf("Ошибка! Слишком много аргументов для работы программы. Программе нужно передавать 1 параметр.\n");
		return false;
	}
	else
	{
		return true;
	}
}

void Filing(const double(&sourceMatrix)[MATRIX_SIZE][MATRIX_SIZE])
{
	std::string outputFileName = "out.txt";
	ofstream outputFile;
	outputFile.open(outputFileName);
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			outputFile << sourceMatrix[i][j];
			outputFile << " ";
		}
		outputFile << "\n";
	}
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");
	bool matrixDegenerate = false;
	if (InputValidation(argc))
	{
		double sourceMatrix[MATRIX_SIZE][MATRIX_SIZE];
		string inputFileName = argv[1];
		if (ReadMatrixFromFile(sourceMatrix, inputFileName))
		{
			FindingInverseMatrix(sourceMatrix, matrixDegenerate);
			OutputInConsole(sourceMatrix, matrixDegenerate);
			if (!matrixDegenerate)
			{
				Filing(sourceMatrix);
				std::cout << "Выполнение завершено. Программа выполнена успешно." << std::endl;
				return 0;
			}
			else
			{
				std::cout << "Программа не выполнена." << std::endl;
				return 1;
			}
		}
		else
		{
			return 2;
		}
	}
	else
	{
		return 1;
	}
}

