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
			std::cout << "ssssssssssss" << std::endl;
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

	}
	return dataElements;
}
