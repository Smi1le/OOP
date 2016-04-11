#pragma once

#include "Circle.h"
#include "LineSegment.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "SolidShape.h"
#include <memory>

typedef std::vector<std::vector<std::string>> dataShapes;


std::vector<std::shared_ptr<IShape>> GetParamShapes(dataShapes const &elements);
