#pragma once
#include "Shape.h"

class ISolidShape : public IShape
{
public:
	virtual ~ISolidShape() = default;
	virtual Color GetColor() const = 0;
};