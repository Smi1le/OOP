#pragma once
#include "Shape.h"
#include "Point.h"

class CLineSegment final : public IShape
{
public:
	CLineSegment(Point const &p1, Point const &p2, Color const &color);

	//GetLength - yes
	float GetLength() const;

	//rename - yes
	Point GetFirstPoint() const;

	// move method to view - no
	float GetAngle() const;


	float GetPerimeter() const override;
	float GetArea() const override;
	Color GetLineColor() const override;
	std::string GetDescription() const override;
	std::string GetName() const override;
private:
	Point m_firstPoint;
	Point m_secondPoint;
	Color m_color;
};