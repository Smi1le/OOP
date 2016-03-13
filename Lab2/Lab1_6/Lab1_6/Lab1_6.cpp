#include "stdafx.h"
#include "VectorProcessor.h"
#include <iterator>

using namespace std;

int main()
{
	vector<double> numbers;
	copy(istream_iterator<double>(cin), istream_iterator<double>(), back_inserter(numbers));
	ConversionVectorElements(numbers);
	return 0;
}
