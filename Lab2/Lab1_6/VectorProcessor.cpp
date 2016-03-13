#include "stdafx.h"
#include "VectorProcessor.h"
#include <algorithm>
#include <iterator>


using namespace std;

double SearchMaxElement(vector<double> const &numbers)
{
	auto maxNumber = max_element(numbers.begin(), numbers.end());
	double max = distance(numbers.begin(), maxNumber);
	cout << "\n" << "maxNumber = " << numbers[max] << endl;
	return numbers[max];
}

double SearchMinElement(vector<double> const &numbers)
{
	auto maxNumber = min_element(numbers.begin(), numbers.end());
	double min = distance(numbers.begin(), maxNumber);
	cout << "\n" << "minNumber = " << numbers[min] << endl;
	return numbers[min];
}

void ConversionVectorElements(vector<double> &numbers)
{
	auto minNumber = SearchMinElement(numbers);
	auto maxNumber = SearchMaxElement(numbers);
	for (auto &element : numbers)
	{
		element = (element * maxNumber) / minNumber;
	}
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, ", "));
}