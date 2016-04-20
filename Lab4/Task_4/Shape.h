#pragma once
#include <string>
#include <vector>
#include "Config.h"
#include <memory>

using point = std::pair<float, float>;

class IShape
{
public:
	virtual ~IShape() = default;
	virtual float GetAreaShape() const = 0;
	virtual float GetPerimeterShape() const = 0;
	virtual std::string GetColorLine() const = 0;
	virtual std::string GetDescription() const = 0;
	virtual std::string GetNameShape() const = 0;
private:
};