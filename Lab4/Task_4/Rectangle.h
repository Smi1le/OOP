#pragma once
#include "SolidShape.h"
#include "Point.h"
#include <memory>

class CRectangle : public ISolidShape
{
public:
	CRectangle(std::shared_ptr<CPoint> const &p1, std::shared_ptr<CPoint> const &p2, std::string const &edgeColor, std::string const &fillColor):
		m_firstPoint(p1),
		m_secondPoint(p2),
		m_edgeColor(edgeColor),
		m_fillColor(fillColor)
	{
	}
	~CRectangle() = default;
	point GetPointUpLeftAngle() const;
	std::string GetColorLine() const override;
	std::string ToString()const override;
	std::string GetColor() const override;
	float GetPerimeterShape() const override;
	float GetAreaShape() const override;
	float GetHeight() const;
	float GetWidth() const;
private:
	std::shared_ptr<CPoint> m_firstPoint;
	std::shared_ptr<CPoint> m_secondPoint;
	std::string m_edgeColor;
	std::string m_fillColor;
};



