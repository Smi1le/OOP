// OOP_Lab1_Part3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int MATRIX_SIZE = 3;

struct Vector2i
{
	int x;
	int y;
};

typedef double Matrix[MATRIX_SIZE][MATRIX_SIZE];

bool ReadMatrixFromFile(Matrix (&sourceMatrix), const string &fileName)
{
	ifstream inputFile(fileName);
	if (inputFile)
	{
		for (size_t i = 0; i < MATRIX_SIZE; ++i)
		{
			for (size_t j = 0; j < MATRIX_SIZE; ++j)
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

double FindDeterminantMatrix(Matrix (&sourceMatrix), bool &matrixDegenerate)
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

void TransposeMatrix(Matrix (&sourceMatrix),Matrix (&cofactorsMatrix))
{
	for (size_t i = 0; i < MATRIX_SIZE; ++i)
	{
		for (size_t j = 0; j < MATRIX_SIZE; ++j)
		{
			sourceMatrix[j][i] = cofactorsMatrix[i][j];
		}
	}
}

void DeterminePositionsCellsMatrix(int &firstLine, int &firstColumn, int &secondLine, int &secondColumn, size_t i, size_t j)
{
	firstLine = (i == 0) ? 1 : 0;
	firstColumn = (j == 0) ? 1 : 0;

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



void CalculationMatrixCofactors(const Matrix (&sourceMatrix), Matrix (&cofactorsMatrix))
{
	for (size_t i = 0; i < MATRIX_SIZE; ++i)
	{
		for (size_t j = 0; j < MATRIX_SIZE; ++j)
		{
			Vector2i firstCell;
			Vector2i secondCell;
			DeterminePositionsCellsMatrix(firstCell.x, firstCell.y, secondCell.x, secondCell.y, i, j);
			double productFirstDiagonal = sourceMatrix[firstCell.x][firstCell.y] * sourceMatrix[secondCell.x][secondCell.y];
			DeterminePositionsCellsMatrix(secondCell.x, firstCell.y, firstCell.x, secondCell.y, i, j);
			double productSecondDiagonal = sourceMatrix[firstCell.x][firstCell.y] * sourceMatrix[secondCell.x][secondCell.y];
			cofactorsMatrix[i][j] = pow(-1, (i + 1) + (j + 1)) * (productFirstDiagonal - productSecondDiagonal);
		}
	}
}

void InvertMatrix(Matrix (&sourceMatrix), const double determinantSourceMatrix)
{
	for (size_t i = 0; i < MATRIX_SIZE; ++i)
	{
		for (size_t j = 0; j < MATRIX_SIZE; ++j)
		{
			sourceMatrix[i][j] = (1.0 / determinantSourceMatrix) * sourceMatrix[i][j];
		}
	}
}

void FindInverseMatrix(Matrix (&sourceMatrix), bool &matrixDegenerate)
{
	double determinateSourceMatrix = FindDeterminantMatrix(sourceMatrix, matrixDegenerate);
	if (!matrixDegenerate)
	{
		Matrix cofactorsMatrix;
		CalculationMatrixCofactors(sourceMatrix, cofactorsMatrix);
		TransposeMatrix(sourceMatrix, cofactorsMatrix);
		InvertMatrix(sourceMatrix, determinateSourceMatrix);
	}
}



void OutputInConsole(const Matrix (&sourceMatrix), const bool &matrixDegenerate)
{
	if (matrixDegenerate)
	{
		cout << "Матрица является вырожденной\n";
		return;
	}

	for (size_t i = 0; i < MATRIX_SIZE; ++i)
	{
		for (size_t j = 0; j < MATRIX_SIZE; ++j)
		{
			cout << sourceMatrix[i][j] << " ";
		}
		if (i != MATRIX_SIZE - 1)
		{
			cout << "\n";
		}
	}
}

bool CheckNumberArguments(int argc)
{
	if (argc != 2)
	{
		std::cout << "Error! Usage invert.exe <matrixfile1>." << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}

void FillMatrix(const Matrix (&sourceMatrix))
{
	std::string outputFileName = "out.txt";
	ofstream outputFile;
	outputFile.open(outputFileName);
	for (size_t i = 0; i < MATRIX_SIZE; ++i)
	{
		for (size_t j = 0; j < MATRIX_SIZE; ++j)
		{
			outputFile << sourceMatrix[i][j] << " ";
		}
		outputFile << "\n";
	}
}

enum STATUS_CODE {ALL_IS_OK = 0, PROGRAM_ERROR = 1, CANT_READ_FILE = 2};

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");
	bool matrixDegenerate = false;
	if (!CheckNumberArguments(argc))
	{
		return STATUS_CODE::PROGRAM_ERROR;
	}
	Matrix sourceMatrix;;
	string inputFileName = argv[1];
	if (ReadMatrixFromFile(sourceMatrix, inputFileName))
	{
		FindInverseMatrix(sourceMatrix, matrixDegenerate);
		OutputInConsole(sourceMatrix, matrixDegenerate);
		if (!matrixDegenerate)
		{
			return STATUS_CODE::ALL_IS_OK;
		}
		else
		{
			std::cout << "Программа не выполнена." << std::endl;
			return STATUS_CODE::PROGRAM_ERROR;
		}
	}
	else
	{
		return STATUS_CODE::CANT_READ_FILE;
	}
}

