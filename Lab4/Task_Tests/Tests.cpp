#include "stdafx.h"
#include "../Task_4/GetDataWithFile.h"
#include "../Task_4/GetParamShapes.h"
#include <iterator>
#include <memory>

bool IsEqual(std::vector<std::vector<std::string>> const &first, std::vector<std::vector<std::string>> const &second)
{
	return first == second;
}

typedef std::vector<std::vector<std::string>> dataShapes;

typedef std::vector<std::shared_ptr<IShape>> Vector;

BOOST_AUTO_TEST_SUITE(checking_of_functions_for_data_entry)

BOOST_AUTO_TEST_CASE(splitting_the_input_file_on_the_line_with_parameters)
{
	dataShapes inst = { { "rectangle", "20", "30", "17", "25", "#ff0000", "#00ff00" },
	{ "circle", "10", "54" },
	{ "triangle", "15", "18", "87", "90", "32", "65", "#ef82h1" } };
	dataShapes result = GetDataWithFile("input.txt");
	BOOST_CHECK(IsEqual(result, inst));
}

BOOST_AUTO_TEST_CASE(create_a_shape_point_and_check_all_its_parameters_to_due_compliance)
{
	dataShapes inst = { { "point", "20.0f", "30.0f" } };
	Vector shape = GetParamShapes(inst);
	BOOST_CHECK(shape[0]->GetAreaShape() == 0.0f);
}

BOOST_AUTO_TEST_SUITE_END()
