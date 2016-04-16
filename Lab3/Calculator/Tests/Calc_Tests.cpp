#include "stdafx.h"
#include "../Calculator/ICalculator.h"
#include "../Calculator/Functions.h"


struct CCalcFixture
{
	CCalculatorHelper func;
	CFunctions function;
};

BOOST_FIXTURE_TEST_SUITE(Calculator, CCalcFixture)

BOOST_AUTO_TEST_CASE(the_ability_to_add_any_kind_of_variable)
{
	BOOST_CHECK(function.AddVariable("var1"));
	BOOST_CHECK(function.AssValToVar("var1", 0.5f));
}

BOOST_AUTO_TEST_CASE(Ad_2_variables_and_their_initialization)
{
	BOOST_CHECK(function.AddVariable("var1"));
	BOOST_CHECK(function.AddVariable("var2"));
	BOOST_CHECK(function.AssValToVar("var1", 0.5f));
	BOOST_CHECK(function.AssValToVar("var2", "var1"));
}

/*BOOST_AUTO_TEST_CASE(it_is_impossible_to_create_the_same_variable_twice)
{
	BOOST_CHECK(func.AddVariable("var1"));
	BOOST_CHECK(func.AddVariable("var2"));
	//Проверим что нельзя добавить уже инициализированную переменную
	BOOST_CHECK(!func.AddVariable("var2"));
}


BOOST_AUTO_TEST_CASE(it_is_impossible_to_pass_the_value_of_an_uninitialized_variable)
{
	BOOST_CHECK(func.AddVariable("var1"));
	BOOST_CHECK(func.AssValToVar("var1", 0.22));
	BOOST_CHECK(!func.AssValToVar("var1", "var2"));
}

BOOST_AUTO_TEST_CASE(check_the_job_functions)
{
	BOOST_CHECK(func.AddVariable("x"));
	BOOST_CHECK(func.AddVariable("y"));
	BOOST_CHECK(func.AssValToVar("x", 32.56f));
	BOOST_CHECK(func.AssValToVar("y", 12.6f));
	BOOST_CHECK(func.AddFunction({ "fn", "XPlusY", "=", "x", "+", "y" }));
	BOOST_CHECK(func.AddFunction({ "fn", "XPlusYY", "=", "x", "+", "XPlusY" }));
	BOOST_CHECK_EQUAL(func.GetValFunc("XPlusYY"), 77.72);
}

BOOST_AUTO_TEST_CASE(it_is_impossible_to_create_the_function_twice)
{
	BOOST_CHECK(func.AddVariable("x"));
	BOOST_CHECK(func.AddVariable("y"));
	BOOST_CHECK(func.AddFunction({ "fn", "XPlusY", "=", "x", "+", "y" }));
	BOOST_CHECK(!func.AddFunction({ "fn", "XPlusY", "=", "x", "+", "y" }));
}

BOOST_AUTO_TEST_CASE(on_input_validation)
{
	BOOST_CHECK(func.IsNumber("0.2232"));
	BOOST_CHECK(!func.IsNumber("0.2232aa"));
}

BOOST_AUTO_TEST_CASE(calculation_value_two_variable)
{
	
	BOOST_CHECK_EQUAL(func.CalcValTwoVar("*", 1.0, 3.5 ), 3.5);
	BOOST_CHECK_EQUAL(func.CalcValTwoVar("+", 1.0, 3.5), 4.5);
	BOOST_CHECK_EQUAL(func.CalcValTwoVar("/", 3.5, 3.5), 1.0);
	BOOST_CHECK_EQUAL(func.CalcValTwoVar("-", 1.0, 3.5), -2.5);
}
*/


BOOST_AUTO_TEST_SUITE_END()