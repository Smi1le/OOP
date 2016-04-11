#include "stdafx.h"
#include "LineSegment.h"
#include <cmath>


float CLineSegment::GetLengthSegment() const
{
	return sqrt(pow(m_firstPoint->GetCoordinates().first - m_secondPoint->GetCoordinates().first, 2) + 
		pow(m_firstPoint->GetCoordinates().second - m_secondPoint->GetCoordinates().second, 2));
}

float CLineSegment::GetPerimeterShape() const
{
	return GetLengthSegment();
}

float CLineSegment::GetAreaShape() const
{
	return float(0);
}

std::string CLineSegment::GetColorLine() const
{
	return "Red";
}

std::string CLineSegment::ToString() const
{
	return "Line Segment <<" + std::to_string(m_firstPoint->GetCoordinates().first) + ", " +
		std::to_string(m_firstPoint->GetCoordinates().second) + ">, <" +
		std::to_string(m_secondPoint->GetCoordinates().first) + ", " +
		std::to_string(m_secondPoint->GetCoordinates().second) + "> " +
		"P = " + std::to_string(this->GetLengthSegment());
}


