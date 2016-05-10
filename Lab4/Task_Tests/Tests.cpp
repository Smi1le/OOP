#include "stdafx.h"
#include "../Task_4/GetDataWithFile.h"
#include "../Task_4/GetParamShapes.h"
#include <iterator>
#include <memory>

bool IsEqual(Point const &c1, Point const &c2)
{
	return (c1.x == c2.x && c1.y == c2.y);
}

bool IsEqual(float const &c1, float const &c2)
{
	return (c1 == c2);
}

bool IsEqual(Color const &c1, Color const &c2)
{
	return (c1.red == c2.red && c1.green == c2.green && c1.blue == c2.blue);
}

bool IsEqual(std::string const &c1, std::string const &c2)
{
	return (c1 == c2);
}

struct point_created_with_the_position_and_color_
{
	point_created_with_the_position_and_color_()
		: p1({ 50.f, 50.f })
		, color({ 87, 65, 12 })
		, point (p1, color)
	{}
	Point p1;
	Color color;
	CPoint point;
};

//проверка того что данные точки выводятся правильные
BOOST_FIXTURE_TEST_SUITE(check_parameters_point, point_created_with_the_position_and_color_)

	BOOST_AUTO_TEST_CASE(coordinates_of_the_right)
	{
		//check coordinates it is { 50.f, 50.f } 
		BOOST_CHECK(IsEqual(point.GetCoordinates(), p1));
		BOOST_CHECK(!IsEqual(point.GetCoordinates(), { 10.f, 54.f }));
		BOOST_CHECK(!IsEqual(point.GetCoordinates(), { 15.6f, 00.f }));
	}

	BOOST_AUTO_TEST_CASE(color_of_the_right)
	{
		BOOST_CHECK(IsEqual(point.GetLineColor(), color));
		BOOST_CHECK(!IsEqual(point.GetLineColor(), { 0, 0, 0 }));
		BOOST_CHECK(!IsEqual(point.GetLineColor(), { 255, 255, 255 }));
	}

	BOOST_AUTO_TEST_CASE(area_equals_0)
	{
		BOOST_CHECK(IsEqual(point.GetArea(), 0.f));
		BOOST_CHECK(!IsEqual(point.GetArea(), 10.f));
		BOOST_CHECK(!IsEqual(point.GetArea(), 312.f));
	}
	BOOST_AUTO_TEST_CASE(perimeter_equals_0)
	{
		//check perimeter it is 0
		BOOST_CHECK(IsEqual(point.GetPerimeter(), 0.f));
		BOOST_CHECK(!IsEqual(point.GetPerimeter(), 10.f));
		BOOST_CHECK(!IsEqual(point.GetPerimeter(), 312.f));
	}
	BOOST_AUTO_TEST_CASE(at_the_point_of_the_right_name)
	{
		//check name
		BOOST_CHECK(IsEqual(point.GetName(), "point"));
		BOOST_CHECK(!IsEqual(point.GetName(), std::string("vinni pux")));
		BOOST_CHECK(!IsEqual(point.GetName(), std::string("peppa")));
	}

BOOST_AUTO_TEST_SUITE_END()



struct that_all_the_data_line_segment_are_correct_for
{
	that_all_the_data_line_segment_are_correct_for()
		: p1({ 50.f, 50.f })
		, p2({ 80.f, 100.f })
		, edgeColor({ 87, 65, 12 })
		, lineSegment(p1, p2, edgeColor)
	{}
	Point p1;
	Point p2;
	Color edgeColor;
	CLineSegment lineSegment;
};




//проверка того что данные точки выводятся правильные
BOOST_FIXTURE_TEST_SUITE(line_segment, that_all_the_data_line_segment_are_correct_for)

	BOOST_AUTO_TEST_CASE(coordinates_of_the_top_right_corner_of_the_right)
	{
		BOOST_CHECK(IsEqual(lineSegment.GetFirstPoint(), p1));
		BOOST_CHECK(!IsEqual(lineSegment.GetFirstPoint(), { 10.f, 54.f }));
		BOOST_CHECK(!IsEqual(lineSegment.GetFirstPoint(), { 15.6f, 00.f }));
	}

	BOOST_AUTO_TEST_CASE(edge_color_of_the_right)
	{
		//check color it is { 87, 65, 12 }
		BOOST_CHECK(IsEqual(lineSegment.GetLineColor(), edgeColor));
		BOOST_CHECK(!IsEqual(lineSegment.GetLineColor(), { 0, 0, 0 }));
		BOOST_CHECK(!IsEqual(lineSegment.GetLineColor(), { 255, 255, 255 }));
	}

	BOOST_AUTO_TEST_CASE(area_equals_0)
	{
		//check area it is 0
		BOOST_CHECK(IsEqual(lineSegment.GetArea(), 0.f));
		BOOST_CHECK(!IsEqual(lineSegment.GetArea(), 10.f));
		BOOST_CHECK(!IsEqual(lineSegment.GetArea(), 312.f));
	}
	BOOST_AUTO_TEST_CASE(check_perimeter)
	{
		//check perimeter it is 0
		std::cout << "lineSegment.GetPerimeter() = " << lineSegment.GetPerimeter() << std::endl;
		BOOST_CHECK(IsEqual(lineSegment.GetPerimeter(), 58.31f)); // Тест не проходит из-за погрешности значения float
		BOOST_CHECK(!IsEqual(lineSegment.GetPerimeter(), 10.f));
		BOOST_CHECK(!IsEqual(lineSegment.GetPerimeter(), 312.f));
	}
	BOOST_AUTO_TEST_CASE(at_the_line_segment_of_the_right_name)
	{
		//check name
		BOOST_CHECK(IsEqual(lineSegment.GetName(), "lineSegment"));
		BOOST_CHECK(!IsEqual(lineSegment.GetName(), std::string("vinni pux")));
		BOOST_CHECK(!IsEqual(lineSegment.GetName(), std::string("peppa")));
	}

