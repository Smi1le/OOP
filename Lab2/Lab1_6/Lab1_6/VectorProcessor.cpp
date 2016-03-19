#include "stdafx.h"
#include "VectorProcessor.h"
#include <algorithm>
#include <iterator>


using namespace std;

double SearchMaxElement(vector<double> const &numbers)
{
	return *max_element(numbers.begin(), numbers.end());
	
}

double SearchMinElement(vector<double> const &numbers)
{
	return *min_element(numbers.begin(), numbers.end());
	
}

void ConversionVectorElements(vector<double> &numbers)
{
	if (!numbers.empty())
	{
		double minNumber = SearchMinElement(numbers);
		double maxNumber = SearchMaxElement(numbers);
		for (auto &element : numbers)
		{
			element = (element * maxNumber) / minNumber;
		}
	}
	sort(numbers.begin(), numbers.end());
}