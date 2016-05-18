#include "stdafx.h"
#include "GetParamShapes.h"
#include <iostream>

std::shared_ptr<IShape> CreateShape(std::vector<std::string> const &element)
{
	std::string name = element[0];
	std::shared_ptr<IShape> shape;
	if (name == POINT)
	{
		if (CreatePoint(element, shape))
		{
			return shape;
		}
	}
	else if (name == LINE_SEGMENT)
	{
		if (CreateLineSegment(element, shape))
		{
			return shape;
		}
	}
	else if (name == RECTANGLE)
	{
		if (CreateRectangle(element, shape))
		{
			return shape;
		}
	}
	else if (name == TRIANGLE)
	{
		if (CreateTriangle(element, shape))
		{
			return shape;
		}
	}
	else //This Circle!!
	{
		if (CreateCircle(element, shape))
		{
			return shape;
		}
	}
}

bool CreateColor(Color &color, std::string const &colorString)
{
	bool wasError = false;
	int red = IntoDecimalSystem(colorString.substr(1, 2), 16, wasError);
	int green = IntoDecimalSystem(colorString.substr(3, 2), 16, wasError);
	int blue = IntoDecimalSystem(colorString.substr(5, 2), 16, wasError);
	if (!wasError)
	{
		color.red = red;
		color.green = green;
		color.blue = blue;
		return true;
	}
	return false;
}

bool CreatePoint(std::vector<std::string> const &element, std::shared_ptr<IShape> &shape)
{
	Point p = { static_cast<float>(atof(element[1].c_str())), static_cast<float>(atof(element[2].c_str())) };
	Color color = Color();
	std::string edgeColor = element[4];
	if (CreateColor(color, edgeColor))
	{
		shape = std::make_shared<CPoint>(p, color);
		return true;
	}
	return false;
}

bool CreateLineSegment(std::vector<std::string> const &element, std::shared_ptr<IShape> &shape)
{
	Point p1 = { static_cast<float>(atof(element[1].c_str())), static_cast<float>(atof(element[2].c_str())) };
	Point p2 = { static_cast<float>(atof(element[3].c_str())), static_cast<float>(atof(element[4].c_str())) };
	std::string edgeColor = element[5];
	Color color = Color();
	if (CreateColor(color, edgeColor))
	{
		shape = std::make_shared<CLineSegment>(p1, p2, color);
		return true;
	}
	return false;
}

bool CreateRectangle(std::vector<std::string> const &element, std::shared_ptr<IShape> &shape)
{
	Point p1 = { static_cast<float>(atof(element[1].c_str())), static_cast<float>(atof(element[2].c_str())) };
	Point p2 = { static_cast<float>(atof(element[3].c_str())), static_cast<float>(atof(element[4].c_str())) };
	std::string edgeColor = element[5];
	std::string fillColor = element[6];
	Color colorEdge = Color();
	Color colorFill = Color();
	if (CreateColor(colorEdge, edgeColor), CreateColor(colorFill, fillColor))
	{
		shape = std::make_shared<CRectangle>(p1, p2, colorEdge, colorFill);
		return true;
	}
	return false;
}

bool CreateTriangle(std::vector<std::string> const &element, std::shared_ptr<IShape> &shape)
{
	Point p1 = { static_cast<float>(atof(element[1].c_str())), static_cast<float>(atof(element[2].c_str())) };
	Point p2 = { static_cast<float>(atof(element[3].c_str())), static_cast<float>(atof(element[4].c_str())) };
	Point p3 = { static_cast<float>(atof(element[5].c_str())), static_cast<float>(atof(element[6].c_str())) };
	std::string edgeColor = element[7];
	std::string fillColor = element[8];
	Color colorEdge = Color();
	Color colorFill = Color();
	if (CreateColor(colorEdge, edgeColor), CreateColor(colorFill, fillColor))
	{
		shape = std::make_shared<CTriangle>(p1, p2, p3, colorEdge, colorFill);
		return true;
	}
	return false;
}

bool CreateCircle(std::vector<std::string> const &element, std::shared_ptr<IShape> &shape)
{
	Point p1 = { static_cast<float>(atof(element[1].c_str())), static_cast<float>(atof(element[2].c_str())) };
	float radius = static_cast<float>(atof(element[3].c_str()));
	std::string edgeColor = element[4];
	std::string fillColor = element[5];
	Color colorEdge = Color();
	Color colorFill = Color();
	if (CreateColor(colorEdge, edgeColor), CreateColor(colorFill, fillColor))
	{
		shape = std::make_shared<CCircle>(p1, radius, colorEdge, colorFill);
		return true;
	}
	return false;
}

//use std::sort - yes
void SortVectorForArea(std::vector<std::shared_ptr<IShape>> &parameterShapes)
{
	std::sort(parameterShapes.begin(), parameterShapes.end(), [](std::shared_ptr<IShape> l, std::shared_ptr<IShape> r) {
		return l->GetArea() <= r->GetArea();
	});
}

//use std::sort - yes
void SortVectorForPerimeter(std::vector<std::shared_ptr<IShape>> &parameterShapes)
{
	std::sort(parameterShapes.begin(), parameterShapes.end(), [](std::shared_ptr<IShape> l, std::shared_ptr<IShape> r) {
		return l->GetPerimeter() >= r->GetPerimeter();
	});
}

bool CheckVectorForSize(std::vector<std::string> const &element)
{
	if (element.size() > 0)
	{
		std::string name = element[0];
		return ((name == POINT && element.size() == 5) ||
			(name == LINE_SEGMENT && element.size() == 6) ||
			(name == CIRCLE && element.size() == 6) ||
			(name == TRIANGLE && element.size() == 9) ||
			(name == RECTANGLE && element.size() == 7));
	}
	return false;
}