#include "stdafx.h"
#include "Rectangle.h"
#include <cmath>

CRectangle::CRectangle(Point const &p1, Point const &p2, Color const &edgeColor, Color const &fillColor) :
	m_firstPoint(p1),
	m_secondPoint(p2),
	m_edgeColor(edgeColor),
	m_fillColor(fillColor)
{}


Point CRectangle::GetFirstPoint() const
{
	return m_firstPoint;
}

Color CRectangle::GetLineColor() const
{
	return m_edgeColor;
}

float CRectangle::GetHeight() const
{
	return abs(m_secondPoint.y - m_firstPoint.y);
}

float CRectangle::GetWidth() const
{
	return abs(m_secondPoint.x - m_firstPoint.x);
}

float CRectangle::GetPerimeter() const
{
	return (static_cast<float>(GetHeight()) + static_cast<float>(GetWidth())) * 2.0f;
}

float CRectangle::GetArea() const
{
	return static_cast<float>(GetHeight()) * static_cast<float>(GetWidth());
}	

Color CRectangle::GetColor() const
{
	return m_fillColor;
}

std::string CRectangle::GetDescription() const
{
	return  "Rectangle <<" + std::to_string(m_firstPoint.x) + ", " + std::to_string(m_firstPoint.y)
		+ "><" + std::to_string(m_secondPoint.x) + ", " + std::to_string(m_secondPoint.y) + 
		">>, S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimeter());
}

std::string CRectangle::GetName() const
{
	return RECTANGLE;
}