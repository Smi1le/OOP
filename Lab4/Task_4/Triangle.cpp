#include "stdafx.h"

#include "Triangle.h"
#include <iostream>

CTriangle::CTriangle(Point const &p1, Point const &p2, Point const &p3, Color const &edgeColor, Color const &fillColor)
	: m_edgeColor(edgeColor)
	, m_fillColor(fillColor)
{
	m_points.push_back(p1);
	m_points.push_back(p2);
	m_points.push_back(p3);
}


Color CTriangle::GetLineColor() const
{
	return m_edgeColor;
}

std::string CTriangle::GetDescription()const
{
	return "Triangle <<" + std::to_string(m_points[0].x) + ", " + std::to_string((m_points[0].y)) +
		"><" + std::to_string((m_points[1].x)) + ", " + std::to_string((m_points[1].y))
		+ "><" + std::to_string((m_points[2].x)) + ", " + std::to_string((m_points[2].y))
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
	return static_cast<float>(sqrt(pow((m_points[0].x) - (m_points[1].x), 2) +
		pow(m_points[0].y - m_points[1].y, 2)));
}

float CTriangle::GetSecondSideLength() const
{
	return  static_cast<float>(sqrt(pow(m_points[0].x - m_points[2].x, 2) +
		pow(m_points[0].y - m_points[2].y, 2)));
}

float CTriangle::GetThirdSideLength() const
{
	return  static_cast<float>(sqrt(pow(m_points[2].x - m_points[1].x, 2) +
		pow(m_points[2].y - m_points[1].y, 2)));
}

Point CTriangle::GetPoint(TRIANGLE_POINT p) const
{
	if (p == TRIANGLE_POINT::FIRST)
	{
		return m_points[0];
	}
	else if (p == TRIANGLE_POINT::SECOND)
	{
		return m_points[1];
	}
	return m_points[2];
}

std::string CTriangle::GetName() const
{
	return TRIANGLE;
}