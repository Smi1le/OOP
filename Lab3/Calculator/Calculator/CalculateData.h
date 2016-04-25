#pragma once
#include <map>
#include <vector>
#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>
#include <memory>
#include "DataProgram.h"


class CCalculateData
{
public:
	CCalculateData();
	boost::optional<float> GetValFunction(std::string const &name, DataProgram const &data);
	float CalcValTwoVar(TypeOperand operation, float firstVal, float secondVal) const;
	bool Calculate(std::string const &var, float &number, DataProgram const &data);// TODO: don't use abil in names
};