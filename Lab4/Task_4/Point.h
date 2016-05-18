#pragma once
#include "Shape.h"

class CPoint final : public IShape
{
public:
	CPoint(Point const &p, Color const &edgeColor);
	Point GetCoordinates() const;
	float GetArea() const override;
	float GetPerimeter() const override;
	Color GetLineColor() const override;
	std::string GetDescription() const override;
	std::string GetName() const override;
private:
	Point m_point;
	Color m_edgeColor;
};