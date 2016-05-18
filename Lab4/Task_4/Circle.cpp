
#include "stdafx.h"
#define _USE_MATH_DEFINES

#include <boost/format.hpp>
#include "Circle.h"
#include <iostream>

#include <math.h>


CCircle::CCircle(Point const &p1, float radius, Color const &edgeColor, Color const &fillColor)
	: m_pointCenter(p1)
	, m_radius(radius)
	, m_edgeColor(edgeColor)
	, m_fillColor(fillColor)
{
	if (radius > 0.f)
	{

	}
}

Color CCircle::GetLineColor() const
{
	return m_edgeColor;
}

std::string CCircle::GetDescription()const
{
	return "Circle <" + std::to_string(m_pointCenter.x) + ", " +
		std::to_string(m_pointCenter.y) + ">, R = " + std::to_string(m_radius) + 
		", S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimeter());
}

Color CCircle::GetColor() const
{
	return m_fillColor;
}

float CCircle::GetPerimeter() const
{
	return std::round(static_cast<float>(2 * M_PI * m_radius) * 100) / 100;
}

float CCircle::GetArea() const
{
	return std::round(static_cast<float>(M_PI * pow(m_radius, 2)) * 100) / 100;
}

float CCircle::GetRadius() const
{
	return std::round(m_radius * 100) / 100;
}

std::string CCircle::GetName() const
{
	return CIRCLE;
}

Point CCircle::GetPointCenter() const
{
	return m_pointCenter;
}