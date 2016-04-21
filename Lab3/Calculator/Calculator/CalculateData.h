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
	CCalculateData(std::shared_ptr<DataProgram> tData);
	boost::optional<double> GetValFunction(std::string const &name);
	double CalcValTwoVar(TypeOperand operation, double firstVal, double secondVal) const;
	bool AbilGetVal(std::string const &var, double &number);// TODO: don't use abil in names
private:
	std::shared_ptr<DataProgram> m_data;
};