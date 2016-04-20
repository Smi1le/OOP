#pragma once
#include "SolidShape.h"
#include "Point.h"

class CCircle : public ISolidShape
{
public:
	CCircle(std::shared_ptr<CPoint> const &p1, float radius, std::string const &edgeColor, std::string const &fillColor)
		: m_pointCenter(p1)
		, m_radius(radius)
		, m_edgeColor(edgeColor)
		, m_fillColor(fillColor)
	{}
	~CCircle() = default;
	std::string GetColorLine() const override;
	std::string GetDescription()const override;
	std::string GetColor() const override;
	float GetPerimeterShape() const override;
	float GetRadius() const;
	//CCircle GetCopy() const;
	CPoint GetPointCenter() const;
	std::string GetNameShape() const override;
	//point GetCoordinates();
	float GetAreaShape() const override;
private:
	std::shared_ptr<CPoint> m_pointCenter;
	float m_radius;
	std::string m_edgeColor;
	std::string m_fillColor;
};