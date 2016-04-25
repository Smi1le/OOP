#include "stdafx.h"
#include "OutputData.h"
#include <iostream>

COutputData::COutputData()
{
	m_calcData = std::make_shared<CCalculateData>();
}

bool COutputData::PrintVariables(DataProgram const &data)
{
	if (data.m_dataVariables.empty())
	{
		return false;
	}
	for (auto elem : data.m_dataVariables)
	{
		std::cout << elem.first << ":" << elem.second << std::endl;
	}
	return true;
}

bool COutputData::PrintFunctions(DataProgram const &data)
{
	if (data.m_dataFunctions.empty())
	{
		return false;
	}
	for (auto elem : data.m_dataFunctions)
	{
		std::cout << elem.first << ":" << m_calcData->GetValFunction(elem.first, data) << std::endl;
	}
	return true;
}

bool COutputData::Print(std::string const &name, DataProgram const &data)
{
	auto outElem = data.m_dataVariables.find(name);
	if (outElem != data.m_dataVariables.end())
	{
		std::cout << outElem->second << std::endl;
		return true;
	}
	else
	{
		auto outElem1 = data.m_dataFunctions.find(name);
		if (outElem1 != data.m_dataFunctions.end())
		{
			std::cout << (*outElem1).first << ":" << m_calcData->GetValFunction((*outElem1).first, data) << std::endl;
			return true;
		}
	}
	return false;
}