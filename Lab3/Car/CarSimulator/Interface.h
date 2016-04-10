#pragma once
#include "CCar.h"

class CInterface
{
public:
	bool SetCommand();
private:
	void Help();
	void Info();
	std::shared_ptr<CCar> m_car = std::make_shared<CCar>();
};