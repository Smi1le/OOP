// FindMaxEx.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "FindMaxEx.h"
#include <iostream>

using namespace std;

int main()
{
	int maxValue;
	vector<int> arr = { 80, 5, -93, 5568 };
	FindMax(arr, maxValue, [](int lhs, int rhs) {return lhs > rhs; });
	std::cout << "maxValue = " << maxValue << std::endl;
    return 0;
}

