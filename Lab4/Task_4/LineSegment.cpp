#include "stdafx.h"
#define _USE_MATH_DEFINES

#include "LineSegment.h"
#include <cmath>
#include <iostream>

static const float G_PI = 3.14159265358979323846f;

CLineSegment::CLineSegment(Point const &p1, Point const &p2, Color const &color) :
	m_firstPoint(p1),
	m_secondPoint(p2),
	m_color(color)
{}

Point CLineSegment::GetFirstPoint() const
{
	return m_firstPoint;
}

float CLineSegment::GetLength() const
{
	return sqrt(pow(m_firstPoint.x - m_secondPoint.x, 2) + 
		pow(m_firstPoint.y - m_secondPoint.y, 2));
}

/*
Нужно вычесть координаты первой точки из координат второй точки
*/

float CLineSegment::GetAngle() const
{
	float X1 = static_cast<float>(m_secondPoint.x - m_firstPoint.x);
	float Y1 = m_secondPoint.y - m_firstPoint.y;

	float t1 = X1 * X1 + Y1 * 0.f;
	float t2 = sqrt(pow(X1, 2) + pow(Y1, 2));
	float t3 = sqrt(pow(X1, 2));
	float t = t1 / (t2 * t3);

	if (t < -1)
	{
		t = -1;
	}
	else if (t > 1)
	{
		t = 1;
	}
	if (m_firstPoint.x > m_secondPoint.x)
	{
		return (-1) * static_cast<float>(asin(t) * 180.f / G_PI);
	}
	return static_cast<float>(asin(t) * 180.f / G_PI);
}

float CLineSegment::GetPerimeter() const
{
	return GetLength();
}

float CLineSegment::GetArea() const
{
	return float(0);
}

Color CLineSegment::GetLineColor() const
{
	return m_color;
}

std::string CLineSegment::GetDescription() const
{
	return "Line Segment <<" + std::to_string(m_firstPoint.x) + ", " + std::to_string(m_firstPoint.y)
		+ "><" + std::to_string(m_secondPoint.x) + ", " + std::to_string(m_secondPoint.y) +
		">>, S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimeter());
}

std::string CLineSegment::GetName() const
{
	return LINE_SEGMENT;
}