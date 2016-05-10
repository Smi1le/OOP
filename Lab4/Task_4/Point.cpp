#include "stdafx.h"
#include "Point.h"

CPoint::CPoint(Point const &p, Color const &edgeColor)
	: m_point(p)
	, m_edgeColor(edgeColor)
{}

Point CPoint::GetCoordinates() const
{
	return m_point;
}

std::string CPoint::GetDescription() const
{
	return "Point <" + std::to_string(m_point.x) + ", " + std::to_string(m_point.y) + ">";
}

float CPoint::GetArea() const
{
	return float(0);
}

float CPoint::GetPerimeter() const
{
	return float(0);
}

Color CPoint::GetLineColor() const
{
	return m_edgeColor;
}

std::string CPoint::GetName() const
{
	return POINT;
}