#include "stdafx.h"
#include "Point.h"

point CPoint::GetCoordinates() const
{
	return m_point;
}

std::string CPoint::ToString() const
{
	return "Point <" + std::to_string(m_point.first) + ", " + std::to_string(m_point.second) + ">";
}

float CPoint::GetAreaShape() const
{
	return float(0);
}

float CPoint::GetPerimeterShape() const
{
	return float(0);
}

std::string CPoint::GetColorLine() const
{
	return "Red";
}