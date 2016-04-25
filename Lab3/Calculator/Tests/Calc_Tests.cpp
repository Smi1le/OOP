#include "stdafx.h"
#include "../Calculator/CCalculatorHelper.h"
#include "../Calculator/Node.h"
#include "../Calculator/CalculateData.h"

struct CCalcFixture
{
	CNode node;

	//CFunctions function;
};

BOOST_FIXTURE_TEST_SUITE(Calculator, CCalcFixture)

	BOOST_AUTO_TEST_CASE(the_ability_to_add_any_kind_of_variable)
	{
		BOOST_CHECK(node.AddVariable("var1"));
		BOOST_CHECK(node.AssValToVar("var1", 0.5f));
	}

	BOOST_AUTO_TEST_CASE(Ad_2_variables_and_their_initialization)
	{
		BOOST_CHECK(node.AddVariable("var1"));
		BOOST_CHECK(node.AddVariable("var2"));
		BOOST_CHECK(node.AssValToVar("var1", 0.5f));
		BOOST_CHECK(node.AssValToVar("var2", "var1"));
	}

	BOOST_AUTO_TEST_CASE(it_is_impossible_to_create_the_same_variable_twice)
	{
		BOOST_CHECK(node.AddVariable("var1"));
		BOOST_CHECK(node.AddVariable("var2"));
		//�������� ��� ������ �������� ��� ������������������ ����������
		BOOST_CHECK(!node.AddVariable("var2"));
	}


	BOOST_AUTO_TEST_CASE(it_is_impossible_to_pass_the_value_of_an_uninitialized_variable)
	{
		BOOST_CHECK(node.AddVariable("var1"));
		BOOST_CHECK(node.AssValToVar("var1", 0.22f));
		BOOST_CHECK(!node.AssValToVar("var1", "var2"));
	}

	BOOST_AUTO_TEST_CASE(check_the_job_functions)
	{
		BOOST_CHECK(node.AddVariable("x"));
		BOOST_CHECK(node.AddVariable("y"));
		BOOST_CHECK(node.AssValToVar("x", 32.56f));
		BOOST_CHECK(node.AssValToVar("y", 12.6f));
		BOOST_CHECK(node.AddFunction({ "fn", "XPlusY", "=", "x", "+", "y" }));
		BOOST_CHECK(node.AddFunction({ "fn", "XPlusYY", "=", "x", "+", "XPlusY" }));
		BOOST_CHECK_EQUAL(node.GetValue("XPlusYY"), 77.72f);
	}

	BOOST_AUTO_TEST_CASE(it_is_impossible_to_create_the_function_twice)
	{
		BOOST_CHECK(node.AddVariable("x"));
		BOOST_CHECK(node.AddVariable("y"));
		BOOST_CHECK(node.AddFunction({ "fn", "XPlusY", "=", "x", "+", "y" }));
		BOOST_CHECK(!node.AddFunction({ "fn", "XPlusY", "=", "x", "+", "y" }));
	}



	struct _check_input : CCalcFixture
	{
		CCalculatorHelper helper;

		//CFunctions function;
	};

	BOOST_FIXTURE_TEST_SUITE(check_input, _check_input)

		BOOST_AUTO_TEST_CASE(on_input_validation)
		{
			BOOST_CHECK(helper.IsNumber("0.2232"));
			BOOST_CHECK(!helper.IsNumber("0.2232aa"));
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
		CCalculateData calculator;
	};

	BOOST_FIXTURE_TEST_SUITE(calc, _calculator_)

		BOOST_AUTO_TEST_CASE(calculation_value_two_variable)
		{
			BOOST_CHECK(node.AddVariable("x"));
			BOOST_CHECK(node.AddVariable("y"));
			BOOST_CHECK(node.AssValToVar("x", 32.56f));
			BOOST_CHECK(node.AssValToVar("y", 12.6f));
			BOOST_CHECK_EQUAL(calculator.CalcValTwoVar(TypeOperand::multiplication, 1.0, 3.5 ), 3.5);
			BOOST_CHECK_EQUAL(calculator.CalcValTwoVar(TypeOperand::addition, 1.0, 3.5), 4.5);
			BOOST_CHECK_EQUAL(calculator.CalcValTwoVar(TypeOperand::division, 3.5, 3.5), 1.0);
			BOOST_CHECK_EQUAL(calculator.CalcValTwoVar(TypeOperand::substraction, 1.0, 3.5), -2.5);
		}

		BOOST_AUTO_TEST_CASE(get_value_function)
		{
			BOOST_CHECK(node.AddVariable("x"));
			BOOST_CHECK(node.AddVariable("y"));
			BOOST_CHECK(node.AssValToVar("x", 32.56f));
			BOOST_CHECK(node.AssValToVar("y", 12.6f));
			BOOST_CHECK(node.AddFunction({ "fn", "XPlusY", "=", "x", "+", "y" }));
			BOOST_CHECK(node.AddFunction({ "fn", "XPlusYY", "=", "x", "+", "XPlusY" }));
			BOOST_CHECK_EQUAL(node.GetValue("XPlusY"), 45.16f);
			BOOST_CHECK_EQUAL(node.GetValue("XPlusYY"), 77.72f);
		}

	BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE_END()