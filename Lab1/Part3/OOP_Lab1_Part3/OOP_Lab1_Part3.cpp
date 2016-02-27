// OOP_Lab1_Part3.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	double sourceMatrix[MATRIX_SIZE][MATRIX_SIZE];
	double determinantSourceMatrix;
	double cofactorsMatrix[MATRIX_SIZE][MATRIX_SIZE];
	double resultMatrix[MATRIX_SIZE][MATRIX_SIZE];
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

void FindDeterminantMatrix(AppData &appData, bool &wasError)
{
	appData.determinantSourceMatrix = ((appData.sourceMatrix[0][0] * pow(-1, 1 + 1) * (appData.sourceMatrix[1][1] * appData.sourceMatrix[2][2] -
			appData.sourceMatrix[2][1] * appData.sourceMatrix[1][2])) + 
		(appData.sourceMatrix[1][0] * pow(-1, 2 + 1) * (appData.sourceMatrix[0][1] * appData.sourceMatrix[2][2] -
			appData.sourceMatrix[2][1] * appData.sourceMatrix[0][2])) + 
		(appData.sourceMatrix[2][0] * pow(-1, 3 + 1) * (appData.sourceMatrix[0][1] * appData.sourceMatrix[1][2] -
			appData.sourceMatrix[1][1] * appData.sourceMatrix[0][2])));
	if (appData.determinantSourceMatrix == 0)
	{
		wasError = true;
	}
}

void TransposeMatrix(AppData &appData)
{
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			appData.resultMatrix[j][i] = appData.cofactorsMatrix[i][j];
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

void BeInverted(AppData &appData)
{
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			appData.resultMatrix[i][j] = (1.0 / appData.determinantSourceMatrix) * appData.resultMatrix[i][j];
		}
	}
}

void CalculatingInverseMatrix(AppData &appData, bool &wasError)
{
	FindDeterminantMatrix(appData, wasError);
	if (!wasError)
	{
		CalculationMatrixCofactors(appData);
		TransposeMatrix(appData);
		BeInverted(appData);
	}
}



void OutputInConsole(const AppData &appData, const bool &wasError)
{
	if (!wasError)
	{
		cout << "�������� �������: \n";
		for (size_t i = 0; i < MATRIX_SIZE; i++)
		{
			for (size_t j = 0; j < MATRIX_SIZE; j++)
			{
				cout << appData.resultMatrix[i][j];
				cout << " ";
			}
			cout << "\n";
		}
	}
	else
	{
		cout << "������� �������� �����������\n";
	}
}

bool InputValidation(int argc)
{
	if (argc <= 1)
	{
		printf("������! �� ������� ���������� ��� ������ ���������.\n");
		return false;
	}

	else if (argc > 2)
	{
		printf("������! ������� ����� ���������� ��� ������ ���������.\n");
		return false;
	}
	else
	{
		return true;
	}
}

void CompletionChecks(const bool &ifCanWork, const bool &wasError)
{
	if (ifCanWork && !wasError)
	{
		std::cout << "���������� ���������. ��������� ��������� �������." << std::endl;
	}
	else
	{
		std::cout << "��������� �� ���������." << std::endl;;
	}
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");
	bool ifCanWork = InputValidation(argc);
	bool wasError = false;
	if (ifCanWork)
	{
		AppData appData;
		string inputFileName = argv[1];
		ReadFromFile(appData, inputFileName);
		CalculatingInverseMatrix(appData, wasError);
		OutputInConsole(appData, wasError);
	}
	CompletionChecks(ifCanWork, wasError);
	if (!wasError)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

