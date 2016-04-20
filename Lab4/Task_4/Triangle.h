#pragma once
#include "SolidShape.h"
#include "Point.h"

class CTriangle : public ISolidShape
{
public:
	CTriangle(std::shared_ptr<CPoint> const &p1, std::shared_ptr<CPoint> const &p2, std::shared_ptr<CPoint> const &p3, std::string const &edgeColor, std::string const &fillColor)
		: m_firstPoint(p1)
		, m_secondPoint(p2)
		, m_thirdPoint(p3)
		, m_edgeColor(edgeColor)
		, m_fillColor(fillColor)
	{}
	std::string GetColorLine() const override;
	std::string GetDescription()const override;
	std::string GetColor() const override;
	std::string GetNameShape() const override;
	float GetPerimeterShape() const override;
	float GetAreaShape() const override;
	
	CPoint GetPoint(int p) const; //¬озможность получить определенную точку 1, 2 или 3-ю
	~CTriangle() = default;
private:
	float GetFirstSideLength() const;
	float GetSecondSideLength() const;
	float GetThirdSideLength() const;
	std::shared_ptr<CPoint> m_firstPoint;
	std::shared_ptr<CPoint> m_secondPoint;
	std::shared_ptr<CPoint> m_thirdPoint;
	std::string m_edgeColor;
	std::string m_fillColor;
};