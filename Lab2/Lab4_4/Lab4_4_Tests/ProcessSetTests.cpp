#include "stdafx.h"
#include "../Lab4_4/ProcessSet.h"

BOOST_AUTO_TEST_SUITE(ProcessSet_function)

BOOST_AUTO_TEST_CASE(we_pass_one_get_one)
{
	BOOST_CHECK(GeneratePrimeNumbersSet(1).empty());
}

BOOST_AUTO_TEST_CASE(screening_of_ten_numbers)
{//TODO 0, 1, Example : 18, 19, 20
	std::set<int> reference = { 2, 3, 5, 7 };
	BOOST_CHECK(GeneratePrimeNumbersSet(10) == reference);
}

BOOST_AUTO_TEST_CASE(to_fifty_numbers_of_check)
{
	std::set<int> reference = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
	BOOST_CHECK(GeneratePrimeNumbersSet(50) == reference);
}

BOOST_AUTO_TEST_CASE(at_one_hundred_numbers_of_check)
{
	std::set<int> reference = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
	BOOST_CHECK(GeneratePrimeNumbersSet(100) == reference);
}

BOOST_AUTO_TEST_CASE(check_number_18_the_last_number_should_be_17)
{//TODO 0, 1, Example : 18, 19, 20
	std::set<int> reference = { 2, 3, 5, 7, 11, 13, 17 };
	BOOST_CHECK(GeneratePrimeNumbersSet(18) == reference);
}

BOOST_AUTO_TEST_CASE(check_number_19_the_last_number_should_be_19)
{//TODO 0, 1, Example : 18, 19, 20
	std::set<int> reference = { 2, 3, 5, 7, 11, 13, 17, 19 };
	BOOST_CHECK(GeneratePrimeNumbersSet(19) == reference);
}

BOOST_AUTO_TEST_CASE(check_number_20_the_last_number_should_be_19)
{//TODO 0, 1, Example : 18, 19, 20
	std::set<int> reference = { 2, 3, 5, 7, 11, 13, 17, 19 };
	BOOST_CHECK(GeneratePrimeNumbersSet(20) == reference);
}

BOOST_AUTO_TEST_CASE(at_upper_bound_100000000_should_be_able_to_5761455_prime_numbers)
{//TODO 0, 1, Example : 18, 19, 20
	BOOST_CHECK(GeneratePrimeNumbersSet(100000000).size() == 5761455);
}

BOOST_AUTO_TEST_SUITE_END()