// Task_4.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "GetParamShapes.h"
#include "GetDataWithFile.h"


int main()
{
	std::string name = "input.txt";
	auto elements = GetDataWithFile(name);
	GetParamShapes(elements);
	return 0;
}

