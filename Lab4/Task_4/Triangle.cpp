#include "stdafx.h"

#include "Triangle.h"
#include <iostream>

CTriangle::CTriangle(Point const &p1, Point const &p2, Point const &p3, Color const &edgeColor, Color const &fillColor)
	: m_firstPoint(p1)
	, m_secondPoint(p2)
	, m_thirdPoint(p3)
	, m_edgeColor(edgeColor)
	, m_fillColor(fillColor)
{}


Color CTriangle::GetLineColor() const
{
	return m_edgeColor;
}

std::string CTriangle::GetDescription()const
{
	return "Triangle <<" + std::to_string(m_firstPoint.x) + ", " + std::to_string(m_firstPoint.y) +
		"><" + std::to_string(m_secondPoint.x) + ", " + std::to_string(m_secondPoint.y) 
		+ "><" + std::to_string(m_thirdPoint.x) + ", " + std::to_string(m_thirdPoint.y)
		+ ">>, S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimeter());
}

Color CTriangle::GetColor() const
{
	return m_fillColor;
}

float CTriangle::GetPerimeter() const
{
	return GetFirstSideLength() + GetSecondSideLength() + GetThirdSideLength();
}

float CTriangle::GetArea() const
{
	float semiperimeter = GetPerimeter() / 2.0f;
	return sqrt(semiperimeter * (semiperimeter - GetFirstSideLength()) * (semiperimeter - GetSecondSideLength()) *
		(semiperimeter - GetThirdSideLength()));
}

float CTriangle::GetFirstSideLength() const
{
	return static_cast<float>(sqrt(pow(m_firstPoint.x - m_secondPoint.x, 2) +
		pow(m_firstPoint.y - m_secondPoint.y, 2)));
}

float CTriangle::GetSecondSideLength() const
{
	return  static_cast<float>(sqrt(pow(m_firstPoint.x - m_thirdPoint.x, 2) +
		pow(m_firstPoint.y - m_thirdPoint.y, 2)));
}

float CTriangle::GetThirdSideLength() const
{
	return  static_cast<float>(sqrt(pow(m_thirdPoint.x - m_secondPoint.x, 2) +
		pow(m_thirdPoint.y - m_secondPoint.y, 2)));
}

Point CTriangle::GetPoint(TRIANGLE_POINT p) const
{
	if (p == 0)
	{
		return m_firstPoint;
	}
	else if (p == 1)
	{
		return m_secondPoint;
	}
	return m_thirdPoint;
}

std::string CTriangle::GetName() const
{
	return TRIANGLE;
}