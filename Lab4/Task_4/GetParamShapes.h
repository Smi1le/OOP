#pragma once

#include "Circle.h"
#include "LineSegment.h"
#include "Point.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <memory>

typedef std::vector<std::vector<std::string>> dataShapes;


std::shared_ptr<IShape> CreateShape(std::vector<std::string> const &element);
bool CreatePoint(std::vector<std::string> const &element, std::shared_ptr<IShape> &shape);
bool CreateLineSegment(std::vector<std::string> const &element, std::shared_ptr<IShape> &shape);
bool CreateRectangle(std::vector<std::string> const &element, std::shared_ptr<IShape> &shape);
bool CreateTriangle(std::vector<std::string> const &element, std::shared_ptr<IShape> &shape);
bool CreateCircle(std::vector<std::string> const &element, std::shared_ptr<IShape> &shape);
bool CreateColor(Color &color, std::string const &colorString);

void SortVectorForArea(std::vector<std::shared_ptr<IShape>> &parameterShapes);
//use std::sort - yes
void SortVectorForPerimeter(std::vector<std::shared_ptr<IShape>> &parameterShapes);
bool CheckVectorForSize(std::vector<std::string> const &element);