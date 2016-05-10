#pragma once
#include "SolidShape.h"
#include "Point.h"

class CTriangle : public ISolidShape
{
public:
	CTriangle(Point const &p1, Point const &p2, Point const &p3, Color const &edgeColor, Color const &fillColor);
	Color GetLineColor() const override;
	std::string GetDescription()const override;
	Color GetColor() const override;
	std::string GetName() const override;
	float GetPerimeter() const override;
	float GetArea() const override;
	
	Point GetPoint(TRIANGLE_POINT p) const; //����������� �������� ������������ ����� 1, 2 ��� 3-�
private:
	float GetFirstSideLength() const;
	float GetSecondSideLength() const;
	float GetThirdSideLength() const;

	//implement to array[] or vector
	Point m_firstPoint;
	Point m_secondPoint;
	Point m_thirdPoint;
	
	
	Color m_edgeColor;
	Color m_fillColor;
};