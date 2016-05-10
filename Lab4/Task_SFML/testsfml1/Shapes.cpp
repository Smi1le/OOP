#include "Shapes.h"

sf::CircleShape CShapesModel::CreatePoint(std::vector<std::string> const &element)
{
	std::string edgeColor = element[3];
	sf::CircleShape pCircle(5.0f);
	pCircle.setPosition(static_cast<float>(atof(element[1].c_str())), static_cast<float>(atof(element[2].c_str())));
	pCircle.setOutlineColor(sf::Color(0, 0, 0));
	return pCircle;
}

sf::RectangleShape CShapesModel::CreateLineSegment(std::vector<std::string> const &element)
{
	Point p1 = { static_cast<float>(atof(element[1].c_str())), static_cast<float>(atof(element[2].c_str())) };
	Point p2 = { static_cast<float>(atof(element[3].c_str())), static_cast<float>(atof(element[4].c_str())) };
	std::string edgeColor = element[5];
	std::string fillColor = element[6];
	Color colorEdge = Color();
	Color colorFill = Color();
	CLineSegment line = CLineSegment(p1, p2, colorEdge);
	if (CreateColor(colorEdge, edgeColor) && CreateColor(colorFill, fillColor))
	{
		line = CLineSegment(p1, p2, colorEdge);
	}
	sf::RectangleShape pLine(sf::Vector2f(line.GetLength(), 1.0f));
	pLine.setFillColor(sf::Color(line.GetLineColor().red, line.GetLineColor().green,
		line.GetLineColor().blue));
	pLine.setOutlineThickness(1.f);
	pLine.setOutlineColor(sf::Color(colorFill.red, colorFill.green, colorFill.blue));
	pLine.setPosition(line.GetFirstPoint().y, line.GetFirstPoint().x);
	pLine.setRotation(line.GetAngle());
	return pLine;
}

sf::RectangleShape CShapesModel::CreateRectangle(std::vector<std::string> const &element)
{
	Point p1 = { static_cast<float>(atof(element[1].c_str())), static_cast<float>(atof(element[2].c_str())) };
	Point p2 = { static_cast<float>(atof(element[3].c_str())), static_cast<float>(atof(element[4].c_str())) };
	std::string edgeColor = element[5];
	std::string fillColor = element[6];
	Color colorEdge = Color();
	Color colorFill = Color();
	CRectangle rect = CRectangle(p1, p2, colorEdge, colorFill);
	if (CreateColor(colorEdge, edgeColor) && CreateColor(colorFill, fillColor))
	{
		rect = CRectangle(p1, p2, colorEdge, colorFill);
	}
	
	std::cout << rect.GetWidth() << std::endl;
	std::cout << rect.GetHeight() << std::endl;
	sf::RectangleShape pRectangle(sf::Vector2f(rect.GetWidth(), rect.GetHeight()));
	pRectangle.setFillColor(sf::Color(rect.GetColor().red, rect.GetColor().green, rect.GetColor().blue));
	pRectangle.setOutlineColor(sf::Color(rect.GetLineColor().red, rect.GetLineColor().green, rect.GetLineColor().blue));
	pRectangle.setOutlineThickness(3);
	pRectangle.setPosition(sf::Vector2f(rect.GetFirstPoint().x, rect.GetFirstPoint().y));
	return pRectangle;
}

