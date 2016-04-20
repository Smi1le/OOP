// Task_4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "GetParamShapes.h"
#include "GetDataWithFile.h"
#include <iterator>

void OutputDataInConsole(std::vector<std::shared_ptr<IShape>> parameterShapes)
{
	for (auto elem : parameterShapes)
	{
		std::cout << elem->GetDescription() << std::endl;
	}
}


int main()
{
	std::string name = "input.txt";
	auto elements = GetDataWithFile(name);
	auto parametersShapes = GetParamShapes(elements);
	OutputDataInConsole(parametersShapes);
	return 0;
}