BOOST_AUTO_TEST_SUITE_END()

struct that_all_the_data_rectangle_are_correct_for
{
	that_all_the_data_rectangle_are_correct_for()
		: p1({ 50.f, 50.f })
		, p2({ 80.f, 100.f })
		, edgeColor({ 87, 65, 12 })
		, fillColor({98, 00, 24})
		, rect(p1, p2, edgeColor, fillColor)
	{}
	Point p1;
	Point p2;
	Color edgeColor;
	Color fillColor;
	CRectangle rect;
};

//проверка того что данные точки выводятся правильные
BOOST_FIXTURE_TEST_SUITE(rectangle, that_all_the_data_rectangle_are_correct_for)

	BOOST_AUTO_TEST_CASE(coordinates_of_the_top_right_corner_of_the_right)
	{
		BOOST_CHECK(IsEqual(rect.GetFirstPoint(), p1));
		BOOST_CHECK(!IsEqual(rect.GetFirstPoint(), { 10.f, 54.f }));
		BOOST_CHECK(!IsEqual(rect.GetFirstPoint(), { 15.6f, 00.f }));
	}

	BOOST_AUTO_TEST_CASE(edge_color_of_the_right)
	{
		//check color it is { 87, 65, 12 }
		BOOST_CHECK(IsEqual(rect.GetLineColor(), edgeColor));
		BOOST_CHECK(!IsEqual(rect.GetLineColor(), { 0, 0, 0 }));
		BOOST_CHECK(!IsEqual(rect.GetLineColor(), { 255, 255, 255 }));
	}

	BOOST_AUTO_TEST_CASE(fill_color_of_the_right)
	{
		//check color it is { 87, 65, 12 }
		BOOST_CHECK(IsEqual(rect.GetColor(), fillColor));
		BOOST_CHECK(!IsEqual(rect.GetColor(), { 0, 0, 0 }));
		BOOST_CHECK(!IsEqual(rect.GetColor(), { 255, 255, 255 }));
	}

	BOOST_AUTO_TEST_CASE(check_area)
	{
		//check area it is 0
		std::cout << "rect.GetArea() = " << rect.GetArea() << std::endl;
		BOOST_CHECK(IsEqual(rect.GetArea(), 1500.f));
		BOOST_CHECK(!IsEqual(rect.GetArea(), 10.f));
		BOOST_CHECK(!IsEqual(rect.GetArea(), 312.f));
	}
	BOOST_AUTO_TEST_CASE(check_perimeter)
	{
		//check perimeter it is 0
		std::cout << "rect.GetPerimeter() = " << rect.GetPerimeter() << std::endl;
		BOOST_CHECK(IsEqual(rect.GetPerimeter(), 160.f));
		BOOST_CHECK(!IsEqual(rect.GetPerimeter(), 10.f));
		BOOST_CHECK(!IsEqual(rect.GetPerimeter(), 312.f));
	}
	BOOST_AUTO_TEST_CASE(at_the_rectangle_of_the_right_name)
	{
		//check name
		BOOST_CHECK(IsEqual(rect.GetName(), "rectangle"));
		BOOST_CHECK(!IsEqual(rect.GetName(), std::string("vinni pux")));
		BOOST_CHECK(!IsEqual(rect.GetName(), std::string("peppa")));
	}

BOOST_AUTO_TEST_SUITE_END()


struct that_all_the_data_circle_are_correct_for
{
	that_all_the_data_circle_are_correct_for()
		: p1({ 50.f, 50.f })
		, radius(15.f)
		, edgeColor({ 87, 65, 12 })
		, fillColor({ 98, 00, 24 })
		, circle(p1, radius, edgeColor, fillColor)
	{}
	Point p1;
	float radius;
	Color edgeColor;
	Color fillColor;
	CCircle circle;
};

