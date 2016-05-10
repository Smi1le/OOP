#pragma once
#include <string>
#include <vector>
#include "Config.h"
#include "Color.h"
#include <memory>

enum TRIANGLE_POINT { FIRST = 0, SECOND = 1, THIRD = 2 };

using point = std::pair<float, float>;
// TODO : изменить порядок слов в названиях переменных на правильные - yes
class IShape
{
public:
	virtual ~IShape() = default;
	//rename - yes
	virtual float GetArea() const = 0;

	//rename - yes
	virtual float GetPerimeter() const = 0;

	//string to struct
	virtual Color GetLineColor() const = 0;
	virtual std::string GetDescription() const = 0;
	
	//rename - yes
	virtual std::string GetName() const = 0;
};