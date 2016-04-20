#include "stdafx.h"
#include "Rectangle.h"
#include <cmath>


point CRectangle::GetPointUpLeftAngle() const
{
	return m_firstPoint->GetCoordinates();
}

std::string CRectangle::GetColorLine() const
{
	return m_edgeColor;
}

float CRectangle::GetHeight() const
{
	return abs(m_secondPoint->GetCoordinates().second - m_firstPoint->GetCoordinates().second);
}

float CRectangle::GetWidth() const
{
	return abs(m_secondPoint->GetCoordinates().first - m_firstPoint->GetCoordinates().first);
}

float CRectangle::GetPerimeterShape() const
{
	return (static_cast<float>(GetHeight()) + static_cast<float>(GetWidth())) * 2.0f;
}

float CRectangle::GetAreaShape() const
{
	return static_cast<float>(GetHeight()) * static_cast<float>(GetWidth());
}	

std::string CRectangle::GetColor() const
{
	return m_fillColor;
}

std::string CRectangle::GetDescription() const
{
	return  "Rectangle <<" + std::to_string(m_firstPoint->GetCoordinates().first) + ", " + std::to_string(m_firstPoint->GetCoordinates().second)
		+ "><" + std::to_string(m_secondPoint->GetCoordinates().first) + ", " + std::to_string(m_secondPoint->GetCoordinates().second) + 
		">>, S = " + std::to_string(GetAreaShape()) + ", P = " + std::to_string(GetPerimeterShape());
}

std::string CRectangle::GetNameShape() const
{
	return "rectangle";
}