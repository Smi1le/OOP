#include "stdafx.h"
#include "..\Lab2_3\ProccesorMap.h"

using namespace std;

// Функция ProcessVector
BOOST_AUTO_TEST_SUITE(ProcessVector_function)

// Создает пустой вектор из пустого вектора
BOOST_AUTO_TEST_CASE(makes_empty_string_from_empty_string)
{
	string emptyString = FindAndReplace("", "cat", "mouse");
	BOOST_CHECK(emptyString.empty());
}

BOOST_AUTO_TEST_CASE(does_not_change_vector_containing_no_positive_numbers)
{
	string subject = "I have a cat and I caught a mouse. And you?";
	string reference = "I have a mouse and I caught a mouse. And you?";
	BOOST_CHECK(FindAndReplace(subject, "cat", "mouse") == reference);
}

// должна добавить это число ко всем элементам вектора
BOOST_AUTO_TEST_CASE(should_add_this_nuds_to_each_element)
{
	string subject = "MAMA";
	string reference = "MAMAMAMA";
	BOOST_CHECK(FindAndReplace(subject, "MA", "MAMA") == reference);
}

BOOST_AUTO_TEST_CASE(should_add_this_numrgr_to_each_element)
{
	string subject = "12312312345";
	string reference = "123true5";
	BOOST_CHECK(FindAndReplace(subject, "1231234", "true") == reference);
}

BOOST_AUTO_TEST_SUITE_END()