#pragma once
#include "Shape.h"
#include "Point.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(std::shared_ptr<CPoint> const &p1, std::shared_ptr<CPoint> const &p2, std::string const &color):
		m_firstPoint(p1),
		m_secondPoint(p2),
		m_color(color)
	{}
	~CLineSegment() = default;
	float GetLengthSegment() const;
	float GetPerimeterShape() const override;
	float GetAreaShape() const override;
	std::string GetColorLine() const override;
	std::string ToString() const override;
private:
	std::shared_ptr<CPoint> m_firstPoint;
	std::shared_ptr<CPoint> m_secondPoint;
	std::string m_color;
};