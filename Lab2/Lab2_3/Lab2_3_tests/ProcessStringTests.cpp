#include "stdafx.h"
#include "..\Lab2_3\ProcessorString.h"

using namespace std;

// Функция ProcessVector
BOOST_AUTO_TEST_SUITE(ProcessString_function)

// Создает пустой вектор из пустого вектора
BOOST_AUTO_TEST_CASE(makes_empty_string_from_empty_string)
{
	string emptyString = FindAndReplace("", "cat", "mouse");
	BOOST_CHECK(emptyString.empty());
}

BOOST_AUTO_TEST_CASE(regular_replacement_substring)
{
	string subject = "I have a cat and I caught a mouse. And you?";
	string reference = "I have a mouse and I caught a mouse. And you?";
	BOOST_CHECK(FindAndReplace(subject, "cat", "mouse") == reference);
}

BOOST_AUTO_TEST_CASE(getting_out_of_line_MAMA_line_MAMAMAMA_by_replacing_MA_at_MAMA)
{	
	string subject = "MAMA";
	string reference = "MAMAMAMA";
	BOOST_CHECK(FindAndReplace(subject, "MA", "MAMA") == reference);
}

BOOST_AUTO_TEST_CASE(getting_out_of_line_12312312345_line_123true5_by_replacing_1231234_at_true)
{
	string subject = "12312312345";
	string reference = "123true5";
	BOOST_CHECK(FindAndReplace(subject, "1231234", "true") == reference);
}

BOOST_AUTO_TEST_CASE(getting_out_of_line_кот_кот_котline_собака_собака_собака_by_replacing_кот_at_собака)
{
	string subject = "кот кот кот";
	string reference = "собака собака собака";
	BOOST_CHECK(FindAndReplace(subject, "кот", "собака") == reference);
}

BOOST_AUTO_TEST_SUITE_END()