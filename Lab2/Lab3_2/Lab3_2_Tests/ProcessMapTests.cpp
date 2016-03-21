#include "stdafx.h"
#include "../Lab3_2/ProcessMap.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(ProcessMap_function)

BOOST_AUTO_TEST_CASE(reading_vocabulary)
{
	map<string, string> dict = ReadDictionaryWithFile("dictionary1.txt");
	std::cout << "dict.empty() = " << dict.empty() << endl;
	BOOST_CHECK(!dict.empty());
}

BOOST_AUTO_TEST_CASE(reading_vocabulary_of_a_non_existent_file)
{
	map<string, string> dict = ReadDictionaryWithFile("dictionary2.txt");
	std::cout << "dict.empty() = " << dict.empty() << endl;
	BOOST_CHECK(dict.empty());
}

BOOST_AUTO_TEST_CASE(check_the_entered_word_on_the_possible_shutdown)
{
	std::string checkString = "";
	BOOST_CHECK(InspectionLine(checkString));
}

BOOST_AUTO_TEST_CASE(check_word_entered_to_shut_down)
{
	std::string checkString = "";
	BOOST_CHECK(!InspectionLine(checkString));
}

BOOST_AUTO_TEST_CASE(value_is_found)
{
	std::map<string, string> dict = { {"cat", "кошка"},
									  {"dog", "собака"} };
	string value;
	BOOST_CHECK(SearchByKeyValues(dict, "cat", value));
}

BOOST_AUTO_TEST_CASE(find_what_you_are_correct_value)
{
	std::map<string, string> dict = { { "cat", "кошка" },
									  { "dog", "собака" } };
	string value;
	SearchByKeyValues(dict, "cat", value);
	BOOST_CHECK(value == "кошка");
}

BOOST_AUTO_TEST_SUITE_END()