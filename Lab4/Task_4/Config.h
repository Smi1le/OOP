#pragma once
#include <string>


static char const COMMA = ',';
static const std::string POINT = "point";
static const std::string LINE_SEGMENT = "lineSegment";
static const std::string RECTANGLE = "rectangle";
static const std::string TRIANGLE = "triangle";
static const std::string CIRCLE = "circle";
static const std::string SYMBOLS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

struct Point
{
	float x;
	float y;
};