#include "stdafx.h"
#include "../Lab4_4/ProcessSet.h"

// Функция ProcessVector
BOOST_AUTO_TEST_SUITE(ProcessSet_function)

// Создает пустой вектор из пустого вектора
BOOST_AUTO_TEST_CASE(we_pass_one_get_one)
{
	std::set<int> unit = { 1 };
	std::set<int> kdsj = GeneratePrimeNumbersSet(1);
	std::copy(kdsj.begin(), kdsj.end(), std::ostream_iterator<int>(std::cout, " "));
	BOOST_CHECK(kdsj == unit);
}

BOOST_AUTO_TEST_CASE(screening_of_ten_numbers)
{
	std::set<int> unit = { 1, 2, 3, 5, 7 };
	BOOST_CHECK(GeneratePrimeNumbersSet(10) == unit);
}

BOOST_AUTO_TEST_CASE(to_fifty_numbers_of_check)
{
	std::set<int> unit = { 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
	BOOST_CHECK(GeneratePrimeNumbersSet(50) == unit);
}

BOOST_AUTO_TEST_CASE(at_one_hundred_numbers_of_check)
{
	std::set<int> unit = { 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
	BOOST_CHECK(GeneratePrimeNumbersSet(100) == unit);
}

BOOST_AUTO_TEST_SUITE_END()