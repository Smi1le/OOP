#include "stdafx.h"
#define _USE_MATH_DEFINES

#include "LineSegment.h"
#include <cmath>
#include <iostream>


point CLineSegment::GetPointUpLeftAngle() const
{
	return m_firstPoint->GetCoordinates();
}

float CLineSegment::GetLengthSegment() const
{
	return sqrt(pow(m_firstPoint->GetCoordinates().first - m_secondPoint->GetCoordinates().first, 2) + 
		pow(m_firstPoint->GetCoordinates().second - m_secondPoint->GetCoordinates().second, 2));
}

/*
Нужно вычесть координаты первой точки из координат второй точки
*/

float CLineSegment::GetAngle() const
{

	float X1 = m_secondPoint->GetCoordinates().first - m_firstPoint->GetCoordinates().first;
	float Y1 = m_secondPoint->GetCoordinates().second - m_firstPoint->GetCoordinates().second;




	/*float t1 = m_firstPoint->GetCoordinates().second * m_secondPoint->GetCoordinates().second +
		m_firstPoint->GetCoordinates().first * m_secondPoint->GetCoordinates().first;
	float t2 = sqrt(pow(m_firstPoint->GetCoordinates().second, 2) + pow(m_firstPoint->GetCoordinates().first, 2));
	float t3 = sqrt(pow(m_secondPoint->GetCoordinates().second, 2) + pow(m_secondPoint->GetCoordinates().first, 2));
	float t = t1 / (t2 * t3);*/

	float t1 = X1 * X1 + Y1 * 0.f;
	float t2 = sqrt(pow(X1, 2) + pow(Y1, 2));
	float t3 = sqrt(pow(X1, 2));
	float t = t1 / (t2 * t3);


	std::cout << "m_firstPoint->GetCoordinates().first = " << m_firstPoint->GetCoordinates().first << std::endl;
	std::cout << "m_firstPoint->GetCoordinates().second = " << m_firstPoint->GetCoordinates().second << std::endl;
	std::cout << "m_secondPoint->GetCoordinates().first1 = " << m_secondPoint->GetCoordinates().first << std::endl;
	std::cout << "m_secondPoint->GetCoordinates().second = " << m_secondPoint->GetCoordinates().second << std::endl;
	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;
	std::cout << "t3 = " << t3 << std::endl;
	if (t < -1)
	{
		t = -1;
	}
	else if (t > 1)
	{
		t = 1;
	}
	std::cout << "t = " << t << std::endl;
	return acos(t) * 180.f / M_PI;
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

std::string CLineSegment::GetDescription() const
{
	return "Line Segment <<" + std::to_string(m_firstPoint->GetCoordinates().first) + ", " + std::to_string(m_firstPoint->GetCoordinates().first)
		+ "><" + std::to_string(m_secondPoint->GetCoordinates().first) + ", " + std::to_string(m_secondPoint->GetCoordinates().first) +
		">>, S = " + std::to_string(GetAreaShape()) + ", P = " + std::to_string(GetPerimeterShape());
}

std::string CLineSegment::GetNameShape() const
{
	return "Line segment";
}