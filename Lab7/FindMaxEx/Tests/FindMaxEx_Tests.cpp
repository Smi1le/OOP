#include "stdafx.h"
#include "../FindMaxEx/FindMaxEx.h"

BOOST_AUTO_TEST_SUITE(FindMaxEx)

	BOOST_AUTO_TEST_CASE(can_not_find_the_max_value_in_the_empty_vector)
	{
		std::vector<int> arr = {};
		int maxValue;
		BOOST_CHECK(!FindMax(arr, maxValue, [](int lhs, int rhs) {return lhs < rhs; }));
	}

	BOOST_AUTO_TEST_CASE(the_maximum_value_can_be_found_in_the_vector_when_it_is_initialized)
	{
		std::vector<int> arr = { 54, 96, 213, 654, 321, 34, 33 };
		int maxValue = 0;
		BOOST_CHECK(FindMax(arr, maxValue, [](int lhs, int rhs) {return lhs < rhs; }));
		BOOST_CHECK(maxValue == 654);
	}

	BOOST_AUTO_TEST_CASE(length_strings_can_be_compared_between_themselves_and_with_the_maximum_length_to_obtain)
	{
		std::vector<std::string> arr = { "mama", "ocean", "summer", "aqua", "school", "HULK", "beefsteak" };
		std::string stringMaxLength;
		BOOST_CHECK(FindMax(arr, stringMaxLength, [](std::string const &lhs, std::string const &rhs)
		{return lhs.length() < rhs.length(); }));
		BOOST_CHECK(stringMaxLength == "beefsteak");
	}

	BOOST_AUTO_TEST_CASE(you_can_check_not_passing_lambda_function)
	{
		std::vector<int> arr = { 6546, 5348, 2318, 97645313, 548621, 54212 };
		int maxValue = 0;
		BOOST_CHECK(FindMax(arr, maxValue));
		BOOST_CHECK(maxValue == 97645313);
	}

BOOST_AUTO_TEST_SUITE_END()