#include "stdafx.h"
#include "VectorProcessor.h"
#include <algorithm>
#include <iterator>


using namespace std;

void OutputInConsole(vector<double> const &numbers)
{
	copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(cout, ", "));
	cout << endl;
}

void ConversionVectorElements(vector<double> &numbers)
{
	if (!numbers.empty())
	{
		double minNumber = *min_element(numbers.begin(), numbers.end());;
		double maxNumber = *max_element(numbers.begin(), numbers.end());
		for (auto &element : numbers)
		{
			minNumber != 0 ? element *= maxNumber / minNumber : element *= maxNumber;
		}
	}
	OutputInConsole(numbers);
}