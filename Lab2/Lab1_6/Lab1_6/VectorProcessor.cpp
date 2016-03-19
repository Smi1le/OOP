#include "stdafx.h"
#include "VectorProcessor.h"
#include <algorithm>
#include <iterator>


using namespace std;

double SearchMaxElement(vector<double> const &numbers)
{
	auto maxNumber = max_element(numbers.begin(), numbers.end());
	double max = distance(numbers.begin(), maxNumber);
	return numbers[max];
}

double SearchMinElement(vector<double> const &numbers)
{
	auto maxNumber = min_element(numbers.begin(), numbers.end());
	double min = distance(numbers.begin(), maxNumber);
	return numbers[min];
}

void OutputInConcole(std::vector<double> &numbers)
{
	
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, ", "));
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
	//OutputInConcole(numbers);
}