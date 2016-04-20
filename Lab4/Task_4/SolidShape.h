#pragma once
#include "Shape.h"

using point = std::pair<float, float>;

class ISolidShape : public IShape
{
public:
	virtual ~ISolidShape() = default;
	virtual std::string GetColor() const = 0;
};