//проверка того что данные точки выводятся правильные
BOOST_FIXTURE_TEST_SUITE(shape_circle, that_all_the_data_circle_are_correct_for)

	BOOST_AUTO_TEST_CASE(coordinates_center_of_the_right)
	{
		BOOST_CHECK(IsEqual(circle.GetPointCenter(), p1));
		BOOST_CHECK(!IsEqual(circle.GetPointCenter(), { 10.f, 54.f }));
		BOOST_CHECK(!IsEqual(circle.GetPointCenter(), { 15.6f, 00.f }));
	}

	BOOST_AUTO_TEST_CASE(edge_color_of_the_right)
	{
		//check color it is { 87, 65, 12 }
		BOOST_CHECK(IsEqual(circle.GetLineColor(), edgeColor));
		BOOST_CHECK(!IsEqual(circle.GetLineColor(), { 0, 0, 0 }));
		BOOST_CHECK(!IsEqual(circle.GetLineColor(), { 255, 255, 255 }));
	}

	BOOST_AUTO_TEST_CASE(fill_color_of_the_right)
	{
		//check color it is { 87, 65, 12 }
		BOOST_CHECK(IsEqual(circle.GetColor(), fillColor));
		BOOST_CHECK(!IsEqual(circle.GetColor(), { 0, 0, 0 }));
		BOOST_CHECK(!IsEqual(circle.GetColor(), { 255, 255, 255 }));
	}

	BOOST_AUTO_TEST_CASE(check_area)
	{
		std::cout << "circle.GetArea() = " << circle.GetArea() << std::endl;
		BOOST_CHECK(IsEqual(circle.GetArea(), 706.86f));
		BOOST_CHECK(!IsEqual(circle.GetArea(), 10.f));
		BOOST_CHECK(!IsEqual(circle.GetArea(), 312.f));
	}
	BOOST_AUTO_TEST_CASE(check_perimeter)
	{
		std::cout << "circle.GetPerimeter() = " << circle.GetPerimeter() << std::endl;
		BOOST_CHECK(IsEqual(circle.GetPerimeter(), 94.25f));
		BOOST_CHECK(!IsEqual(circle.GetPerimeter(), 10.f));
		BOOST_CHECK(!IsEqual(circle.GetPerimeter(), 312.f));
	}
	BOOST_AUTO_TEST_CASE(at_the_circle_of_the_right_name)
	{
		//check name
		BOOST_CHECK(IsEqual(circle.GetName(), "circle"));
		BOOST_CHECK(!IsEqual(circle.GetName(), std::string("vinni pux")));
		BOOST_CHECK(!IsEqual(circle.GetName(), std::string("peppa")));
	}

BOOST_AUTO_TEST_SUITE_END()



struct that_all_the_data_triangle_are_correct_for
{
	that_all_the_data_triangle_are_correct_for()
		: p1({ 50.f, 50.f })
		, p2({100.f, 50.f })
		, p3({100.f, 100.f})
		, edgeColor({ 87, 65, 12 })
		, fillColor({ 98, 00, 24 })
		, triangle(p1, p2, p3, edgeColor, fillColor)
	{}
	Point p1;
	Point p2;
	Point p3;
	Color edgeColor;
	Color fillColor;
	CTriangle triangle;
};

