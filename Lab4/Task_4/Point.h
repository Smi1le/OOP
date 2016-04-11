#pragma once
#include "Shape.h"

class CPoint : public IShape
{
public:
	CPoint(point const &p) : m_point(p)
	{}
	~CPoint() = default;
	point GetCoordinates() const;
	float GetAreaShape() const override;
	float GetPerimeterShape() const override;
	std::string GetColorLine() const override;
	std::string ToString() const override;
private:
	point m_point;
};