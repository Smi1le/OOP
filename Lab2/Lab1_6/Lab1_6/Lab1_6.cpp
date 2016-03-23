#include "stdafx.h"
#include "VectorProcessor.h"
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	vector<double> numbers;
	copy(istream_iterator<double>(cin), istream_iterator<double>(), back_inserter(numbers));
	if (!numbers.empty())
	{
		ConversionVectorElements(numbers);
		sort(numbers.begin(), numbers.end());
		OutputInConsole(numbers);
	}
	return 0;
}