//проверка того что данные точки выводятся правильные
BOOST_FIXTURE_TEST_SUITE(shape_triangle, that_all_the_data_triangle_are_correct_for)

	BOOST_AUTO_TEST_CASE(coordinates_first_point)
	{
		BOOST_CHECK(IsEqual(triangle.GetPoint(TRIANGLE_POINT::FIRST), p1));
		BOOST_CHECK(!IsEqual(triangle.GetPoint(TRIANGLE_POINT::FIRST), { 10.f, 54.f }));
		BOOST_CHECK(!IsEqual(triangle.GetPoint(TRIANGLE_POINT::FIRST), { 15.6f, 00.f }));
	}

	BOOST_AUTO_TEST_CASE(coordinates_second_point)
	{
		BOOST_CHECK(IsEqual(triangle.GetPoint(TRIANGLE_POINT::SECOND), p2));
		BOOST_CHECK(!IsEqual(triangle.GetPoint(TRIANGLE_POINT::SECOND), { 10.f, 54.f }));
		BOOST_CHECK(!IsEqual(triangle.GetPoint(TRIANGLE_POINT::SECOND), { 15.6f, 00.f }));
	}

	BOOST_AUTO_TEST_CASE(coordinates_third_point)
	{
		BOOST_CHECK(IsEqual(triangle.GetPoint(TRIANGLE_POINT::THIRD), p3));
		BOOST_CHECK(!IsEqual(triangle.GetPoint(TRIANGLE_POINT::THIRD), { 10.f, 54.f }));
		BOOST_CHECK(!IsEqual(triangle.GetPoint(TRIANGLE_POINT::THIRD), { 15.6f, 00.f }));
	}

	BOOST_AUTO_TEST_CASE(edge_color_of_the_right)
	{
		BOOST_CHECK(IsEqual(triangle.GetLineColor(), edgeColor));
		BOOST_CHECK(!IsEqual(triangle.GetLineColor(), { 0, 0, 0 }));
		BOOST_CHECK(!IsEqual(triangle.GetLineColor(), { 255, 255, 255 }));
	}

	BOOST_AUTO_TEST_CASE(fill_color_of_the_right)
	{
		BOOST_CHECK(IsEqual(triangle.GetColor(), fillColor));
		BOOST_CHECK(!IsEqual(triangle.GetColor(), { 0, 0, 0 }));
		BOOST_CHECK(!IsEqual(triangle.GetColor(), { 255, 255, 255 }));
	}

	BOOST_AUTO_TEST_CASE(check_area)
	{
		std::cout << "triangle.GetArea() = " << triangle.GetArea() << std::endl;
		BOOST_CHECK(IsEqual(triangle.GetArea(), 1250.f));
		BOOST_CHECK(!IsEqual(triangle.GetArea(), 10.f));
		BOOST_CHECK(!IsEqual(triangle.GetArea(), 312.f));
	}
	BOOST_AUTO_TEST_CASE(check_perimeter)
	{
		std::cout << "triangle.GetPerimeter() = " << triangle.GetPerimeter() << std::endl;
		BOOST_CHECK(IsEqual(triangle.GetPerimeter(), 170.711f)); // Тест не проходит из-за погрешности значения float
		BOOST_CHECK(!IsEqual(triangle.GetPerimeter(), 10.f));
		BOOST_CHECK(!IsEqual(triangle.GetPerimeter(), 312.f));
	}
	BOOST_AUTO_TEST_CASE(at_the_triangle_of_the_right_name)
	{
		//check name
		BOOST_CHECK(IsEqual(triangle.GetName(), "triangle"));
		BOOST_CHECK(!IsEqual(triangle.GetName(), std::string("vinni pux")));
		BOOST_CHECK(!IsEqual(triangle.GetName(), std::string("peppa")));
	}

BOOST_AUTO_TEST_SUITE_END()


struct sort_vector_for_parameters
{
	sort_vector_for_parameters()
	{
		Point p = { 20.f, 20.f };
		Point p2 = { 50.f, 50.f };
		Color edgeColor = { 98, 98, 98 };
		Color fillColor = { 120, 120, 120 };
		shapes.push_back(std::make_shared<CPoint>(p, edgeColor));
		shapes.push_back(std::make_shared<CRectangle>(p, p2, edgeColor, fillColor));
		shapes.push_back(std::make_shared<CCircle>(p, 5.f, edgeColor, fillColor));
	}
	std::vector<std::shared_ptr<IShape>> shapes;
	Point p;
	Point p2;
	Color edgeColor;
	Color fillColor;
};

bool IsEqual(std::vector<std::shared_ptr<IShape>> l, std::vector<std::shared_ptr<IShape>> r)
{
	for (size_t i = 0; i != l.size(); ++i)
	{
		if (l[i]->GetName() != r[i]->GetName())
		{
			return false;
		}
	}
	return true;
}

BOOST_FIXTURE_TEST_SUITE(sort_vector, sort_vector_for_parameters)

	BOOST_AUTO_TEST_CASE(Ascending_Square)
	{
		std::vector<std::shared_ptr<IShape>> referenceShapes;
		referenceShapes.push_back(std::make_shared<CPoint>(p, edgeColor));
		referenceShapes.push_back(std::make_shared<CCircle>(p, 5.f, edgeColor, fillColor));
		referenceShapes.push_back(std::make_shared<CRectangle>(p, p2, edgeColor, fillColor));
		
		SortVectorForArea(shapes);

		BOOST_CHECK(IsEqual(shapes, referenceShapes));
	}

	BOOST_AUTO_TEST_CASE(Perimeter_Descending)
	{
		std::vector<std::shared_ptr<IShape>> referenceShapes;
		referenceShapes.push_back(std::make_shared<CRectangle>(p, p2, edgeColor, fillColor));
		referenceShapes.push_back(std::make_shared<CCircle>(p, 5.f, edgeColor, fillColor));
		referenceShapes.push_back(std::make_shared<CPoint>(p, edgeColor));

		SortVectorForPerimeter(shapes);

		BOOST_CHECK(IsEqual(shapes, referenceShapes));
	}

BOOST_AUTO_TEST_SUITE_END()