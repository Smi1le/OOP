#pragma once
#include "SolidShape.h"
#include "Point.h"

class CTriangle final : public ISolidShape
{
public:
	CTriangle(Point const &p1, Point const &p2, Point const &p3, Color const &edgeColor, Color const &fillColor);
	Color GetLineColor() const override;
	std::string GetDescription()const override;
	Color GetColor() const override;
	std::string GetName() const override;
	float GetPerimeter() const override;
	float GetArea() const override;
	
	Point GetPoint(TRIANGLE_POINT p) const; //¬озможность получить определенную точку 1, 2 или 3-ю
private:
	float GetFirstSideLength() const;
	float GetSecondSideLength() const;
	float GetThirdSideLength() const;

	std::vector<Point> m_points;
	
	
	Color m_edgeColor;
	Color m_fillColor;
};