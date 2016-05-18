#pragma once
#include <SFML/Graphics.hpp>
#include "../../../Lab4/Task_4/Circle.h"
#include "../../../Lab4/Task_4/Config.h"
#include "../../../Lab4/Task_4/Color.h"
#include "../../../Lab4/Task_4/GetDataWithFile.h"
#include "../../../Lab4/Task_4/GetParamShapes.h"
#include "../../../Lab4/Task_4/LineSegment.h"
#include "../../../Lab4/Task_4/Point.h"
#include "../../../Lab4/Task_4/Rectangle.h"
#include "../../../Lab4/Task_4/Triangle.h"

class CShapesView
{
public:
	void DisplayShapes(sf::RenderWindow &window) const;
	void GetAngle() const;
};

class CTriangleView: public sf::Drawable
{
public:
	//CTriangleView(CTriangle const& model);

protected:
	//void draw(...) override;
};


class CShapesModel
{
public:
	sf::CircleShape CreatePoint(std::vector<std::string> const &element);
	sf::CircleShape CreateCircle(std::vector<std::string> const &element);
	sf::RectangleShape CreateLineSegment(std::vector<std::string> const &element);
	sf::RectangleShape CreateRectangle(std::vector<std::string> const &element);
	sf::ConvexShape CreateTriangle(std::vector<std::string> const &element);
};

class CShapesController
{
public:
	void CreateElements(dataShapes const &parametersShapes);
	void DisplayShapes() const;
private:
	std::shared_ptr<sf::RenderWindow> m_window;
	CShapesModel m_controller;
	CShapesView m_view;
};

