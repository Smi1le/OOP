#pragma once
#include "SolidShape.h"
#include "Point.h"

class CCircle : public ISolidShape
{
public:
	//move to cpp
	CCircle(Point const &p1, float radius, Color const &edgeColor, Color const &fillColor);
	Color GetLineColor() const override;
	std::string GetDescription()const override;
	Color GetColor() const override;
	float GetPerimeter() const override;
	float GetRadius() const;
	//CCircle GetCopy() const;

	// GetCenter
	Point GetPointCenter() const;

	std::string GetName() const override;
	//point GetCoordinates();
	float GetArea() const override;
private:
	// m_center
	Point m_pointCenter;
	float m_radius;

	// structs
	Color m_edgeColor;
	Color m_fillColor;
};