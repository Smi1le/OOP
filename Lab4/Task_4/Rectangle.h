#pragma once
#include "SolidShape.h"
#include "Point.h"
#include <memory>

class CRectangle final : public ISolidShape
{
public:
	//move construction to .cpp - yes
	CRectangle(Point const &p1, Point const &p2, Color const &edgeColor, Color const &fillColor);
	//rename - yes
	Point GetFirstPoint() const;
	Color GetLineColor() const override;
	std::string GetDescription()const override;
	Color GetColor() const override;
	float GetPerimeter() const override;
	float GetArea() const override;
	std::string GetName() const override;
	float GetHeight() const;
	float GetWidth() const;
private:
	Point m_firstPoint;
	Point m_secondPoint;
	Color m_edgeColor;
	Color m_fillColor;
};



