#include "stdafx.h"
#include "..\Lab1_6\VectorProcessor.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(ProcessVector_function)
	BOOST_AUTO_TEST_CASE(makes_empty_vector_from_empty_vector)
	{
		vector<double> emptyVector;
		ConversionVectorElements(emptyVector);
		BOOST_CHECK(emptyVector.empty());
	}

	BOOST_AUTO_TEST_CASE(calculation_of_the_value_of_the_vector_in_sorted_order)
	{
		vector<double> numbers = { -4, 4, 5, 8};
		vector<double> reference = { -16, -10, -8, 8};
		ConversionVectorElements(numbers);
		BOOST_CHECK(numbers == reference);
	}

	BOOST_AUTO_TEST_CASE(on_a_single_vector)
	{
		vector<double> numbers = { 1, 1, 1, 1, 1 };
		auto copy(numbers);
		ConversionVectorElements(numbers);
		BOOST_CHECK(numbers == copy);
	}
BOOST_AUTO_TEST_SUITE_END()