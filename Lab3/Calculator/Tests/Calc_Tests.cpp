#include "stdafx.h"
#include "../Calculator/Functions.h"


struct CCalcFixture
{
	CFunctions func;
};

BOOST_FIXTURE_TEST_SUITE(Calculator, CCalcFixture)

BOOST_AUTO_TEST_CASE(the_ability_to_add_any_kind_of_variable)
{
	BOOST_CHECK(func.AddVariable("var1"));
	BOOST_CHECK(func.AssValToVar("var1", 0.5f));
	BOOST_CHECK_EQUAL(func.GetValue("var1"), 0.5f);
}

BOOST_AUTO_TEST_CASE(Ad_2_variables_and_their_initialization)
{
	BOOST_CHECK(func.AddVariable("var1"));
	BOOST_CHECK(func.AddVariable("var2"));
	//Проверим что нельзя добавить уже инициализированную переменную
	BOOST_CHECK(!func.AddVariable("var2"));
	BOOST_CHECK(func.AssValToVar("var1", 0.5f));
	BOOST_CHECK(func.AssValToVar("var2", "var1"));
	BOOST_CHECK_EQUAL(func.GetValue("var2"), 0.5f);
}

BOOST_AUTO_TEST_CASE(check_the_job_functions)
{
	BOOST_CHECK(func.AddVariable("x"));
	BOOST_CHECK(func.AddVariable("y"));
	BOOST_CHECK(func.AssValToVar("x", 32.56f));
	BOOST_CHECK(func.AssValToVar("y", 12.6f));
	BOOST_CHECK(func.AddFunction({ "fn", "XPlusY", "=", "x", "+", "y" }));
	BOOST_CHECK(func.AddFunction({ "fn", "XPlusYY", "=", "x", "+", "XPlusY" }));
	BOOST_CHECK_EQUAL(func.GetValFunc("XPlusYY"), 77.72f);
}

BOOST_AUTO_TEST_CASE(b_functions)
{
	BOOST_CHECK(func.IsNumber("0.2232"));
	BOOST_CHECK(!func.IsNumber("0.2232aa"));
}


BOOST_AUTO_TEST_SUITE_END()