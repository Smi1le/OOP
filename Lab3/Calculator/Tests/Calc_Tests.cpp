#include "stdafx.h"
#include "../Calculator/CCalculatorHelper.h"
#include "../Calculator/Calculator.h"

struct CCalcFixture
{
	CCalculator calculator;

	//CFunctions function;
};

BOOST_FIXTURE_TEST_SUITE(Calculator, CCalcFixture)

	BOOST_AUTO_TEST_CASE(the_ability_to_add_any_kind_of_variable)
	{
		BOOST_CHECK(calculator.AddVariable("var1"));
		BOOST_CHECK(calculator.AssignValToVar("var1", 0.5));
	}

	BOOST_AUTO_TEST_CASE(Ad_2_variables_and_their_initialization)
	{
		BOOST_CHECK(calculator.AddVariable("var1"));
		BOOST_CHECK(calculator.AddVariable("var2"));
		BOOST_CHECK(calculator.AssignValToVar("var1", 0.5));
		BOOST_CHECK(calculator.AssignValToVar("var2", "var1"));
	}

	BOOST_AUTO_TEST_CASE(it_is_impossible_to_create_the_same_variable_twice)
	{
		BOOST_CHECK(calculator.AddVariable("var1"));
		BOOST_CHECK(calculator.AddVariable("var2"));
		//ѕроверим что нельз€ добавить уже инициализированную переменную
		BOOST_CHECK(!calculator.AddVariable("var1"));
		BOOST_CHECK(!calculator.AddVariable("var2"));
	}


	BOOST_AUTO_TEST_CASE(it_is_impossible_to_pass_the_value_of_an_uninitialized_variable)
	{
		BOOST_CHECK(calculator.AddVariable("var1"));
		BOOST_CHECK(calculator.AssignValToVar("var1", 0.22f));
		BOOST_CHECK(!calculator.AssignValToVar("var1", "var2"));
	}

	BOOST_AUTO_TEST_CASE(check_the_job_functions)
	{
		BOOST_CHECK(calculator.AddVariable("x"));
		BOOST_CHECK(calculator.AddVariable("y"));
		BOOST_CHECK(calculator.AssignValToVar("x", 32.56));
		BOOST_CHECK(calculator.AssignValToVar("y", 12.6));
		BOOST_CHECK(calculator.AddFunction({ "fn", "XPlusY", "=", "x", "+", "y" }));
		BOOST_CHECK(calculator.AddFunction({ "fn", "XPlusYY", "=", "x", "+", "XPlusY" }));
		BOOST_CHECK_EQUAL(calculator.GetValue("XPlusYY"), 77.72);
	}

	BOOST_AUTO_TEST_CASE(it_is_impossible_to_create_the_function_twice)
	{
		BOOST_CHECK(calculator.AddVariable("x"));
		BOOST_CHECK(calculator.AddVariable("y"));
		BOOST_CHECK(calculator.AddFunction({ "fn", "XPlusY", "=", "x", "+", "y" }));
		BOOST_CHECK(!calculator.AddFunction({ "fn", "XPlusY", "=", "x", "+", "y" }));
	}

	struct _check_input : CCalcFixture
	{
		CCalculatorHelper helper;

		//CFunctions function;
	};

	BOOST_FIXTURE_TEST_SUITE(check_input, _check_input)

		BOOST_AUTO_TEST_CASE(on_input_validation)
		{
			BOOST_CHECK(calculator.IsNumber("0.2232"));
			BOOST_CHECK(!calculator.IsNumber("0.2232aa"));
		}

		BOOST_AUTO_TEST_CASE(operand_is_correct)
		{
			BOOST_CHECK(helper.IsOperation("*"));
			BOOST_CHECK(helper.IsOperation("-"));
			BOOST_CHECK(!helper.IsOperation("0"));
			BOOST_CHECK(!helper.IsOperation("9"));
			BOOST_CHECK(!helper.IsOperation("h"));
			BOOST_CHECK(helper.IsOperation("/"));
			BOOST_CHECK(!helper.IsOperation("+9"));
			BOOST_CHECK(helper.IsOperation("+"));
			BOOST_CHECK(!helper.IsOperation("4-/"));
		}
	BOOST_AUTO_TEST_SUITE_END()

	struct _calculator_ : CCalcFixture
	{
	};

	BOOST_FIXTURE_TEST_SUITE(calc, _calculator_)

		BOOST_AUTO_TEST_CASE(calculation_value_two_variable)
		{
			BOOST_CHECK_EQUAL(calculator.CalcValTwoVar(TypeOperand::multiplication, 1.0, 3.5 ), 3.5);
			BOOST_CHECK_EQUAL(calculator.CalcValTwoVar(TypeOperand::addition, 1.0, 3.5), 4.5);
			BOOST_CHECK_EQUAL(calculator.CalcValTwoVar(TypeOperand::division, 3.5, 3.5), 1.0);
			BOOST_CHECK_EQUAL(calculator.CalcValTwoVar(TypeOperand::substraction, 1.0, 3.5), -2.5);
		}

		BOOST_AUTO_TEST_CASE(get_value_function)
		{
			BOOST_CHECK(calculator.AddVariable("x"));
			BOOST_CHECK(calculator.AddVariable("y"));
			BOOST_CHECK(calculator.AssignValToVar("x", 32.56));
			BOOST_CHECK(calculator.AssignValToVar("y", 12.6));
			BOOST_CHECK(calculator.AddFunction({ "fn", "XPlusY", "=", "x", "+", "y" }));
			BOOST_CHECK(calculator.AddFunction({ "fn", "XPlusYY", "=", "x", "+", "XPlusY" }));
			BOOST_CHECK(calculator.AddFunction({ "fn", "Function2", "=", "XPlusYY", "+", "XPlusY" }));
			BOOST_CHECK_EQUAL(calculator.GetValue("XPlusY"), 45.16); // ѕроваливаетс€ из-за погрешности double'a
			BOOST_CHECK_EQUAL(calculator.GetValue("XPlusYY"), 77.72);
			BOOST_CHECK_EQUAL(calculator.GetValue("Function2"), 122.88);
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()