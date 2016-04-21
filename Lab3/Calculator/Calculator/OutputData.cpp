#include "stdafx.h"
#include "OutputData.h"
#include <iostream>

COutputData::COutputData(std::shared_ptr<DataProgram> tData)
{
	m_data = tData;
	m_calcData = std::make_shared<CCalculateData>(m_data);
}

bool COutputData::PrintVariables()
{
	if (m_data->m_dataVariables.empty())
	{
		return false;
	}
	for (auto elem : m_data->m_dataVariables)
	{
		std::cout << elem.first << ":" << elem.second << std::endl;
	}
	return true;
}

bool COutputData::PrintFunctions()
{
	if (m_data->m_dataFunctions.empty())
	{
		return false;
	}
	for (auto elem : m_data->m_dataFunctions)
	{
		std::cout << elem.first << ":" << m_calcData->GetValFunction(elem.first) << std::endl;
	}
	return true;
}

bool COutputData::Print(std::string const &name)
{
	auto outElem = m_data->m_dataVariables.find(name);
	if (outElem != m_data->m_dataVariables.end())
	{
		std::cout << outElem->second << std::endl;
		return true;
	}
	else
	{
		auto outElem1 = m_data->m_dataFunctions.find(name);
		if (outElem1 != m_data->m_dataFunctions.end())
		{
			std::cout << (*outElem1).first << ":" << m_calcData->GetValFunction((*outElem1).first) << std::endl;
			return true;
		}
	}
	return false;
}