sf::ConvexShape CShapesModel::CreateTriangle(std::vector<std::string> const &element)
{
	Point p1 = { static_cast<float>(atof(element[1].c_str())), static_cast<float>(atof(element[2].c_str())) };
	Point p2 = { static_cast<float>(atof(element[3].c_str())), static_cast<float>(atof(element[4].c_str())) };
	Point p3 = { static_cast<float>(atof(element[5].c_str())), static_cast<float>(atof(element[6].c_str())) };
	std::string edgeColor = element[7];
	std::string fillColor = element[8];
	Color colorEdge = Color();
	Color colorFill = Color();
	CTriangle triangle = CTriangle(p1, p2, p3, colorEdge, colorFill);
	if (CreateColor(colorEdge, edgeColor) && CreateColor(colorFill, fillColor))
	{
		triangle = CTriangle(p1, p2, p3, colorEdge, colorFill);
	}
	sf::ConvexShape pTriangle;
	pTriangle.setPointCount(3);
	pTriangle.setPoint(0, sf::Vector2f(triangle.GetPoint(TRIANGLE_POINT::FIRST).x, triangle.GetPoint(TRIANGLE_POINT::FIRST).y));
	pTriangle.setPoint(1, sf::Vector2f(triangle.GetPoint(TRIANGLE_POINT::SECOND).x, triangle.GetPoint(TRIANGLE_POINT::SECOND).y));
	pTriangle.setPoint(2, sf::Vector2f(triangle.GetPoint(TRIANGLE_POINT::THIRD).x, triangle.GetPoint(TRIANGLE_POINT::THIRD).y));
	pTriangle.setFillColor(sf::Color(88, 96, 32));
	pTriangle.setPosition(sf::Vector2f(sf::Vector2f(triangle.GetPoint(TRIANGLE_POINT::FIRST).x, triangle.GetPoint(TRIANGLE_POINT::FIRST).y)));
	pTriangle.setFillColor(sf::Color(triangle.GetColor().red, triangle.GetColor().green,
		triangle.GetColor().blue));
	pTriangle.setOutlineThickness(3);
	pTriangle.setOutlineColor(sf::Color(triangle.GetLineColor().red, triangle.GetLineColor().green,
		triangle.GetLineColor().blue));
	return pTriangle;
}

sf::CircleShape CShapesModel::CreateCircle(std::vector<std::string> const &element)
{
	Point p1 = { static_cast<float>(atof(element[1].c_str())), static_cast<float>(atof(element[2].c_str())) };
	float radius = static_cast<float>(atoi(element[3].c_str()));
	std::string edgeColor = element[4];
	std::string fillColor = element[5];
	Color colorEdge = Color();
	Color colorFill = Color();
	CCircle circle = CCircle(p1, radius, colorEdge, colorFill);
	if (CreateColor(colorEdge, edgeColor) && CreateColor(colorFill, fillColor))
	{
		circle = CCircle(p1, radius, colorEdge, colorFill);
	}
	sf::CircleShape pCircle(circle.GetRadius());
	pCircle.setPosition(circle.GetPointCenter().x, circle.GetPointCenter().y);
	pCircle.setFillColor(sf::Color(circle.GetColor().red, circle.GetColor().green, circle.GetColor().blue));
	pCircle.setOutlineThickness(2);
	pCircle.setOutlineColor(sf::Color(circle.GetLineColor().red, circle.GetLineColor().green, circle.GetLineColor().blue));
	return pCircle;
}


void CShapesView::DisplayShapes(sf::RenderWindow &window) const
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}

void CShapesController::CreateElements(dataShapes const &parametersShapes)
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(840, 560), "Task 4 SFML", sf::Style::Default, settings);
	for (auto elem : parametersShapes)
	{
		for (auto elem1 : elem)
		{
			std::cout << elem1;
		}
		std::cout << std::endl;
	}
	m_window->clear();
	for (auto element : parametersShapes)
	{
		std::string name = element[0];
		if (name == POINT)
		{
			m_window->draw(m_controller.CreatePoint(element));
		}
		else if (name == LINE_SEGMENT)
		{
			m_window->draw(m_controller.CreateLineSegment(element));
		}
		else if (name == RECTANGLE)
		{
			if (element.size() >= 7)
			{
				m_window->draw(m_controller.CreateRectangle(element));
			}
		}
		else if (name == TRIANGLE)
		{
			if (element.size() >= 9)
			{
				m_window->draw(m_controller.CreateTriangle(element));
			}
		}
		else if (name == CIRCLE)
		{
			if (element.size() >= 6)
			{
				m_window->draw(m_controller.CreateCircle(element));
			}
		}
	}
	m_window->display();
}

void CShapesController::DisplayShapes() const
{
	m_view.DisplayShapes(*m_window);
}