// Task_4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "GetParamShapes.h"
#include "GetDataWithFile.h"
#include <iterator>
#include <map>
#include <algorithm>


//use std::sort - yes


void OutputDataInSortedOrder(std::vector<std::shared_ptr<IShape>> &parameterShapes)
{
	SortVectorForArea(parameterShapes);
	for (auto elem : parameterShapes)
	{
		std::cout << elem->GetDescription() << std::endl;
	}
	std::cout << ">>-----------------------------------------------------------------<<" << std::endl;
	std::cout << ">>-----------------------------------------------------------------<<" << std::endl;
	SortVectorForPerimeter(parameterShapes);
	for (auto elem : parameterShapes)
	{
		std::cout << elem->GetDescription() << std::endl;
	}
}

int main()
{
	std::string name = "input.txt";
	auto elements = ReadFromFile(name);
	std::vector<std::shared_ptr<IShape>> parametersShapes;
	for (auto element : elements)
	{
		if (CheckVectorForSize(element))
		{
			parametersShapes.push_back(CreateShape(element));
		}
		else
		{
			std::cout << "Wrong name or the wrong set of data for the figures" << std::endl;
		}
	}
	OutputDataInSortedOrder(parametersShapes);
	system("pause");
	return 0;
}

