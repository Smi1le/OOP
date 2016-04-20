#include "stdafx.h"
#include "GetParamShapes.h"
#include <iostream>



std::vector<std::shared_ptr<IShape>> GetParamShapes(dataShapes const &elements)
{
	std::vector<std::shared_ptr<IShape>> dataElements;
	for (auto elem : elements)
	{
		std::string name = elem[0];
		if (name == POINT)
		{
			point p;
			p = std::make_pair(static_cast<float>(atof(elem[1].c_str())), static_cast<float>(atof(elem[2].c_str())));
			dataElements.push_back(std::make_shared<CPoint>(p));
		}
		else if (name == LINE_SEGMENT)
		{
			point p1;
			point p2;
			p1 = std::make_pair(static_cast<float>(atoi(elem[1].c_str())), static_cast<float>(atoi(elem[2].c_str())));
			p2 = std::make_pair(static_cast<float>(atoi(elem[3].c_str())), static_cast<float>(atoi(elem[4].c_str())));
			std::string edgeColor = elem[5];
			dataElements.push_back(std::make_shared<CLineSegment>(std::make_shared<CPoint>(p1), std::make_shared<CPoint>(p2), edgeColor));
		}
		else if (name == RECTANGLE)
		{
			if (elem.size() >= 7)
			{
				point p1;
				point p2;
				p1 = std::make_pair(static_cast<float>(atoi(elem[1].c_str())), static_cast<float>(atoi(elem[2].c_str())));
				p2 = std::make_pair(static_cast<float>(atoi(elem[3].c_str())), static_cast<float>(atoi(elem[4].c_str())));
				std::string edgeColor = elem[5];
				std::string fillColor = elem[6];
				dataElements.push_back(std::make_shared<CRectangle>(std::make_shared<CPoint>(p1), std::make_shared<CPoint>(p2), edgeColor, fillColor));
			}
		}
		else if (name == TRIANGLE)
		{
			if (elem.size() >= 9)
			{
				point p1;
				point p2;
				point p3;
				p1 = std::make_pair(static_cast<float>(atoi(elem[1].c_str())), static_cast<float>(atoi(elem[2].c_str())));
				p2 = std::make_pair(static_cast<float>(atoi(elem[3].c_str())), static_cast<float>(atoi(elem[4].c_str())));
				p3 = std::make_pair(static_cast<float>(atoi(elem[5].c_str())), static_cast<float>(atoi(elem[6].c_str())));
				std::string edgeColor = elem[7];
				std::string fillColor = elem[8];
				dataElements.push_back(std::make_shared<CTriangle>(std::make_shared<CPoint>(p1), std::make_shared<CPoint>(p2), std::make_shared<CPoint>(p3), 
					edgeColor, fillColor));
			}
		}
		else if (name == CIRCLE)
		{
			if (elem.size() >= 6)
			{
				point p1;
				p1 = std::make_pair(static_cast<float>(atoi(elem[1].c_str())), static_cast<float>(atoi(elem[2].c_str())));
				float radius = static_cast<float>(atoi(elem[3].c_str()));
				std::string edgeColor = elem[4];
				std::string fillColor = elem[5];
				dataElements.push_back(std::make_shared<CCircle>(std::make_shared<CPoint>(p1), radius, edgeColor, fillColor));
			}
		}
	}
	return dataElements;
}
